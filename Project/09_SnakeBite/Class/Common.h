#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <time.h>

/**
@brief dst Surface에 scr 경로에 있는 이미지 x, y 좌표에 출력.
@param dst scr를 출력할 SDL_Surface의 포인터
@param x   출력 될 x 좌표
@param y   출력 될 y 좌표
@param src 출력할 SDL_Surface의 포인터
*/
inline void DrawSurface(SDL_Surface *dst, int x, int y, SDL_Surface *src)
{
	SDL_Rect rectDst;
	rectDst.x = x;
	rectDst.y = y;
	SDL_BlitSurface(src, NULL, dst, &rectDst);
}

/**
@brief 숫자 2개의 범위안에서 랜덤값을 출력합니다.
@param x x 부터
@param y y 까지
@return x~y 의 범위 내 랜덤값
*/
inline int BaseRand(int x, int y){
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