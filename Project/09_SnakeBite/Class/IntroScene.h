/** 
	@file	IntroScene.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임시작 화면 Scene 클래스.
*/

#pragma once
#include "common.h"
#include "IScene.h"
class Game;
class IntroScene : public IScene<Game*>
{
private:
	SDL_Event event;
	SDL_Surface *bg;
public:
	static IntroScene* Shaerd()
	{
		static IntroScene* instance = 0;
		if( instance == 0 )
		{
			instance = new IntroScene();
		}
		return instance;
	}

	virtual void Init(Game* owner);
	virtual void Execute(Game* owner);
	virtual void Exit(Game* owner) ;
	virtual void Input(Game* owner);
	virtual void Update(Game* owner);
	virtual void Rendder(Game* owner);
};