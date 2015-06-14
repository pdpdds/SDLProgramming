/** 
	@file	Snake.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	뱀에 대한 정보를 가지고 있는 클래스
*/

#include "stdafx.h"

#include "Snake.h"
#include "ItemManager.h"
#include "Point2D.h"

/**
	@brief 생성자. 시작점을 인자값으로 받아 몸통 생성
	@param startPosX x좌표
	@param startPosY y좌표
*/
Snake::Snake(int startPosX, int startPosY)
{
	body.push_back( new Point2D(startPosX, startPosY) );
	body.push_back( new Point2D(startPosX, startPosY) );
	body.push_back( new Point2D(startPosX, startPosY) );
}

/**
	@brief 오브젝트 초기화 함수
*/
void Snake::Init() 
{
	isArrive = true;

	dir = kRIGHT;	///< 초기 진행방향 : 오른쪽
	speed = 200;	
	isSpeedUp = false;

	lastUpdateTime = 0;
}	

/**
	@brief 오브젝트 갱신 함수
*/
void Snake::Update() 
{
	int currentTime = SDL_GetTicks();	///< 현재 시간 받아옴
	if(currentTime - lastUpdateTime < speed) ///< 업데이트 한지 일정 시간이 안지났으면
		return;								 ///< 그냥 리턴
	lastUpdateTime = SDL_GetTicks();		 ///< 일정 시간이 지나면 업데이트 시간을 갱신

	
	for(int i=body.size()-1; i>0; i--) ///< 꼬리의 끝부터 머리 전까지 바로 앞 몸통을 따라간다.
	{
		body[i]->x = body[i-1]->x; 
		body[i]->y = body[i-1]->y;	
		snakeMap_->SetTilesInfoOfIndex(body[i]->x, body[i]->y, '#'); ///< 오브젝트의 정보를 snakeMap_ 에 등록
	}

	switch(dir)	///< 진행 방향에 따라 머리 이동
	{
	case kLEFT:		body[0]->x--;	break;
	case kRIGHT:	body[0]->x++;	break;
	case kUP:		body[0]->y--;	break;
	case kDOWN:		body[0]->y++;	break;
	}

	this->CheckIntersection();

	snakeMap_->SetTilesInfoOfIndex(body[0]->x, body[0]->y, '#'); ///< 머리 정보를 snakeMap_에 등록

	this->CheckSpeedUpTime();
}

/**
	@brief 오브젝트 렌더 함수
*/
void Snake::Draw() 
{
	for(int i=body.size()-1; i>0; i--) ///< 꼬리 그림
	{
		SDL_Surface *tail = IMG_Load("tail.bmp");
		DrawSurface(screen_, body[i]->x * 20, body[i]->y * 20, tail);
		SDL_FreeSurface(tail);
	}

	SDL_Surface *head = IMG_Load("head.bmp"); ///< 머리 그림
	DrawSurface(screen_, body[0]->x*20, body[0]->y*20, head);
	SDL_FreeSurface(head);
}

/**
	@brief 머리가 어딘가에 충돌했는지 검사하는 함수.
*/
void Snake::CheckIntersection() 
{	
	char front = snakeMap_->TilesInfoOfIndex(body[0]->x, body[0]->y); ///< 머리 진행방향 앞쪽에 있는 TileData 정보를 검사

	if( front != ' ')		///< 빈공간이 아니면 충돌
	{
		if(front == '#')	///< 벽, 장애물, 꼬리일 경우 프로그램 종료
		{
			isArrive = false;
		}
		else if(front == '0')		///< 스피드업 아이템을 먹은 경우
		{
			time(&getItemTime);		///< 아이템을 먹으면 먹은 시간 기록
			speed = 100;			///< 스피드 증가
			isSpeedUp = true;		///< 스피드 업 상태
			itemMgr->CreateItem();	///< 새로운 아이템 생성
		}
		else ///< 꼬리 증가 아이템을 먹은 경우
		{
			int inc = front - '0';
			Point2D* lastBody = body.back();
			for(int i=0; i<inc; i++)	///< 아이템의 종류(증가치) 만큼 꼬리 증식
			{
				body.push_back( new Point2D( lastBody->x, lastBody->y ) );
			}
			itemMgr->CreateItem();	///< 새로운 아이템 생성
		}
	}
}

/**
	@brief 속도 업 아이템의 지속시간을 체크하는 함수.
*/
void Snake::CheckSpeedUpTime()
{
	time_t curTime;	 
	time(&curTime);	///< 현재 시간 기록

	if( curTime - getItemTime > 2 && isSpeedUp == true) ///< 현재시간 - 아이템먹은 시간이 일정 시간 지나고, 스피드 업 상태이면,
	{
		speed = 200;		///< 스피드를 정상속도로 돌리고
		isSpeedUp = false;	///< 스피드 업 상태가 아니게 한다.
	}
}

/**
	@brief 꼬리의 갯수를 반환하는 함수.
*/
int Snake::BodyCount() const
{
	return body.size()-1;
}

/**
	@brief 뱀의 진행 방향을 설정하는 함수. \n
		   입력값이 현재와 반대 방향이 아닐 경우만 방향을 전환한다.
	@param 방향에 대한 enum 값
*/
void Snake::SetDir(DIR d)
{	
	if( dir==kLEFT && d==kRIGHT) return;
	if( dir==kRIGHT && d==kLEFT) return;
	if( dir==kUP && d==kDOWN) return;
	if( dir==kDOWN && d==kUP) return;

	dir = d;
}

/**
	@brief 뱀의 속도값 반환.
*/
int Snake::Speed() const
{
	return speed;
}

/**
	@brief 뱀의 생사 여부 반환
*/
bool Snake::IsArrive() const
{
	return isArrive;
}

/**
	@brief ItemManager의 포인터를 입력받는 함수.
	@param itemmanager itemmanager 객체의 포인터
*/
void Snake::SetItemManager(ItemManager* itemmanger)
{
	itemMgr = itemmanger;
}