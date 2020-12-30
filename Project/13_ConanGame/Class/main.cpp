// ConanGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SDL2/SDL.h"

#include "Game.h"
#include <iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

#ifdef WIN32
#include <tchar.h>
#endif


#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	Uint32 frameStart, frameTime;

	std::cout << "game init attempt...\n";

#ifndef WIN32 
	if (TheGame::Instance()->init("Conan the Caveman", 0, 0, 0, 0, false))
#else
	if (TheGame::Instance()->init("Conan the Caveman", 100, 100, 640, 480, false))
#endif
	{
		std::cout << "game init success!\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();

	return 0;
}