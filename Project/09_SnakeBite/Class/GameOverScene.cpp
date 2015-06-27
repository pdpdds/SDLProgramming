/** 
	@file	GameOverScene.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임오버 Scene 클래스.
*/

#include "stdafx.h"
#include "GameOverScene.h"
#include "IntroScene.h"
#include "Game.h"

/**
	@brief Scene 의 초기화 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene::Init(Game* owner)
{
	
}

GameOverScene::GameOverScene()
{
	bg = IMG_Load("GameOverBG.bmp");
}

/**
	@brief Scene 의 갱신 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene::Execute(Game* owner)
{
	this->Input(owner);	
	this->Update(owner);
	this->Rendder(owner);
}

/**
	@brief Scene 의 종료 함수.\n
		   주로 맴버 변수의 메모리 정리를 한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene:: Exit(Game* owner) 
{
	SDL_FreeSurface(bg);
	bg = NULL;
}

/**
	@brief Scene 의 입력을 처리하는 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene::Input(Game* owner)
{
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_KEYUP: ///< 아무키나 누르면 메뉴 화면으로 돌아감
			owner->FSM()->ChangeState(IntroScene::Shaerd());
			break;
		case SDL_FINGERUP:
		{

			owner->FSM()->ChangeState(IntroScene::Shaerd());
		}
		break;
		}

	}
}

/**
	@brief Scene 이 가지고 있는 객체들의 갱신을 처리하기 위한 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene::Update(Game* owner)
{}

/**
	@brief Scene 이 가지고 있는 객체들의 렌더링을 처리하기 위한 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void GameOverScene::Rendder(Game* owner)
{
	if(bg!=NULL) 
	{
		DrawSurface(owner->Screen(), 0, 0, bg);
	}
}