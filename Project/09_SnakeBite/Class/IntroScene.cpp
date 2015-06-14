/** 
	@file	IntroScene.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임시작 화면 Scene 클래스.
*/

#include "stdafx.h"

#include "IntroScene.h"
#include "Game.h"
#include "Stage01Scene.h"
#include "PvPStageScene.h"

/**
	@brief Scene 의 초기화 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void IntroScene::Init(Game* owner)
{
	bg = IMG_Load("introBG.bmp");
	owner->SetLife(3); ///< 총 Life 설정
}

/**
	@brief Scene 의 갱신 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void IntroScene::Execute(Game* owner)
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
void IntroScene:: Exit(Game* owner) {}

/**
	@brief Scene 의 입력을 처리하는 함수 \n
	       키 입력에 따라 싱글모드, 2인모드 Scene 으로 전환 한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void IntroScene::Input(Game* owner)
{
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_KEYUP:
			if(event.key.keysym.sym == SDLK_1) ///< 1번 키를 누르면 싱글모드로
			{
				owner->FSM()->ChangeState(Stage01Scene::Shaerd());
			}
			if(event.key.keysym.sym == SDLK_2) ///< 2번 키를 누르면 2인모드로
			{
				owner->FSM()->ChangeState(PvPStageScene::Shaerd());
			}
			if(event.key.keysym.sym == SDLK_ESCAPE) ///< esc키를 누르면 프로그램 종료
			{
				exit(1);
			}
			break;
		}
	}
}

/**
	@brief Scene 이 가지고 있는 객체들의 갱신을 처리하기 위한 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void IntroScene::Update(Game* owner)
{}

/**
	@brief Scene 이 가지고 있는 객체들의 렌더링을 처리하기 위한 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void IntroScene::Rendder(Game* owner)
{
	if(bg!=NULL) 
		DrawSurface(owner->Screen(), 0, 0, bg);
}