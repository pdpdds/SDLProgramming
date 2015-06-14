/** 
	@file	ISnakeSingleScene.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Sanke 게임에서 싱글모드의 Stage 에 대한 추상클래스
*/

#pragma once
#include "IScene.h"
class Game;
class SnakeMap;
class Wall;
class ItemManager;
class Snake;
class TextFieldFactory;

class ISnakeSingleScene : public IScene<Game*>
{
protected:
	SnakeMap	*snakeMap;
	Wall		*wall;
	ItemManager	*itemMgr;
	Snake		*snake;

	SDL_Event	event;
	SDL_Surface *lifeLabel;
	SDL_Surface *tailCountLabel;

	int clear_tailCount;

public:
	virtual void Init(Game* owner) = 0;
	virtual void Execute(Game* owner) = 0;
	virtual void Exit(Game* owner) = 0;

protected:
	virtual void Input(Game* owner);
	virtual void Update(Game* owner);
	virtual void Rendder(Game* owner);
	void DrawTextFiledLabelWithValue(SDL_Surface* screen, std::string label, int value, int posx, int posy);
};
