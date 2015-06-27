/** 
	@file	ItemManager.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	아이템을 생성, 정보를 가지고 있는 클래스
*/

#pragma once
#include "common.h"
#include "SnakeGameObject.h"
class Point2D;

class ItemManager : public SnakeGameObject
{
private:
	Point2D* pos;	///< 아이템의 위치
	int inc;		///< 아이템의 종류(증가치)

public:
	void Init();	
	void Update();	
	void Draw();

	void CreateItem();	///< 아이템을 만드는 함수

	SDL_Surface* speedItem;
	SDL_Surface* tailItem;

	ItemManager();

	~ItemManager();
	
};

