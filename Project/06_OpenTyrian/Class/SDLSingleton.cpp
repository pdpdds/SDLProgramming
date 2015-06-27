#include "SDLSingleton.h"

SDLSingleton* SDLSingleton::m_pInstance = 0;

SDLSingleton::SDLSingleton()
{
	m_pInstance = 0;
}


SDLSingleton::~SDLSingleton()
{
}

bool SDLSingleton::InitSystem()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		return 0;
	}

#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &m_pWindow, &m_pRenderer) < 0)
#else
	if (SDL_CreateWindowAndRenderer(800, 600, 0, &m_pWindow, &m_pRenderer) < 0)
#endif
	{
		return false;
	}

	SDL_GetWindowSize(m_pWindow, &m_winWidth, &m_winHeight);

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	m_pGameScreen = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 200, 32,
		0,
		0,
		0,
		0);

	if (m_pGameScreen == 0)
	{
		return false;
	}

	m_pGameTexture = SDL_CreateTexture(m_pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		320, 200);

	if (m_pGameTexture == 0)
	{
		return false;
	}

	return true;
}

void SDLSingleton::DoRender()
{
	SDL_RenderClear(m_pRenderer);
	SDL_UpdateTexture(m_pGameTexture, NULL, m_pGameScreen->pixels, m_pGameScreen->pitch);
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = 320;
	srcRect.h = destRect.h = 200;
	destRect.x = 0;
	destRect.y = 0;

	destRect.x = 0;
	destRect.y = 0;

	destRect.w = SDL_RATIO_X(destRect.w);
	destRect.h = SDL_RATIO_Y(destRect.h);

	SDL_SetTextureAlphaMod(m_pGameTexture, 255);
	SDL_RenderCopyEx(SDLSingleton::GetInstance()->GetRenderer(), m_pGameTexture, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);

	SDL_RenderPresent(m_pRenderer);
}