/** 
	@file	Point2D.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	2d 좌표를 표현하기 위한 클래스 \n
			간편한 조작을 위해 모든 맴버를 public으로 공개
*/

#pragma once   
class Point2D 
{
public:
	int x, y; ///< x, y, 좌표
	void SetPoint2D(int x, int y);
	Point2D();
	Point2D(int x, int y);
};