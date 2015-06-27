/** 
	@file	Game.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임의 전체적인 부분을 관리하는 클래스
*/

#pragma once
#include <sdl.h>
#include "StateMachine.h"

class Game
{
private:
	StateMachine<Game*> *fsm_;		///< Scene 을 관리하는 상태머신
	SDL_Surface			*screen_;	///< 최상위 뷰
	int					life_;		///< 목숨

public:
	void Update() const;

	StateMachine<Game*> * FSM() const;
	SDL_Surface* Screen() const;
	void SetLife(int life);
	int Life() const;

	Game(SDL_Surface* screen);
	~Game();
};

