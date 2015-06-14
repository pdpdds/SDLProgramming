// SampleSDLTTF.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <stdlib.h>
#include <iostream>

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "sdl2_TTF.lib")
#endif

bool LoadBufferFromFile(const char* source_file, char** destination, int& length);

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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
	if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &pWindow, &pRenderer) < 0)
#endif
	{
		std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Surface* screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
		0,
		0,
		0,
		0);

	if (screen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Texture* pTexture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		640, 480);

	if (pTexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	if (TTF_Init() == -1) {
		return 0;
	}

	TTF_Font* pTTF_Font = NULL;

	char* pBuffer = NULL;
	int size = 0;
	if (false == LoadBufferFromFile("H2MJRE.TTF", &pBuffer, size))
		return 0;

	SDL_RWops *fp;
	fp = SDL_RWFromMem(pBuffer, size);

	size_t len = SDL_RWseek(fp, 0, SEEK_END);

	SDL_RWseek(fp, 0, SEEK_SET);

	int winWidth, winHeight;
	SDL_GetWindowSize(pWindow, &winWidth, &winHeight);

	
	pTTF_Font = TTF_OpenFontRW(fp, len, 20);
	
	//SDL_RWclose(fp);

	if (pTTF_Font == NULL) {
		return 0;
	}

	SDL_Surface* pTTFSurface = NULL;
	SDL_Color textColor = { 255, 0, 0 }; // 색상을 담기위한 변수

	char* ptextBuffer = NULL;
	
	if (false == LoadBufferFromFile("utf8.txt", &ptextBuffer, size))
		return 0;

	pTTFSurface = TTF_RenderUTF8_Blended(pTTF_Font, ptextBuffer, textColor);

	SDL_Rect dst;
	dst.x = 10;
	dst.y = 10;
	dst.w = 400;
	dst.h = 30;

	if (pTTFSurface)
		SDL_BlitSurface(pTTFSurface, 0, screen, &dst);

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

		SDL_RenderClear(pRenderer);
		SDL_UpdateTexture(pTexture, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(pRenderer, pTexture, NULL, NULL);
		SDL_RenderPresent(pRenderer);
	}

	SDL_FreeSurface(screen);
	SDL_FreeSurface(pTTFSurface);	

	SDL_DestroyTexture(pTexture);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(pTTF_Font);
	delete pBuffer;
	delete ptextBuffer;

	TTF_Quit();

	SDL_Quit();

	return 0;
}

bool LoadBufferFromFile(const char* source_file, char** destination, int& length)
{
	// Open the file
	SDL_RWops *file;
	file = SDL_RWFromFile(source_file, "r");

	if (file == 0)
		return false;

	size_t file_length = SDL_RWseek(file, 0, SEEK_END);
	(*destination) = new char[file_length + 1];
	// Reset seek to beginning of file and read text
	SDL_RWseek(file, 0, SEEK_SET);
	int n_blocks = SDL_RWread(file, (*destination), 1, file_length);
	if (n_blocks <= 0)
	{

	}
	SDL_RWclose(file);

	(*destination)[file_length] = '\0';
	length = file_length;
	return true;
}