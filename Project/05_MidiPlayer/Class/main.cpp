#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <iostream>

#include "GUIManager.h"
#include "MidiManager.h"
#include "WidgetsContainer.h"

#ifdef WIN32
#pragma comment(lib, "guichan.lib")
#endif

WidgetsContainer* pWidgetsContainer;

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
	MidiManager* pMidiManager = new MidiManager();

	if (0 != Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096))
		return 0;
	
	if(false == pGUIManager->InitSystem())
	{
		std::cout << "GUIManager::InitSystem Error: " << std::endl;
		return 0;
	}

	pWidgetsContainer = new WidgetsContainer(pGUIManager);
	
	if (false == pWidgetsContainer->BuildWidgets())
	{
		std::cout << "GUIManager::BuildWidget Error: " << std::endl;
		return 0;
	}

	bool running = true;
	Uint32 start = SDL_GetTicks();

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

		Uint32 currentTime = SDL_GetTicks();
		Uint32 diff = currentTime - start;

		/*if (diff > 1000)
		{
			start = currentTime;
			pWidgetsContainer->UpdateSlider();

			pWidgetsContainer->AutoPlay();
		}*/

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

