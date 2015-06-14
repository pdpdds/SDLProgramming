/** 
	@file	IState.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	상태에 대한 인터페이스 클래스 \n
			T : 상태의 대상이되는 클래스. 내부에서 대상을 조작하기 위한 인자값
*/

#pragma once
template <typename T>
class IState
{
public:
	virtual void Init(T owner) = 0;
	virtual void Execute(T owner) = 0;
	virtual void Exit(T owner) = 0;
};