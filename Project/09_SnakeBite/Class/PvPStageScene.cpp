/** 
	@file	PvPStageScene.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Sanke 게임에서 대전모드의 Scene 클래스
*/

#include "StdAfx.h"
#include "PvPStageScene.h"

#include "Game.h"
#include "SnakeMap.h"
#include "Wall.h"
#include "ItemManager.h"
#include "Snake.h"
#include "TextFieldFactory.h"

/**
	@brief Scene 의 초기화 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void PvPStageScene::Init(Game* owner)
{
	snakeMap = new SnakeMap(30, 20);

	wall = new Wall("stage01.txt");	///< 벽 생성
	wall->SetScreen(owner->Screen());
	wall->SetSnakeMap(snakeMap);
	wall->Init();

	itemMgr = new ItemManager(); ///< 아이템 생성
	itemMgr->SetScreen(owner->Screen());
	itemMgr->SetSnakeMap(snakeMap);
	itemMgr->Init();

	snake_1p = new Snake(3, 3);	 ///< 1p 뱀 생성	
	snake_1p->SetSnakeMap(snakeMap);
	snake_1p->SetItemManager( itemMgr );
	snake_1p->SetScreen(owner->Screen());
	snake_1p->Init();

	snake_2p = new Snake(10, 3); ///< 2p 뱀 생성	
	snake_2p->SetSnakeMap(snakeMap);
	snake_2p->SetItemManager( itemMgr );
	snake_2p->SetScreen(owner->Screen());
	snake_2p->Init();
}

/**
	@brief Scene 의 갱신 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void PvPStageScene::Execute(Game* owner)
{
	this->Input(owner);	
	this->Update(owner);
	this->Rendder(owner);


	if( snake_1p->IsArrive() == false ) ///< 1p 뱀이 죽으면..
	{}
	if( snake_2p->IsArrive() == false ) ///< 2p 뱀이 죽으면..
	{}
}

/**
	@brief Scene 의 종료 함수.\n
		   주로 맴버 변수의 메모리 정리를 한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void PvPStageScene::Exit(Game* owner) 
{
	delete wall;		wall = NULL;
	delete itemMgr;		itemMgr = NULL;
	delete snake_1p;	snake_1p = NULL;
	delete snake_2p;	snake_2p = NULL;
	delete snakeMap;	snakeMap = NULL;
}

/**
	@brief Scene 의 입력을 처리하는 함수\n
	       두 플레이어의 키 입력으로 뱀 움직임을 처리한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void PvPStageScene::Input(Game* owner)
{
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_KEYUP:			
			if(event.key.keysym.sym == SDLK_UP) ///< 1p 
			{
				snake_1p->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				snake_1p->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				snake_1p->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_RIGHT)
			{
				snake_1p->SetDir(Snake::kRIGHT);
			}
			
			if(event.key.keysym.sym == SDLK_w) ///< 2p
			{
				snake_2p->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_s)
			{
				snake_2p->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_a)
			{
				snake_2p->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_d)
			{
				snake_2p->SetDir(Snake::kRIGHT);
			}

			if(event.key.keysym.sym == SDLK_ESCAPE) ///< 종료
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
void PvPStageScene::Update(Game* owner)
{
	wall->Update();
	itemMgr->Update();
	snake_1p->Update();
	snake_2p->Update();
}

void PvPStageScene::Rendder(Game* owner)
{
	wall->Draw();
	itemMgr->Draw();
	snake_1p->Draw();
	snake_2p->Draw();
}