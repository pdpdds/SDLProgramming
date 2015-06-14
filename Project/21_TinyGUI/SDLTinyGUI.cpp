// SDLTinyGUI.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
#include "SDL.h"
#ifdef __cplusplus
}
#endif

#include "SDLGui.h"

#pragma comment(lib, "sdl2.lib")
#pragma comment(lib, "sdl2_TTF.lib")
#pragma comment(lib, "SDL2_net.lib")


int _tmain(int argc, _TCHAR* argv[])
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

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	screen = SDL_CreateRGBSurface(0, 640, 480, 32,
		0,
		0,
		0,
		0);

	if (screen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Texture* pGUITexture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		640, 480);

	if (pGUITexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	if(TTF_Init() == -1)
	{
		std::cout << "TTF Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	char text[256] = { 0, };
	GUIListBox serverListBox;
	GUIButton getServers; Uint32 lastRetrieve = 0;
	GUIButton connectToServer; connectToServer.SetDisabled(true);
	GUILabel titleLabel; sprintf(text, "G v%s Protocol version %d", "1.0", "2.0");
	titleLabel.Render(text, 0x0000FFFF, 20);
	GUITextBox customServer; customServer.SetText("localhost:666");
	GUIButton customServerConnect;

	GUILoadFont("font.ttf");

	bool running = true;
	Uint32 start = SDL_GetTicks();

	int screenW = 640;
	int screenH = 480;
	titleLabel.Register();
	titleLabel.SetPos(5, 5, screenW - 5, 25);
	serverListBox.Register();
	serverListBox.SetPos(5, 30, screenW - 5, screenH - 55);
	getServers.Register();
	getServers.SetPos(5, screenH - 50, screenW / 2 - 5, screenH - 30);
	getServers.SetText("Retrieve server list");
	connectToServer.Register();
	connectToServer.SetPos(screenW / 2 + 5, screenH - 50, screenW - 5, screenH - 30);
	connectToServer.SetText("Connect to selected server");
	customServer.Register();
	customServer.SetPos(5, screenH - 25, screenW / 2 - 5, screenH - 5);
	customServerConnect.Register();
	customServerConnect.SetPos(screenW / 2 + 5, screenH - 25, screenW - 5, screenH - 5);
	customServerConnect.SetText("Direct connect");

	for (int i = 0; i < 30; i++)
	{
		serverListBox.AddItem("JHGGHJG");
	}
	

	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (GUIEvent(&event))continue;
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

		Uint32 currentTime = SDL_GetTicks();
		Uint32 diff = currentTime - start;

		
		boxColor(screen,0,0,screen->w,screen->h,0xF0F0F0FF);
		GUIDraw(screen);
		SDL_RenderClear(pRenderer);
		SDL_UpdateTexture(pGUITexture, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(pRenderer, pGUITexture, NULL, NULL);
		SDL_RenderPresent(pRenderer);
	}

	
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return 0;
}

void Popup(const char *text, Uint32 color, Uint32 time){
	SDLTimer timer; SDL_Event SDLEvent;
	bool run = true; Uint16 textLen = strlen(text);
	SDLSetVideo(800, 200, false);
	SDL_ShowCursor(SDL_ENABLE);
	timer.Reset();
	while (run){
		while (SDL_PollEvent(&SDLEvent)){
			switch (SDLEvent.type){
			case SDL_QUIT: run = false; break;
			case SDL_KEYDOWN:
				if (SDLEvent.key.keysym.sym == SDLK_ESCAPE)run = false;
				break;
			}
		}
		timer.Frame(15);
		if (time > 0)if (timer.total > time)run = false;
		boxColor(screen, 0, 0, screen->w, screen->h, 0xF0F0F0FF);
		stringColor(screen, (screen->w / 2) - (textLen * 4), screen->h / 2 - 4, text, color);
		//SDL_Flip(screen);
	}
}