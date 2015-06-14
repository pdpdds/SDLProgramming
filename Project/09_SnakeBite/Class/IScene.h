/** 
	@file	IScene.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	Scene 에 대한 추상 클래스
*/

#pragma once
#include "IState.h"

template <class T>
class IScene : public IState<T>
{
protected:
	virtual void Input(T owner) = 0;
	virtual void Update(T owner) = 0;
	virtual void Rendder(T owner) = 0;
};