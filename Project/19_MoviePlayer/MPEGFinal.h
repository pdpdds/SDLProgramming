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
#include "SDL2/SDL.h"  
#include "SDL2/SDL_thread.h"  
#include <ao/ao.h>
};