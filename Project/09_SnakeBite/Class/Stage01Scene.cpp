/** 
	@file	Stage01Scene.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Sanke 게임에서 Stage 1 의 Scene 클래스
*/

#include "stdafx.h"
#include "Stage01Scene.h"
#include "Stage02Scene.h"
#include "GameOverScene.h"

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
void Stage01Scene::Init(Game* owner)
{
	snakeMap = new SnakeMap(30, 20); ///< 타일 정보 생성

	wall = new Wall("stage01.txt");	///< 벽 생성
	wall->SetScreen(owner->Screen());
	wall->SetSnakeMap(snakeMap);
	wall->Init();

	itemMgr = new ItemManager(); ///< 아이템 생성
	itemMgr->SetScreen(owner->Screen());
	itemMgr->SetSnakeMap(snakeMap);
	itemMgr->Init();

	snake = new Snake(3, 3); ///< 뱀 생성	
	snake->SetSnakeMap(snakeMap);
	snake->SetItemManager( itemMgr );
	snake->SetScreen(owner->Screen());
	snake->Init();

	clear_tailCount = 20; ///< 클리어 꼬리 갯수
}

/**
	@brief Scene 의 갱신 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void Stage01Scene::Execute(Game* owner)
{
	this->Input(owner);
	this->Update(owner);
	this->Rendder(owner);
	
	if(clear_tailCount < snake->BodyCount()) ///< 클리어 목표를 달성하면
	{ 
		owner->FSM()->ChangeState( Stage02Scene::Shaerd() ); ///< Stage2 로 넘어감
		return;
	}

	if( snake->IsArrive() == false ) ///< 뱀이 죽으면
	{
		owner->SetLife( owner->Life()-1 ); ///< life 1 감소
		int life = owner->Life();

		if(life == 0 ) ///< 목숨이 0개면 게임오버
			owner->FSM()->ChangeState( GameOverScene::Shaerd() );

		else ///< 목숨이 남았으면 스테이지 다시 시작
			owner->FSM()->ChangeState( Stage01Scene::Shaerd() );
	}
}

/**
	@brief Scene 의 종료 함수.\n
		   주로 맴버 변수의 메모리 정리를 한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void Stage01Scene::Exit(Game* owner) 
{
	delete wall;		wall = NULL;
	delete itemMgr;		itemMgr = NULL;
	delete snake;		snake = NULL;
	delete snakeMap;	snakeMap = NULL;
}