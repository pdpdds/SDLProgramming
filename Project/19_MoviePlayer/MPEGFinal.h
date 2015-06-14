#pragma once

#include "resource.h"

extern "C"
{
	// ffmpeg  
#include "libavcodec/avcodec.h"  
#include "libavformat/avformat.h"  
#include "libswscale/swscale.h"  
#include "libavutil/time.h"  
	// SDL  
#include "SDL.h"  
#include "SDL_thread.h"  
#include <ao/ao.h>
};