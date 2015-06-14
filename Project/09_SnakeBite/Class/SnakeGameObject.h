/** 
	@file	SnakeGameObject.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Snake 게임의 오브젝트 추상 클래스
*/

#pragma once
#include <vector>
#include "SnakeMap.h"

class SnakeGameObject
{
protected:
	SDL_Surface	*screen_; ///< 최상위 View 
	SnakeMap	*snakeMap_; ///< 타일의 정보를 가진 객체

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw()	= 0;

	void SetScreen(SDL_Surface* screen) { screen_ = screen; }
	void SetSnakeMap(SnakeMap* snakemap) { snakeMap_ = snakemap; }
};