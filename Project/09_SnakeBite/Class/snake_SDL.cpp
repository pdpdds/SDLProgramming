/** 
	@file	sanke_SDL.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	콘솔 응용 프로그램에 대한 진입점을 정의합니다.
*/

#include "stdafx.h"
#include "common.h"
#include "Game.h"
#include "SDLSingleton.h"

#ifdef WIN32
#include <vld.h>
#pragma comment(lib, "vld.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_image.lib")
#endif

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	if (false == SDLSingleton::GetInstance()->InitSystem())
		return 0;

	TTF_Init();					///< TTF 초기화

	Game *pGame = new Game(SDLSingleton::GetInstance()->GetSurface());

	while(1) {
		pGame->Update();	///< 게임 갱신
		SDL_Delay(10);		///< 10ms 딜레이
	}

	SDL_Quit();	///< SDL 종료
	TTF_Quit();	///< TTF 종료

	delete pGame; ///< Game 객체 정리
	pGame = NULL;

	return 0;
}