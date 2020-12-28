#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>

#include "GUIManager.h"
#include "WidgetsContainer.h"

#ifdef WIN32
#pragma comment(lib, "guichan.lib")
#endif

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Window *pWindow;
	SDL_Renderer *pRenderer;
#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &pWindow, &pRenderer) < 0)
#else
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &pWindow, &pRenderer) < 0)
#endif
	{
		std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	GUIManager* pGUIManager = new GUIManager(pWindow, pRenderer);
	
	if(false == pGUIManager->InitSystem())
	{
		std::cout << "GUIManager::InitSystem Error: " << std::endl;
		return 0;
	}

	WidgetsContainer* pWidgetsContainer = new WidgetsContainer(pGUIManager);
	
	if (false == pWidgetsContainer->BuildWidgets())
	{
		std::cout << "GUIManager::BuildWidget Error: " << std::endl;
		return 0;
	}

	bool running = true;

	while (running)
	{
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
			else if (event.type == SDL_QUIT)
			{
				running = false;
			}

			pGUIManager->PushInput(event);
		}

		pGUIManager->ProcessLogic();
		pGUIManager->ProcessDraw();

		SDL_RenderClear(pRenderer);
		pGUIManager->DoRender();
		SDL_RenderPresent(pRenderer);
	}

	pGUIManager->Finally();

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return 0;
}

