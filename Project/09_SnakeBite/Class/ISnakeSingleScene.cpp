/** 
	@file	ISnakeSingleScene.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Sanke 게임에서 싱글모드의 Stage 에 대한 추상클래스
*/

#include "StdAfx.h"

#include "ISnakeSingleScene.h"
#include "SDLSingleton.h"
#include "Game.h"
#include "SnakeMap.h"
#include "Wall.h"
#include "ItemManager.h"
#include "Snake.h"
#include "TextFieldFactory.h"

/**
	@brief 문자열+숫자 형태의 문자열을 화면에 그려주는 함수.
	@param screen 그려질 화면(SDL_Surface)의 포인터
	@param label 뿌려질 문자열
	@param value 뿌려질 숫자
	@param posx 뿌려질 화면의 좌표 x
	@param posy 뿌려질 화면의 좌표 y
*/
void ISnakeSingleScene::DrawTextFiledLabelWithValue(SDL_Surface* screen, std::string label, int value, int posx, int posy)
{
	/*std::string str = TextFieldFactory::Shared()->StringAndInt(label, value);
	char *ch = const_cast<char*>(str.c_str());
	SDL_Surface *textField = TextFieldFactory::Shared()->CreateTextFieldSurface(ch);
	DrawSurface(screen , posx, posy, textField);
	SDL_FreeSurface(textField);*/
}

/**
	@brief Scene 의 입력을 처리하는 함수 \n
		   키입력으로 뱀의 움직임을 처리한다.
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void ISnakeSingleScene::Input(Game* owner)
{	
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT: break;
		case SDL_FINGERUP:
		{
			float fingerX = event.tfinger.x;
			float fingerY = event.tfinger.y;

			fingerX *= SDLSingleton::GetInstance()->m_winWidth;
			fingerY *= SDLSingleton::GetInstance()->m_winHeight;

			if (fingerX < (GAME_WIDTH / 4))
				snake->SetDir(Snake::kLEFT);
			else if (fingerX >(GAME_WIDTH - (GAME_WIDTH / 4)))
				snake->SetDir(Snake::kRIGHT);
			else if (fingerY < (GAME_HEIGHT / 4))
				snake->SetDir(Snake::kUP);
			else if (fingerY >(GAME_HEIGHT - (GAME_HEIGHT / 4)))
				snake->SetDir(Snake::kDOWN);
		}
		break;
		case SDL_KEYUP: 
			if(event.key.keysym.sym == SDLK_UP) ///< snake 움직임
			{
				snake->SetDir(Snake::kUP);
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				snake->SetDir(Snake::kDOWN);
			}
			if(event.key.keysym.sym == SDLK_LEFT)
			{
				snake->SetDir(Snake::kLEFT);
			}
			if(event.key.keysym.sym == SDLK_RIGHT)
			{
				snake->SetDir(Snake::kRIGHT);
			}
			 
			if(event.key.keysym.sym == SDLK_ESCAPE) ///< 게임 종료
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
void ISnakeSingleScene::Update(Game* owner)
{
	wall->Update();
	itemMgr->Update();
	snake->Update();
}

/**
	@brief Scene 이 가지고 있는 객체들의 렌더링을 처리하기 위한 함수
	@param owner Scene을 관리하는 StateMachine을 가지고있는 Game 객체
*/
void ISnakeSingleScene::Rendder(Game* owner)
{
	wall->Draw();
	itemMgr->Draw();
	snake->Draw();

	DrawTextFiledLabelWithValue(
		owner->Screen(), 
		"Life : ", owner->Life(), 
		0, 420);
	DrawTextFiledLabelWithValue(
		owner->Screen(), 
		"Tail Count : ", snake->BodyCount(), 
		200, 420);
}