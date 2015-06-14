/** 
	@file	Game.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임의 전체적인 부분을 관리하는 클래스
*/

#include "stdafx.h"

#include "Game.h"
#include "IntroScene.h"
#include "SDLSingleton.h"
/**
	@brief 게임의 전체적인 로직, 렌더 갱신
*/
void Game::Update() const
{
	if(fsm_!=NULL)		fsm_->Update();
	if (screen_ != NULL)	SDLSingleton::GetInstance()->DoRender();
}

/**
	@brief 생성자
	@param screen 최상위 View의 포인터
*/
Game::Game(SDL_Surface* screen) 
	:screen_(screen),  ///< main 함수에서 Screen에 대한 포인터 얻어옴
	 fsm_(NULL),
	 life_(3)
{
	// 상태머신 생성, IntroScene 으로 시작
	fsm_ = new StateMachine<Game*>(this);
	fsm_->ChangeState( IntroScene::Shaerd() );
}

/**
	@brief screen 포인터에 대한 Get 함수
	@return screen 포인터
*/
SDL_Surface* Game::Screen() const
{
	return screen_;
}

/**
	@brief stateMachine 포인터에 대한 Get 함수
	@return stateMachine 포인터
*/
StateMachine<Game*> * Game::FSM() const
{
	return fsm_;
}

/**
	@brief life를 Set 하는 함수
	@param life 목숨
*/
void Game::SetLife(int life) 
{
	life_ = life;
}

/**
	@brief life 대한 Get 함수
	@return 현재 목숨
*/
int Game::Life() const 
{ 
	return life_; 
}

/**
	@brief 소멸자.
*/
Game::~Game()
{
	screen_ = NULL;

	delete fsm_;
	fsm_ = NULL;
}
