#include "stdafx.h"
#include "Common.h"
#include "SDLSingleton.h"



#define SDL_RATIO_X(width) width * ((float)SDLSingleton::GetInstance()->m_winWidth / (float)GAME_WIDTH)
#define SDL_RATIO_Y(height) height * ((float)SDLSingleton::GetInstance()->m_winHeight / (float)GAME_HEIGHT)

void DrawSurface(SDL_Surface *dst, int x, int y, SDL_Surface *src)
{
	SDL_Rect rectDst;

	/*SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = SDL_RATIO_X(src->w);
	srcRect.h = SDL_RATIO_X(src->h);

	rectDst.x = SDL_RATIO_X(x);
	rectDst.y = SDL_RATIO_Y(y);

	rectDst.w = SDL_RATIO_X(src->w);
	rectDst.h = SDL_RATIO_Y(src->h);*/

	rectDst.x = x;
	rectDst.y = y;

	rectDst.w = src->w;
	rectDst.h = src->h;

	SDL_BlitSurface(src, NULL, dst, &rectDst);
}

int BaseRand(int x, int y){
	static int z = 0;
	int tmp;
	if (z == 0){
		srand((int)time(NULL));
		rand(); rand(); rand(); rand();
		srand(rand());
		z = 1;
	}

	tmp = rand() % (y - x + 1) + x;
	return tmp;
}