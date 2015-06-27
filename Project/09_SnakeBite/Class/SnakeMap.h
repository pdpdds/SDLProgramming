/** 
	@file	SnakeMap.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	게임의 모든 오브젝트가 참조할 타일의 정보를 가지고 있는 클래스
*/

#pragma once
#include "common.h"
class SnakeMap
{
private:
	int width_;  ///< 타일의 가로 길이
	int height_; ///< 타일의 세로길이
	std::vector<std::vector<char>> tilesInfo_; ///< tilesInfo_[height][widht] 2차원배열

public:
	SnakeMap(int width, int height);

	char TilesInfoOfIndex(int x, int y) const;
	void SetTilesInfoOfIndex(int x, int y, char ch);
	int Width() const;
	int Height() const;
};

