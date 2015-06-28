#include "SDLSingleton.h"


SDLSingleton* SDLSingleton::m_pInstance = 0;

SDLSingleton::SDLSingleton()
{
	m_pInstance = 0;
}


SDLSingleton::~SDLSingleton()
{
	SDL_DestroyTexture(m_pGameTexture);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

bool SDLSingleton::InitSystem(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		return 0;
	}

#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &m_pWindow, &m_pRenderer) < 0)
#else
	if (SDL_CreateWindowAndRenderer(width, height, 0, &m_pWindow, &m_pRenderer) < 0)
#endif
	{
		return false;
	}

	SDL_GetWindowSize(m_pWindow, &m_winWidth, &m_winHeight);

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	m_pGameScreen = SDL_CreateRGBSurface(SDL_SWSURFACE, m_winWidth, m_winHeight, 32,
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
		m_winWidth, m_winHeight);

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
	SDL_RenderCopy(m_pRenderer, m_pGameTexture, NULL, NULL);
	SDL_RenderPresent(m_pRenderer);
}