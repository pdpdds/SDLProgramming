/** 
	@file	Wall.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	벽, 장애물들에 대한 정보를 가지고 있는 클래스.
*/

#pragma once
#include "SnakeGameObject.h"

class Wall : public SnakeGameObject
{
private:
	std::vector<std::vector<char>> blocks; ///< 벽, 장애물의 정보. blocks[h][w]
	SDL_Surface* bg;

public:
	Wall(const char* mapFileName);

	virtual void Init();	
	virtual void Update();	
	virtual void Draw();
};

