/** 
	@file	Point2D.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	2d 좌표를 표현하기 위한 클래스 \n
			간편한 조작을 위해 모든 맴버를 public으로 공개
*/

#include "stdafx.h"
#include "Point2D.h"

/**
	@brief Point2D 객체의 의 x, y를 설정하는 함수
	@param x x좌표
	@param y y좌표
*/
void Point2D::SetPoint2D(int x, int y) 
{
	this->x = x;
	this->y = y;
}

/**
	@brief Point2D 클래스의 기본생성자. 좌표는(0, 0) 이 된다.
*/
Point2D::Point2D() : x(0), y(0) {}

/**
	@brief Point2D 클래스의 생성자. 좌표는(x, y) 이 된다.
	@param x x좌표
	@param y y좌표
*/
Point2D::Point2D(int x, int y) : x(x), y(y) {}