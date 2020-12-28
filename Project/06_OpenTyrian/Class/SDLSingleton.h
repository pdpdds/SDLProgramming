#pragma once
#include <SDL2/SDL.h>

#define SDL_RATIO_X(width) width * ((float)SDLSingleton::GetInstance()->getGameWidth() / (float)320)
#define SDL_RATIO_Y(height) height * ((float)SDLSingleton::GetInstance()->getGameHeight() / (float)200)
#define SDL_REVERSE_RATIO_X(width) width * ((float)320 / (float)SDLSingleton::GetInstance()->getGameWidth())
#define SDL_REVERSE_RATIO_Y(height) height * ((float)200 / (float)SDLSingleton::GetInstance()->getGameHeight())
class SDLSingleton
{
public:
	SDLSingleton();
	virtual ~SDLSingleton();

	SDL_Window* GetWindow(){ return m_pWindow; }
	SDL_Surface* GetSurface(){ return m_pGameScreen; }
	SDL_Renderer* GetRenderer(){ return m_pRenderer; }

	static SDLSingleton* GetInstance()
	{
		if (m_pInstance == 0)
		{
			m_pInstance = new SDLSingleton();
		}
		return m_pInstance;
	}

	bool InitSystem();

	int getGameWidth() const { return m_winWidth; }
	int getGameHeight() const { return m_winHeight; }

	int m_winWidth, m_winHeight;

	void DoRender();


private:
	SDL_Window* m_pWindow;
	static SDLSingleton* m_pInstance;

	SDL_Renderer* m_pRenderer;

	SDL_Surface* m_pGameScreen;
	SDL_Texture* m_pGameTexture;
};

