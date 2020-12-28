#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <iostream>

#include "GUIManager.h"
#include "WidgetsContainer.h"

#ifdef WIN32
#pragma comment(lib, "guichan.lib")
#pragma comment(lib, "IMSLibrary.lib")
#pragma comment(lib, "BaseLib.lib")
#endif

#ifndef WIN32
#include <iconv.h>
#else
#include <tchar.h>
#endif

#include "IMSLibrary/IMSManager.h"
#include "IMSEventCallback.h"
#include "LyricsManager.h"

IMSManager* g_pManager = 0;

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

	SDL_Surface* lyricsMessageSurface1 = NULL; // 글자를 담기위한 서피스
	SDL_Surface* lyricsMessageSurface2 = NULL; // 글자를 담기위한 서피스
	std::string szLyricsMessage1;
	std::string szLyricsMessage2;

	TTF_Font* font = NULL; // 폰트형을 가져오기 위한 변수

	SDL_Color textColor = { 255, 0, 0 }; // 색상을 담기위한 변수
	SDL_Color textColor2 = { 255, 255, 255 }; // 색상을 담기위한 변수

	g_pManager = new IMSManager();

	if (false == g_pManager->Initialize())
	{
		return 0;
	}

	IMSEventCallback* pEventCallback = new IMSEventCallback();
	g_pManager->SetIMSEventCallback(pEventCallback);

	/*if (TTF_Init() == -1) {
		return 0;
	}

	char* file_contents = NULL;
	int size;
	IMSManager::read_text("H2MJRE.TTF", &file_contents, size);
	SDL_RWops *file;
	file = SDL_RWFromMem(file_contents, size);

	size_t file_length = SDL_RWseek(file, 0, SEEK_END);

	SDL_RWseek(file, 0, SEEK_SET);

	int winWidth, winHeight;
	SDL_GetWindowSize(pWindow, &winWidth, &winHeight);

	if (winWidth >= 640 && winWidth < 800)
		font = TTF_OpenFontRW(file, file_length, 20);
	else if (winWidth >= 800 && winWidth < 1024)
		font = TTF_OpenFontRW(file, file_length, 30);
	else if (winWidth >= 1024)
		font = TTF_OpenFontRW(file, file_length, 40);

	//SDL_RWclose(file);

	if (font == NULL) {
		return 0;
	}

	pWidgetsContainer->SetTrueTypeFont(font);*/

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
			Uint32 currentTime = SDL_GetTicks();
			Uint32 diff = currentTime - start;

			if (diff > 1000)
			{
				start = currentTime;
				pWidgetsContainer->UpdateSlider();
			}
		}

		pGUIManager->ProcessLogic();
		pGUIManager->ProcessDraw();

		if (g_pManager)
		{
			if (g_pManager->GetPlayStatus() == 1)
			{
				IMSEventCallback* pLyricsManager = (IMSEventCallback*)(g_pManager->GetIMSEventCallback());
				if (pLyricsManager->IsLyricsUpdate(szLyricsMessage1, szLyricsMessage2) == true)
				{

					/*if (lyricsMessageSurface1)
						SDL_FreeSurface(lyricsMessageSurface1);

					if (lyricsMessageSurface2)
						SDL_FreeSurface(lyricsMessageSurface2);*/
					std::string szCompleteLyrics = szLyricsMessage1 + "\n" + szLyricsMessage2;
					pWidgetsContainer->m_pTextBox->setText(szCompleteLyrics);

					//lyricsMessageSurface1 = TTF_RenderUTF8_Blended(font, szLyricsMessage1.c_str(), textColor);
					//lyricsMessageSurface2 = TTF_RenderUTF8_Blended(font, szLyricsMessage2.c_str(), textColor2);

					//	if (lyricsMessageSurface1 == 0)
					//	exit(0);

				}

			}
		}

		/*SDL_Rect src;
		SDL_Rect dst;
		src.x = 200;
		src.y = 10;
		src.w = 400;
		src.h = 30;
		dst.x = 10;
		dst.y = ((480 / 3) * 2) + 20;

		if (lyricsMessageSurface1)
			SDL_BlitSurface(lyricsMessageSurface1, 0, pGUIManager->GetScreenSurface(), &dst);

		if (lyricsMessageSurface2)
		{
			dst.y += 80;
			SDL_BlitSurface(lyricsMessageSurface2, 0, pGUIManager->GetScreenSurface(), &dst);
		}*/

		SDL_RenderClear(pRenderer);
		pGUIManager->DoRender();
		SDL_RenderPresent(pRenderer);
	}

	pGUIManager->Finally();

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	delete g_pManager;

	return 0;
}



