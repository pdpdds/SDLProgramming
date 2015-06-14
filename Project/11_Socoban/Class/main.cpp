#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif
#include "SDL.h"
#include <stdlib.h>
#include <iostream>
#include "SDLSingleton.h"
#include "CGameCore.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")
#endif

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	if (SDLSingleton::GetInstance()->InitSystem() == false)
		exit(0);
	
	CGameCore::GetInstance()->Initialize();

	bool running = true;

	Uint32 frameStart, frameTime;

	while (running)
	{
		frameStart = SDL_GetTicks();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;				
				}				
			}
			else if (event.type == SDL_KEYUP)
			{				
				CGameCore::GetInstance()->ProcessInput(event.key.keysym.scancode);
			}
			
			else if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else if (event.type == SDL_FINGERUP)
			{							
				
				float fingerX = event.tfinger.x;
				float fingerY = event.tfinger.y;

				CGameCore::GetInstance()->ProcessInputWithTouch(fingerX, fingerY);
			}					
		}

		CGameCore::GetInstance()->ProcessGame();

		SDL_RenderClear(SDLSingleton::GetInstance()->GetRenderer());
		CGameCore::GetInstance()->Render();
		SDL_RenderPresent(SDLSingleton::GetInstance()->GetRenderer());

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	

	return 0;
}

