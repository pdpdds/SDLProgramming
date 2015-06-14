#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif
#include "SDL.h"
#include "SDL_gfxPrimitives.h"

#include <stdlib.h>
#include <iostream>

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "sdl_gfx.lib")
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

	int width, height;
	SDL_GetWindowSize(pWindow, &width, &height);

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	SDL_Surface* screen = SDL_CreateRGBSurface(0, width, height, 32,
		0,
		0,
		0,
		0);

	if (screen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		width, height);

	if (pTexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return false;
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
		}

		SDL_FillRect(screen, NULL, 0x000088);

		circleColor(screen, 50, 50, 20, 0xFFFFFFFF);

		boxRGBA(screen, 10, 10, 50, 50, 100, 100, 100, 255);

		circleRGBA(screen, -100, 100, 200, 100, 100, 100, 255);


		SDL_RenderClear(pRenderer);
		SDL_UpdateTexture(pTexture, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(pRenderer, pTexture, NULL, NULL);
		SDL_RenderPresent(pRenderer);
	}

	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return 0;
}

