/** 
	@file	ItemManager.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	아이템을 생성, 정보를 가지고 있는 클래스
*/

#include "stdafx.h"

#include "ItemManager.h"
#include "Point2D.h"

/**
	@brief 오브젝트 초기화 함수
*/

ItemManager::ItemManager()
{
	speedItem = IMG_Load("speed_item.bmp"); ///< 스피드업 아이템 이미지 로드
	tailItem = IMG_Load("tail_item.bmp");  ///< 꼬리 증가 아이템 이미지 로드
}

ItemManager::~ItemManager()
{
	if (pos != NULL)
		delete pos;

	SDL_FreeSurface(speedItem);
	SDL_FreeSurface(tailItem);
}

void ItemManager::Init() 
{
	pos = new Point2D(0,0);		///< 좌표 초기화
	inc = 0;					///< 아이템 종류 초기화
	
	this->CreateItem();			///< 아이템 생성

	
}	

/**
	@brief 오브젝트 갱신 함수 \n
		   아이템의 위치와 종류를 snakeMap_에 등록한다.
*/
void ItemManager::Update()
{
	char ch = inc + '0';
	snakeMap_->SetTilesInfoOfIndex(pos->x, pos->y, ch);
}		

/**
	@brief 오브젝트 렌더 함수\n
	       아이템의 위치와 종류 정보를 화면에 그린다.
*/
void ItemManager::Draw() 
{
	char ch = inc + '0';

	SDL_Surface* item;

	if (ch == '0')		item = speedItem; ///< 스피드업 아이템 이미지 로드
	else			item = tailItem;  ///< 꼬리 증가 아이템 이미지 로드

	DrawSurface(screen_, pos->x * 20, pos->y * 20, item);
}	

/**
*/
void ItemManager::CreateItem()
{
	while (1) {										///< 아이템이 생성될 때 까지 반복
		int x = BaseRand(1,snakeMap_->Width()-2);	///< 테두리를 뺀 영역에서 렌덤값 생성
		int y = BaseRand(1,snakeMap_->Height()-2);
		
		char ch = snakeMap_->TilesInfoOfIndex(x,y);	///< TileData에서 렌덤한 위치 좌표의 정보를 조사한다.

		if( ch == ' ' || ch == 0)	///< 빈 공간이면 해당 위치에 아이템 생성
		{
			pos->SetPoint2D(x,y);
			inc = BaseRand(0, 5);	///< 0 : 스피드 증가  1 ~ 4 : 꼬리 갯수 증가
			return;					///< 생성 후 루프문 탈출
		}
	}
}