/*************************************************************************** 
  alienBlaster 
  Copyright (C) 2004 
  Paul Grathwohl, Arne Hormann, Daniel Kuehn, Soenke Schwardt

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
***************************************************************************/
#include "game.h"
#include "surfaceDB.h"
#include "SDL.h"
#include <stdlib.h>
#ifdef ANDROID
#include <android/log.h>
#endif

using namespace std;

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_image.lib")
#pragma comment(lib, "guichan.lib")
#pragma comment(lib, "IMSLibrary.lib")
#pragma comment(lib, "BaseLib.lib")
#endif

static void appPutToBackground()
{
 // SDL_ANDROID_PauseAudioPlayback();
}
static void appPutToForeground()
{
 // surfaceDB.reloadAllSurfacesToVideoMemory();
 // SDL_ANDROID_ResumeAudioPlayback();
}

#ifndef WIN32
#include <iconv.h>
#else
#include <tchar.h>
#endif

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
 // SDL_ANDROID_SetApplicationPutToBackgroundCallback(&appPutToBackground, &appPutToForeground);
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "main() 0");
  SDL_Init(0);
  srand(0);
 // __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "main() 1");
  Game game;
//  __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "main() 2");
  game.run();
//  __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "main() 3");
  SDL_Quit();
//  __android_log_print(ANDROID_LOG_INFO, "Alien Blaster", "main() 4");
  return 0;
}
