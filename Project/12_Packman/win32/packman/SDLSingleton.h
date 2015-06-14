#pragma once
#include <SDL.h>
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

	bool InitSystem(int width, int height);

	int m_winWidth, m_winHeight;

	void DoRender();


private:
	SDL_Window* m_pWindow;
	static SDLSingleton* m_pInstance;

	SDL_Renderer* m_pRenderer;

	SDL_Surface* m_pGameScreen;
	SDL_Texture* m_pGameTexture;
};

