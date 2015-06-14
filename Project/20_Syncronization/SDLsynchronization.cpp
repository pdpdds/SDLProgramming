// SDLsynchronization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SDL.h"

#pragma comment(lib, "sdl2.lib")

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_mutex* gMutex = NULL;
SDL_cond* cond = NULL;
int g_sum = 0;

int proc1(void* data);
int proc2(void* data);

#define MAX_LOOP 3000000

int _tmain(int argc, _TCHAR* argv[])
{	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return 0;
	}
					
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		return 0;
	}	

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
	{
		return 0;
	}

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	
	bool quit = false;	
	SDL_Event e;

	
	gMutex = SDL_CreateMutex();

	//Create conditions
	cond = SDL_CreateCond();

	SDL_Thread* thread1 = SDL_CreateThread(proc1, "thread1", NULL);
	SDL_Thread* thread2 = SDL_CreateThread(proc2, "thread2", NULL);
	
	while (!quit)
	{	
		while (SDL_PollEvent(&e) != 0)
		{	
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
				
		SDL_RenderClear(gRenderer);
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);
	
		SDL_RenderPresent(gRenderer);
	}

	SDL_CondSignal(cond);
	
	SDL_WaitThread(thread1, NULL);
	SDL_WaitThread(thread2, NULL);

	SDL_DestroyCond(cond);
			
	return 0;
}

int proc1(void *data)
{
	for (int i = 1; i < 10000000; i++)
	{
		SDL_LockMutex(gMutex);
		g_sum += i;
		SDL_UnlockMutex(gMutex);
	}

	SDL_LockMutex(gMutex);
	SDL_CondWait(cond, gMutex);

	return 0;
}

int proc2(void *data)
{
	for (int i = 10000000; i < 20000000; i++)
	{
		SDL_LockMutex(gMutex);
		g_sum += i;
		SDL_UnlockMutex(gMutex);
	}

	return 0;
}