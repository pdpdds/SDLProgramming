// SDLGUI.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SDLGUI.h"
#include "SDL.h"
#include <balor/gui/all.hpp>

#ifdef _DEBUG
#pragma comment(lib, "balor_debug.lib")
#else
#pragma comment(lib, "balor.lib")
#endif

#pragma comment(lib, "sdl2.lib")

using namespace balor::gui;
Frame* g_pFrame = NULL;
Panel* g_pPanel = NULL;

static int panelProc(void *arg);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	g_pFrame = new Frame(L"SDL With Windows GUI", 640, 480, Frame::Style::dialog);
	g_pPanel = new Panel(*g_pFrame, 240, 10, 320, 240);

	Button button0(*g_pFrame, 10, 10, 100, 50, L"button0");
	button0.onClick() = [&](Button::Click&) {
		MsgBox::show(L"button0 clicked");
	};

//////////////////////////////////////////////////
//SDL 초기화
//////////////////////////////////////////////////
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) {
		fprintf(stderr, "Could not initialize SDL - %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Window* sdlWnd = SDL_CreateWindowFrom(g_pPanel->handle());
	SDL_SetWindowTitle(sdlWnd, "SDL Window - Set by SDL");
	SDL_Surface* s = SDL_GetWindowSurface(sdlWnd);
	SDL_FillRect(s, &s->clip_rect, 0xffffffff);
	SDL_UpdateWindowSurface(sdlWnd);

	SDL_CreateThread(panelProc, "Panel Proc", sdlWnd);
	g_pFrame->runMessageLoop();

	delete g_pPanel;
	delete g_pFrame;

	return 0; 	
}

static int panelProc(void *arg)
{
	SDL_Window* pWindow = (SDL_Window*)arg;
	int running = 1;
	SDL_Event event;
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
	SDL_EventState(SDL_WINDOWEVENT, SDL_ENABLE);

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			
			case SDL_SYSWMEVENT:
			{
								   SDL_Surface* s = SDL_GetWindowSurface(pWindow);
								   SDL_FillRect(s, &s->clip_rect, 0x000000ff);
								   SDL_UpdateWindowSurface(pWindow);
			}
			break;

			}
		}
		// Doing the rest of my stuff here
	}
	return 0;
}
