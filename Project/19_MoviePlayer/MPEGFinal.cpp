// MPEGFinal.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MPEGFinal.h"

#include "GUIWidgets.h"

#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "swscale.lib")
#pragma comment(lib, "avdevice.lib")
#pragma comment(lib, "avfilter.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "swresample.lib")
#pragma comment(lib, "postproc.lib")


#include <combaseapi.h>

#include <stdio.h>
#include <math.h>

#define SDL_AUDIO_BUFFER_SIZE 1024

#define MAX_AUDIOQ_SIZE (5 * 16 * 1024)
#define MAX_VIDEOQ_SIZE (5 * 256 * 1024)

#define AV_SYNC_THRESHOLD 0.01
#define AV_NOSYNC_THRESHOLD 10.0

#define SAMPLE_CORRECTION_PERCENT_MAX 10
#define AUDIO_DIFF_AVG_NB 20

#define VIDEO_PICTURE_QUEUE_SIZE 1
#define AVCODEC_MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32bit audio

#define DEFAULT_AV_SYNC_TYPE AV_SYNC_VIDEO_MASTER

typedef struct PacketQueue {
	AVPacketList *first_pkt, *last_pkt;
	int nb_packets;
	int size;
	SDL_mutex *mutex;
	SDL_cond *cond;
} PacketQueue;


typedef struct VideoPicture {
	AVFrame *bmp;
	int width, height; /* source height & width */
	int allocated;
	double pts;
} VideoPicture;

typedef struct VideoState {

	AVFormatContext *pFormatCtx;
	int             videoStream, audioStream;

	int             av_sync_type;
	double          external_clock; /* external clock base */
	int64_t         external_clock_time;

	double          audio_clock;
	AVStream        *audio_st;
	PacketQueue     audioq;
	uint8_t         audio_buf[(AVCODEC_MAX_AUDIO_FRAME_SIZE * 3) / 2];
	unsigned int    audio_buf_size;
	unsigned int    audio_buf_index;
	AVPacket        audio_pkt;
	AVPacket         *pAudio_pkt;
	int             audio_hw_buf_size;
	double          audio_diff_cum; /* used for AV difference average computation */
	double          audio_diff_avg_coef;
	double          audio_diff_threshold;
	int             audio_diff_avg_count;
	AVFrame*		pFrameYUV;
	double          frame_timer;
	double          frame_last_pts;
	double          frame_last_delay;
	double          video_clock; ///<pts of last decoded frame / predicted pts of next decoded frame
	double          video_current_pts; ///<current displayed pts (different from video_clock if frame fifos are used)
	int64_t         video_current_pts_time;  ///<time (av_gettime) at which we updated video_current_pts - used to have running video pts
	AVStream        *video_st;
	PacketQueue     videoq;
	SwsContext* sws_ctx;

	VideoPicture    pictq[VIDEO_PICTURE_QUEUE_SIZE];
	int             pictq_size, pictq_rindex, pictq_windex;
	SDL_mutex       *pictq_mutex;
	SDL_cond        *pictq_cond;

	SDL_Thread      *parse_tid;
	SDL_Thread      *video_tid;

	char            filename[1024];
	int             quit;
} VideoState;

enum {
	AV_SYNC_AUDIO_MASTER,
	AV_SYNC_VIDEO_MASTER,
	AV_SYNC_EXTERNAL_MASTER,
};

int stream_component_open(VideoState *is, int stream_index);

void packet_queue_flush(PacketQueue *q)
{
	AVPacketList *pkt, *pkt1;

	SDL_LockMutex(q->mutex);
	for (pkt = q->first_pkt; pkt != NULL; pkt = pkt1) {
		pkt1 = pkt->next;
		av_free_packet(&pkt->pkt);
		av_freep(&pkt);
	}
	q->last_pkt = NULL;
	q->first_pkt = NULL;
	q->nb_packets = 0;
	q->size = 0;
	SDL_UnlockMutex(q->mutex);
}


static Uint32 sdl_refresh_timer_cb(Uint32 interval, void *opaque) {
	SDL_Event event;
	event.type = FF_REFRESH_EVENT;
	event.user.data1 = opaque;
	SDL_PushEvent(&event);
	return 0; /* 0 means stop timer */
}

/* schedule a video refresh in 'delay' ms */
static void schedule_refresh(VideoState *is, int delay) {
	SDL_AddTimer(delay, sdl_refresh_timer_cb, is);
}

SDL_Renderer* sdlRenderer;
SDL_Texture* sdlTexture;
static int panelProc(void *arg);
static int SoundProc(void *arg); 


SDL_Window* g_sdlWnd;

/* Since we only have one decoding thread, the Big Struct
can be global in case we need it. */
VideoState *global_video_state;

GUIWidgets* g_pWidgets;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
		
	char	strMultibyte[256] = { 0, };
	int len = WideCharToMultiByte(CP_ACP, 0, lpCmdLine, -1, NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, lpCmdLine, -1, strMultibyte, len, NULL, NULL);

	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	// Register all formats and codecs
	av_register_all();

	VideoState      *is;
	AVFormatContext *pFormatCtx = NULL;

	is = (VideoState*)av_mallocz(sizeof(VideoState));

	strcpy(is->filename, strMultibyte);

	is->pictq_mutex = SDL_CreateMutex();
	is->pictq_cond = SDL_CreateCond();

	schedule_refresh(is, 40);

	int video_index = -1;
	int audio_index = -1;
	int i;

	is->videoStream = -1;
	is->audioStream = -1;

	global_video_state = is;
	// will interrupt blocking functions if we quit!
	//avio_set_interrupt_cb(decode_interrupt_cb);

	// Open video file
	if (avformat_open_input(&pFormatCtx, is->filename, NULL, NULL) != 0)
		return -1; // Couldn't open file

	is->pFormatCtx = pFormatCtx;

	// Retrieve stream information
	if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
		return -1; // Couldn't find stream information

	// Dump information about file onto standard error
	av_dump_format(pFormatCtx, 0, is->filename, 0);

	// Find the first video stream

	for (i = 0; i < pFormatCtx->nb_streams; i++) {
		if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO &&
			video_index < 0) {
			video_index = i;
		}
		if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO &&
			audio_index < 0) {
			audio_index = i;
		}
	}
	if (audio_index >= 0) {
		stream_component_open(is, audio_index);
	}
	if (video_index >= 0) {
		stream_component_open(is, video_index);
	}

	if (is->videoStream < 0 || is->audioStream < 0) {
		fprintf(stderr, "%s: could not open codecs\n", is->filename);
		{
			SDL_Event event;
			event.type = FF_QUIT_EVENT;
			event.user.data1 = is;
			SDL_PushEvent(&event);
			return 0;
		}
	}

	AVFrame* pFrameYUV = av_frame_alloc();;
	AVCodecContext* pCodecCtx = is->pFormatCtx->streams[video_index]->codec;
	//Source color format
	AVPixelFormat src_fix_fmt = pCodecCtx->pix_fmt;	//AV_PIX_FMT_YUV420P
	//Objective color format
	AVPixelFormat dst_fix_fmt = PIX_FMT_BGR24;//PIX_FMT_YUV420P


	is->sws_ctx = sws_getContext(
		pCodecCtx->width,
		pCodecCtx->height,
		pCodecCtx->pix_fmt,
		pCodecCtx->width,
		pCodecCtx->height,
		dst_fix_fmt,//PIX_FMT_BGR24,//PIX_FMT_YUV420P,  
		SWS_BILINEAR,
		NULL,
		NULL,
		NULL);

	int numBytes = avpicture_get_size(
		dst_fix_fmt,//PIX_FMT_YUV420P,  
		pCodecCtx->width,
		pCodecCtx->height);
	uint8_t* buffer = (uint8_t *)av_malloc(numBytes*sizeof(uint8_t));

	avpicture_fill((AVPicture *)pFrameYUV, buffer, dst_fix_fmt,//PIX_FMT_YUV420P,  
		pCodecCtx->width, pCodecCtx->height);

	is->pFrameYUV = pFrameYUV;

	g_pWidgets = new GUIWidgets(pCodecCtx->width, pCodecCtx->height);

	//////////////////////////////////////////////////
	//SDL 초기화
	//////////////////////////////////////////////////
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
		exit(1);
	}

	g_sdlWnd = SDL_CreateWindowFrom(g_pWidgets->m_pPanel->handle());
	SDL_SetWindowTitle(g_sdlWnd, "SDL Window - Set by SDL");
	SDL_Surface* s = SDL_GetWindowSurface(g_sdlWnd);
	SDL_FillRect(s, &s->clip_rect, 0xffffffff);
	SDL_UpdateWindowSurface(g_sdlWnd);



	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
	SDL_EventState(SDL_WINDOWEVENT, SDL_DISABLE);


	sdlRenderer = SDL_CreateRenderer(g_sdlWnd, -1, SDL_RENDERER_TARGETTEXTURE);  //Originally the third parameter is 0
	sdlTexture = SDL_CreateTexture(
		sdlRenderer,
		SDL_PIXELFORMAT_BGR24,//SDL_PIXELFORMAT_YV12,  
		SDL_TEXTUREACCESS_STATIC,//SDL_TEXTUREACCESS_STREAMING,  
		pCodecCtx->width,
		pCodecCtx->height);

	if (!sdlTexture)
		return -1;
	SDL_SetTextureBlendMode(sdlTexture, SDL_BLENDMODE_BLEND);

	g_pWidgets->SetSize(640, 480);

	SDL_CreateThread(panelProc, "Panel Proc", is);

	g_pWidgets->RunMessageLoop();

	delete g_pWidgets;

	CoUninitialize();
}


SDL_Surface     *screen;

void packet_queue_init(PacketQueue *q) {
	memset(q, 0, sizeof(PacketQueue));
	q->mutex = SDL_CreateMutex();
	q->cond = SDL_CreateCond();
}
int packet_queue_put(PacketQueue *q, AVPacket *pkt) {

	AVPacketList *pkt1;
	if (av_dup_packet(pkt) < 0) {
		return -1;
	}
	pkt1 = (AVPacketList*)av_malloc(sizeof(AVPacketList));
	if (!pkt1)
		return -1;
	pkt1->pkt = *pkt;
	pkt1->next = NULL;

	SDL_LockMutex(q->mutex);

	if (!q->last_pkt)
		q->first_pkt = pkt1;
	else
		q->last_pkt->next = pkt1;
	q->last_pkt = pkt1;
	q->nb_packets++;
	q->size += pkt1->pkt.size;
	SDL_CondSignal(q->cond);

	SDL_UnlockMutex(q->mutex);
	return 0;
}
static int packet_queue_get(PacketQueue *q, AVPacket *pkt, int block)
{
	AVPacketList *pkt1;
	int ret;

	SDL_LockMutex(q->mutex);

	for (;;) {

		if (global_video_state->quit) {
			ret = -1;
			break;
		}

		pkt1 = q->first_pkt;
		if (pkt1) {
			q->first_pkt = pkt1->next;
			if (!q->first_pkt)
				q->last_pkt = NULL;
			q->nb_packets--;
			q->size -= pkt1->pkt.size;
			*pkt = pkt1->pkt;
			av_free(pkt1);
			ret = 1;
			break;
		}
		else if (!block) {
			ret = 0;
			break;
		}
		else {
			SDL_CondWait(q->cond, q->mutex);
		}
	}
	SDL_UnlockMutex(q->mutex);
	return ret;
}
double get_audio_clock(VideoState *is) {
	double pts;
	int hw_buf_size, bytes_per_sec, n;

	pts = is->audio_clock; /* maintained in the audio thread */
	hw_buf_size = is->audio_buf_size - is->audio_buf_index;
	bytes_per_sec = 0;
	n = is->audio_st->codec->channels * 2;
	if (is->audio_st) {
		bytes_per_sec = is->audio_st->codec->sample_rate * n;
	}
	if (bytes_per_sec) {
		pts -= (double)hw_buf_size / bytes_per_sec;
	}
	return pts;
}
double get_video_clock(VideoState *is) {
	double delta;

	delta = (av_gettime() - is->video_current_pts_time) / 1000000.0;
	return is->video_current_pts + delta;
}
double get_external_clock(VideoState *is) {
	return av_gettime() / 1000000.0;
}

double get_master_clock(VideoState *is) {
	if (is->av_sync_type == AV_SYNC_VIDEO_MASTER) {
		return get_video_clock(is);
	}
	else if (is->av_sync_type == AV_SYNC_AUDIO_MASTER) {
		return get_audio_clock(is);
	}
	else {
		return get_external_clock(is);
	}
}
/* Add or subtract samples to get a better sync, return new
audio buffer size */
int synchronize_audio(VideoState *is, short *samples,
	int samples_size, double pts) {
	int n;
	double ref_clock;

	n = 2 * is->audio_st->codec->channels;

	if (is->av_sync_type != AV_SYNC_AUDIO_MASTER) {
		double diff, avg_diff;
		int wanted_size, min_size, max_size, nb_samples;

		ref_clock = get_master_clock(is);
		diff = get_audio_clock(is) - ref_clock;

		if (diff < AV_NOSYNC_THRESHOLD) {
			// accumulate the diffs
			is->audio_diff_cum = diff + is->audio_diff_avg_coef
				* is->audio_diff_cum;
			if (is->audio_diff_avg_count < AUDIO_DIFF_AVG_NB) {
				is->audio_diff_avg_count++;
			}
			else {
				avg_diff = is->audio_diff_cum * (1.0 - is->audio_diff_avg_coef);
				if (fabs(avg_diff) >= is->audio_diff_threshold) {
					wanted_size = samples_size + ((int)(diff * is->audio_st->codec->sample_rate) * n);
					min_size = samples_size * ((100 - SAMPLE_CORRECTION_PERCENT_MAX) / 100);
					max_size = samples_size * ((100 + SAMPLE_CORRECTION_PERCENT_MAX) / 100);
					if (wanted_size < min_size) {
						wanted_size = min_size;
					}
					else if (wanted_size > max_size) {
						wanted_size = max_size;
					}
					if (wanted_size < samples_size) {
						/* remove samples */
						samples_size = wanted_size;
					}
					else if (wanted_size > samples_size) {
						uint8_t *samples_end, *q;
						int nb;

						/* add samples by copying final sample*/
						nb = (samples_size - wanted_size);
						samples_end = (uint8_t *)samples + samples_size - n;
						q = samples_end + n;
						while (nb > 0) {
							memcpy(q, samples_end, n);
							q += n;
							nb -= n;
						}
						samples_size = wanted_size;
					}
				}
			}
		}
		else {
			/* difference is TOO big; reset diff stuff */
			is->audio_diff_avg_count = 0;
			is->audio_diff_cum = 0;
		}
	}
	return samples_size;
}

int audio_decode_frame(VideoState *is, uint8_t *audio_buf, int buf_size, double *pts_ptr) {

	int len1, data_size, n;
	AVPacket *pkt = &is->audio_pkt;
	double pts;

	for (;;) {
		while (is->pAudio_pkt && is->pAudio_pkt->size > 0) {
			data_size = buf_size;
			int frameFinished = 0;
			len1 = avcodec_decode_audio4(is->audio_st->codec, (AVFrame *)audio_buf, &frameFinished, is->pAudio_pkt);
			if (len1 < 0) {
				/* if error, skip frame */
				is->pAudio_pkt->size = 0;
				break;
			}
			is->pAudio_pkt->data += len1;
			is->pAudio_pkt->size -= len1;
			if (frameFinished <= 0) {
				/* No data yet, get more frames */
				continue;
			}
			pts = is->audio_clock;
			*pts_ptr = pts;
			n = 2 * is->audio_st->codec->channels;
			is->audio_clock += (double)data_size /
				(double)(n * is->audio_st->codec->sample_rate);

			/* We have data, return it and come back for more later */
			return data_size;
		}
		if (pkt->data)
			av_free_packet(pkt);

		if (is->quit) {
			return -1;
		}
		/* next packet */
		if (packet_queue_get(&is->audioq, pkt, 1) < 0) {
			return -1;
		}
		is->pAudio_pkt = pkt;
		
		/* if update, update the audio clock w/pts */
		if (pkt->pts != AV_NOPTS_VALUE) {
			is->audio_clock = av_q2d(is->audio_st->time_base)*pkt->pts;
		}
	}
}


void audio_callback(void *userdata, Uint8 *stream, int len) {

	VideoState *is = (VideoState *)userdata;
	int len1, audio_size;
	double pts;

	while (len > 0) {
		if (is->audio_buf_index >= is->audio_buf_size) {
			/* We have already sent all our data; get more */
			audio_size = audio_decode_frame(is, is->audio_buf, sizeof(is->audio_buf), &pts);
			if (audio_size < 0) {
				/* If error, output silence */
				is->audio_buf_size = 1024;
				memset(is->audio_buf, 0, is->audio_buf_size);
			}
			else {
				audio_size = synchronize_audio(is, (int16_t *)is->audio_buf,
					audio_size, pts);
				is->audio_buf_size = audio_size;
			}
			is->audio_buf_index = 0;
		}
		len1 = is->audio_buf_size - is->audio_buf_index;
		if (len1 > len)
			len1 = len;
		memcpy(stream, (uint8_t *)is->audio_buf + is->audio_buf_index, len1);
		len -= len1;
		stream += len1;
		is->audio_buf_index += len1;
	}
}


void video_display(VideoState *is) {

	SDL_Rect rect;
	VideoPicture *vp;
	AVPicture pict;
	float aspect_ratio;
	int w, h, x, y;
	int i;

	/*SDL_Rect sdlRect;
	sdlRect.x = 0;
	sdlRect.y = 0;
	sdlRect.w = 640;
	sdlRect.h = 480;*/

	SDL_Rect sdlRect;
	sdlRect.x = 0;
	sdlRect.y = 0;
	sdlRect.w = is->pFormatCtx->streams[is->videoStream]->codec->width;
	sdlRect.h = is->pFormatCtx->streams[is->videoStream]->codec->height;

	vp = &is->pictq[is->pictq_rindex];
	if (vp->bmp) 
	{
		AVCodecContext* pCodecCtx = is->pFormatCtx->streams[is->videoStream]->codec;
		int check = sws_scale(
			is->sws_ctx,
			(uint8_t const * const *)vp->bmp->data,
			vp->bmp->linesize,
			0,
			pCodecCtx->height,
			is->pFrameYUV->data,
			is->pFrameYUV->linesize
			);

		SDL_UpdateTexture(sdlTexture, &sdlRect, is->pFrameYUV->data[0], is->pFrameYUV->linesize[0]);
		SDL_RenderClear(sdlRenderer);
		SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
		SDL_RenderPresent(sdlRenderer);

		av_free(vp->bmp);
	}
}

void video_refresh_timer(void *userdata) {

	VideoState *is = (VideoState *)userdata;
	VideoPicture *vp;
	double actual_delay, delay, sync_threshold, ref_clock, diff;

	if (is->video_st) {
		if (is->pictq_size == 0) {
			schedule_refresh(is, 1);
		}
		else {
			vp = &is->pictq[is->pictq_rindex];

			is->video_current_pts = vp->pts;
			is->video_current_pts_time = av_gettime();

			delay = vp->pts - is->frame_last_pts; /* the pts from last time */
			if (delay <= 0 || delay >= 1.0) {
				/* if incorrect delay, use previous one */
				delay = is->frame_last_delay;
			}
			/* save for next time */
			is->frame_last_delay = delay;
			is->frame_last_pts = vp->pts;

			/* update delay to sync to audio if not master source */
			if (is->av_sync_type != AV_SYNC_VIDEO_MASTER) {
				ref_clock = get_master_clock(is);
				diff = vp->pts - ref_clock;

				/* Skip or repeat the frame. Take delay into account
				FFPlay still doesn't "know if this is the best guess." */
				sync_threshold = (delay > AV_SYNC_THRESHOLD) ? delay : AV_SYNC_THRESHOLD;
				if (fabs(diff) < AV_NOSYNC_THRESHOLD) {
					if (diff <= -sync_threshold) {
						delay = 0;
					}
					else if (diff >= sync_threshold) {
						delay = 2 * delay;
					}
				}
			}

			is->frame_timer += delay;
			/* computer the REAL delay */
			actual_delay = is->frame_timer - (av_gettime() / 1000000.0);
			if (actual_delay < 0.010) {
				/* Really it should skip the picture instead */
				actual_delay = 0.010;
			}
			schedule_refresh(is, (int)(actual_delay * 1000 + 0.5));

			/* show the picture! */
			video_display(is);

			/* update queue for next picture! */
			if (++is->pictq_rindex == VIDEO_PICTURE_QUEUE_SIZE) {
				is->pictq_rindex = 0;
			}
			SDL_LockMutex(is->pictq_mutex);
			is->pictq_size--;
			SDL_CondSignal(is->pictq_cond);
			SDL_UnlockMutex(is->pictq_mutex);
		}
	}
	else {
		schedule_refresh(is, 100);
	}
}

void alloc_picture(void *userdata) {

	VideoState *is = (VideoState *)userdata;
	VideoPicture *vp;

	vp = &is->pictq[is->pictq_windex];
	if (vp->bmp) {
		// we already have one make another, bigger/smaller
		free(vp->bmp);
	}
	// Allocate a place to put our YUV image on that screen
	is->pFrameYUV = av_frame_alloc();
	
	vp->width = is->video_st->codec->width;
	vp->height = is->video_st->codec->height;

	SDL_LockMutex(is->pictq_mutex);
	vp->allocated = 1;
	SDL_CondSignal(is->pictq_cond);
	SDL_UnlockMutex(is->pictq_mutex);

}

int queue_picture(VideoState *is, AVFrame *pFrame, double pts) {

	VideoPicture *vp;
	int dst_pix_fmt;
	AVPicture pict;

	/* wait until we have space for a new pic */
	SDL_LockMutex(is->pictq_mutex);
	while (is->pictq_size >= VIDEO_PICTURE_QUEUE_SIZE &&
		!is->quit) {
		SDL_CondWait(is->pictq_cond, is->pictq_mutex);
	}
	SDL_UnlockMutex(is->pictq_mutex);

	if (is->quit)
		return -1;

	// windex is set to 0 initially
	vp = &is->pictq[is->pictq_windex];

	vp->bmp = pFrame;
	vp->pts = pts;


	/* now we inform our display thread that we have a pic ready */
	if (++is->pictq_windex == VIDEO_PICTURE_QUEUE_SIZE) {
		is->pictq_windex = 0;
	}
	SDL_LockMutex(is->pictq_mutex);
	is->pictq_size++;
	SDL_UnlockMutex(is->pictq_mutex);
	
	return 0;
}

double synchronize_video(VideoState *is, AVFrame *src_frame, double pts) {

	double frame_delay;

	if (pts != 0) {
		/* if we have pts, set video clock to it */
		is->video_clock = pts;
	}
	else {
		/* if we aren't given a pts, set it to the clock */
		pts = is->video_clock;
	}
	/* update the video clock */
	frame_delay = av_q2d(is->video_st->codec->time_base);
	/* if we are repeating a frame, adjust clock accordingly */
	frame_delay += src_frame->repeat_pict * (frame_delay * 0.5);
	is->video_clock += frame_delay;
	return pts;
}

uint64_t global_video_pkt_pts = AV_NOPTS_VALUE;

/* These are called whenever we allocate a frame
* buffer. We use this to store the global_pts in
* a frame at the time it is allocated.
*/
int our_get_buffer(struct AVCodecContext *c, AVFrame *pic, int flag) {
	int ret = avcodec_default_get_buffer(c, pic);
	uint64_t *pts = (uint64_t*)av_malloc(sizeof(uint64_t));
	*pts = global_video_pkt_pts;
	pic->opaque = pts;
	return ret;
}
void our_release_buffer(struct AVCodecContext *c, AVFrame *pic) {
	if (pic) av_freep(&pic->opaque);
	avcodec_default_release_buffer(c, pic);
}

int video_thread(void *arg) {
	VideoState *is = (VideoState *)arg;
	AVPacket pkt1, *packet = &pkt1;
	int len1, frameFinished;
	AVFrame *pFrame;
	double pts;

	for (;;) {
		if (packet_queue_get(&is->videoq, packet, 1) < 0) {
			// means we quit getting packets
			break;
		}
		pts = 0;

		// Save global pts to be stored in pFrame in first call
		global_video_pkt_pts = packet->pts;

		pFrame = avcodec_alloc_frame();
		// Decode video frame
		len1 = avcodec_decode_video2(is->video_st->codec, pFrame, &frameFinished, packet);
		if (packet->dts == AV_NOPTS_VALUE
			&& pFrame->opaque && *(uint64_t*)pFrame->opaque != AV_NOPTS_VALUE) {
			pts = *(uint64_t *)pFrame->opaque;
		}
		else if (packet->dts != AV_NOPTS_VALUE) {
			pts = packet->dts;
		}
		else {
			pts = 0;
		}
		pts *= av_q2d(is->video_st->time_base);

		// Did we get a video frame?
		if (frameFinished) {
			pts = synchronize_video(is, pFrame, pts);
			if (queue_picture(is, pFrame, pts) < 0) {
				break;
			}
		}
		av_free_packet(packet);
	}
	
	return 0;
}

int stream_component_open(VideoState *is, int stream_index) {

	AVFormatContext *pFormatCtx = is->pFormatCtx;
	AVCodecContext *codecCtx;
	AVCodec *codec;
	SDL_AudioSpec wanted_spec, spec;

	if (stream_index < 0 || stream_index >= pFormatCtx->nb_streams) {
		return -1;
	}

	// Get a pointer to the codec context for the video stream
	codecCtx = pFormatCtx->streams[stream_index]->codec;

	if (codecCtx->codec_type == AVMEDIA_TYPE_AUDIO) {
		// Set audio settings from codec info
		/*wanted_spec.freq = codecCtx->sample_rate;
		wanted_spec.format = AUDIO_F32SYS;
		wanted_spec.channels = codecCtx->channels;
		wanted_spec.silence = 0;
		wanted_spec.samples = SDL_AUDIO_BUFFER_SIZE;
		wanted_spec.callback = audio_callback;
		wanted_spec.userdata = is;

		if (SDL_OpenAudio(&wanted_spec, &spec) < 0) {
			fprintf(stderr, "SDL_OpenAudio: %s\n", SDL_GetError());
			return -1;
		}*/
		//is->audio_hw_buf_size = spec.size;
		is->audio_hw_buf_size = 8192;
	}
	codec = avcodec_find_decoder(codecCtx->codec_id);
	if (!codec || (avcodec_open2(codecCtx, codec, NULL) < 0)) {
		fprintf(stderr, "Unsupported codec!\n");
		return -1;
	}

	switch (codecCtx->codec_type) {
	case AVMEDIA_TYPE_AUDIO:
		is->audioStream = stream_index;
		is->audio_st = pFormatCtx->streams[stream_index];
		is->audio_buf_size = 0;
		is->audio_buf_index = 0;

		/* averaging filter for audio sync */
		is->audio_diff_avg_coef = exp(log(0.01 / AUDIO_DIFF_AVG_NB));
		is->audio_diff_avg_count = 0;
		/* Correct audio only if larger error than this */
		is->audio_diff_threshold = 2.0 * SDL_AUDIO_BUFFER_SIZE / codecCtx->sample_rate;

		memset(&is->audio_pkt, 0, sizeof(is->audio_pkt));
		packet_queue_init(&is->audioq);
		//SDL_PauseAudio(0);
		SDL_CreateThread(SoundProc, "Sound Proc", is);
		break;
	case AVMEDIA_TYPE_VIDEO:
		is->videoStream = stream_index;
		is->video_st = pFormatCtx->streams[stream_index];

		is->frame_timer = (double)av_gettime() / 1000000.0;
		is->frame_last_delay = 40e-3;
		is->video_current_pts_time = av_gettime();

		packet_queue_init(&is->videoq);
		is->video_tid = SDL_CreateThread(video_thread, "Video Thread", is);
		codecCtx->get_buffer2 = our_get_buffer;
		codecCtx->release_buffer = our_release_buffer;
		break;
	default:
		break;
	}

	return 0;
}

int decode_interrupt_cb(void) {
	return (global_video_state && global_video_state->quit);
}

int decode_thread(void *arg) {

	VideoState *is = (VideoState *)arg;
	AVPacket pkt1, *packet = &pkt1;

	// main decode loop

	for (;;)
	{
		if (is->quit)
		{
			break;
		}
		// seek stuff goes here
		if (is->audioq.size > MAX_AUDIOQ_SIZE ||
			is->videoq.size > MAX_VIDEOQ_SIZE) {
			SDL_Delay(10);
			continue;
		}
		if (av_read_frame(is->pFormatCtx, packet) < 0)
		{
			//if (url_ferror(&pFormatCtx->pb) == 0) {
			//SDL_Delay(100); /* no error; wait for user input */
			continue;
		}


		// Is this a packet from the video stream?
		if (packet->stream_index == is->videoStream) {
			packet_queue_put(&is->videoq, packet);
		}
		else if (packet->stream_index == is->audioStream) {
			packet_queue_put(&is->audioq, packet);
		}
		else {
			av_free_packet(packet);
		}
	}

	/* all done - wait for it */
	while (!is->quit) {
		SDL_Delay(100);
	}


	{
		SDL_Event event;
		event.type = FF_QUIT_EVENT;
		event.user.data1 = is;
		SDL_PushEvent(&event);
	}
	return 0;
}



static int panelProc(void *arg)
{
	VideoState* is = (VideoState*)(arg);
	SDL_Event       event;

	is->av_sync_type = DEFAULT_AV_SYNC_TYPE;
	is->parse_tid = SDL_CreateThread(decode_thread, "Decode Thread", is);
	if (!is->parse_tid) {
		av_free(is);
		return -1;
	}
	for (;;) {

		SDL_WaitEvent(&event);
		switch (event.type) {
		case FF_QUIT_EVENT:
		case SDL_QUIT:
			is->quit = 1;
			SDL_Quit();
			exit(0);
			break;
		case FF_ALLOC_EVENT:
			alloc_picture(event.user.data1);
			break;
		case FF_REFRESH_EVENT:
			video_refresh_timer(event.user.data1);
			break;
		case FF_SEEK_BAR_EVENT:
		{
								  if (is->pFormatCtx)
								  {
									  int value = g_pWidgets->m_scrollValue;
									  double ratio = (double)value / (double)(60 * 60 * 60);
									  int64_t aa = (int64_t)(ratio * is->pFormatCtx->duration);
									  int DesiredFrameNumber = av_rescale(aa, is->video_st->time_base.den, is->video_st->time_base.num);
									  DesiredFrameNumber /= 1000;
									  //if (avformat_seek_file(pFormatCtx, videoStream, 0, DesiredFrameNumber, DesiredFrameNumber, AVSEEK_FLAG_FRAME) < 0)

									  if (avformat_seek_file(is->pFormatCtx, -1, 0, aa, is->pFormatCtx->duration, 0) >= 0)
									  {
										  packet_queue_flush(&is->videoq);
										  packet_queue_flush(&is->audioq);
									  }
								  }
								  




		}
			break;
			case FF_WINDOW_RESIZE:
			{
								/*	 static int s_w = 0, s_h = 0;
									 int w, h;
									 SDL_GL_GetDrawableSize(g_sdlWnd, &w, &h);

									 if (s_w != w || s_h != h)
									 {
										 s_w = w;
										 s_h = h;

										 SDL_DestroyTexture(sdlTexture);
										 SDL_DestroyRenderer(sdlRenderer);
										 sdlRenderer = SDL_CreateRenderer(g_sdlWnd, -1, SDL_RENDERER_TARGETTEXTURE);  //Originally the third parameter is 0
										 sdlTexture = SDL_CreateTexture(
											 sdlRenderer,
											 SDL_PIXELFORMAT_BGR24,//SDL_PIXELFORMAT_YV12,  
											 SDL_TEXTUREACCESS_STATIC,//SDL_TEXTUREACCESS_STREAMING,  
											 pCodecCtx->width,
											 pCodecCtx->height);
										 if (!sdlTexture)
											 return -1;
										 
			

										 SDL_SetTextureBlendMode(sdlTexture, SDL_BLENDMODE_BLEND);
									 }
									 */



			}
				break;
		default:
			break;
		}
	}
	return 0;
}

static int SoundProc(void *arg)
{
	VideoState* is = (VideoState*)(arg);
	AVCodecContext * aCodecCtx = is->pFormatCtx->streams[is->audioStream]->codec;

	ao_initialize();

	int driver = ao_default_driver_id();

	ao_sample_format sformat;
	AVSampleFormat sfmt = aCodecCtx->sample_fmt;
	if (sfmt == AV_SAMPLE_FMT_U8 || sfmt == AV_SAMPLE_FMT_U8P){
		sformat.bits = 16;
	}
	else if (sfmt == AV_SAMPLE_FMT_S16 || sfmt == AV_SAMPLE_FMT_S16P){
		sformat.bits = 16;
	}
	else if (sfmt == AV_SAMPLE_FMT_S32 || sfmt == AV_SAMPLE_FMT_S32P){
		sformat.bits = 16;
	}
	else if (sfmt == AV_SAMPLE_FMT_FLT || sfmt == AV_SAMPLE_FMT_FLTP) {
		sformat.bits = 16;
	}
	else if (sfmt == AV_SAMPLE_FMT_DBL || sfmt == AV_SAMPLE_FMT_DBLP) {
		sformat.bits = 16;
	}
	else {
		//DBG("Unsupported format");
	}

	sformat.channels = aCodecCtx->channels;
	sformat.rate = aCodecCtx->sample_rate;
	sformat.byte_format = AO_FMT_NATIVE;
	sformat.matrix = 0;

	ao_device *adevice = ao_open_live(driver, &sformat, NULL);

	AVPacket packet;
	AVFrame* pFrame = av_frame_alloc();
	static uint8_t *audio_pkt_data = NULL;
	static int audio_pkt_size = 0;
	int buffer_size = AVCODEC_MAX_AUDIO_FRAME_SIZE + FF_INPUT_BUFFER_PADDING_SIZE;
	int len1, data_size;
	uint8_t *samples = new uint8_t[buffer_size];
	int len;
	int frameFinished = 0;

	int plane_size;


	for (;;) {
		if (packet_queue_get(&is->audioq, &packet, 1) >= 0)
		{
			int frameFinished;
			int len = avcodec_decode_audio4(aCodecCtx, pFrame, &frameFinished, &packet);
			int data_size = av_samples_get_buffer_size(&plane_size, aCodecCtx->channels,
				pFrame->nb_samples,
				aCodecCtx->sample_fmt, 1);
			uint16_t *out = (uint16_t *)samples;

			if (frameFinished){



				int write_p = 0;

				switch (sfmt){

				case AV_SAMPLE_FMT_S16P:
					for (int nb = 0; nb < plane_size / sizeof(uint16_t); nb++){
						for (int ch = 0; ch < aCodecCtx->channels; ch++) {
							out[write_p] = ((uint16_t *)pFrame->extended_data[ch])[nb];
							write_p++;
						}
					}
					ao_play(adevice, (char*)samples, (plane_size)* aCodecCtx->channels);
					break;
				case AV_SAMPLE_FMT_FLTP:
					for (int nb = 0; nb < plane_size / sizeof(float); nb++){
						for (int ch = 0; ch < aCodecCtx->channels; ch++) {
#undef max
							out[write_p] = ((float *)pFrame->extended_data[ch])[nb] * (std::numeric_limits<short>::max()/2);
							write_p++;
						}
					}
					ao_play(adevice, (char*)samples, (plane_size / sizeof(float))  * sizeof(uint16_t)* aCodecCtx->channels);
					break;
				case AV_SAMPLE_FMT_S16:
					ao_play(adevice, (char*)pFrame->extended_data[0], pFrame->linesize[0]);
					break;
				case AV_SAMPLE_FMT_FLT:
					for (int nb = 0; nb < plane_size / sizeof(float); nb++){
						out[nb] = static_cast<short> (((float *)pFrame->extended_data[0])[nb] * std::numeric_limits<short>::max());
					}
					ao_play(adevice, (char*)samples, (plane_size / sizeof(float))  * sizeof(uint16_t));
					break;
				case AV_SAMPLE_FMT_U8P:
					for (int nb = 0; nb < plane_size / sizeof(uint8_t); nb++){
						for (int ch = 0; ch < aCodecCtx->channels; ch++) {
							out[write_p] = (((uint8_t *)pFrame->extended_data[0])[nb] - 127) * std::numeric_limits<short>::max() / 127;
							write_p++;
						}
					}
					ao_play(adevice, (char*)samples, (plane_size / sizeof(uint8_t))  * sizeof(uint16_t)* aCodecCtx->channels);
					break;
				case AV_SAMPLE_FMT_U8:
					for (int nb = 0; nb < plane_size / sizeof(uint8_t); nb++){
						out[nb] = static_cast<short> ((((uint8_t *)pFrame->extended_data[0])[nb] - 127) * std::numeric_limits<short>::max() / 127);
					}
					ao_play(adevice, (char*)samples, (plane_size / sizeof(uint8_t))  * sizeof(uint16_t));
					break;
				default:
					break;
					//DBG("PCM type not supported");
				}
			}
			else {
				//DBG("frame failed");
			}

			if (packet.data)
				av_free_packet(&packet);
		}
	}

	return 0;


}