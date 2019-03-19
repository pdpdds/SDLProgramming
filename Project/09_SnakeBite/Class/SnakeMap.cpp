/** 
	@file	SnakeMap.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임의 모든 오브젝트가 참조할 타일의 정보를 가지고 있는 클래스
*/

#include "StdAfx.h"
#include "SnakeMap.h"

/**
	@brief 생성자. 
	@param width 타일의 너비
	@param height 타일의 높이
*/

SnakeMap::~SnakeMap()
{
	tilesInfo_.clear();
}

SnakeMap::SnakeMap(int width, int height)
	: width_(width), height_(height), tilesInfo_(NULL)
{
	for(int h=0; h<height_; h++)	///< 타일을 모두 ' ;(공백) 으로 초기화
	{
		std::vector<char> horizontal_info;
		for(int w=0; w<width_; w++)
		{
			horizontal_info.push_back(' ');
		}
		tilesInfo_.push_back(horizontal_info);
	}
}

/**
	@brief x, y 좌표 타일의 문자을 조사한다.
	@param x좌표
	@param y좌표
	@return x, y 좌표 타일의 문자
*/
char SnakeMap::TilesInfoOfIndex(int x, int y) const
{
	return tilesInfo_.at(y).at(x);
}

/**
	@brief x, y 좌표 타일의 문자을 설정한다.
	@param x x좌표 
	@param y y좌표
	@param ch 설정할 문자
*/
void SnakeMap::SetTilesInfoOfIndex(int x, int y, char ch)
{
	tilesInfo_.at(y).at(x) = ch;
}

/**
	@brief 타일의 너비를 반환하는 함수.
	@return 타일의 너비
*/
int SnakeMap::Width() const
{
	return width_;
}

/**
	@brief 타일의 높이를 반환하는 함수.
	@return 타일의 높이
*/
int SnakeMap::Height() const
{
	return height_;
}