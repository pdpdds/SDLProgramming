/** 
	@file	StateMachine.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	상태를 관리하는 클래스. \n
			대상이 되는 클래스를 인자로 받고, 대상을 업데이트, 다른상태로 전환 할 수 있다.\n
			T : 대상이 되는 클래스
*/

#pragma once
#include "stdafx.h"
#include "IState.h"

template <typename T>
class StateMachine
{
private:
	T			owner; ///< 상태의 주인
	IState<T>*	currentState; ///< 현재 가지고있는 상태
public:
	StateMachine(T owner) : 
		owner(owner),
		currentState(0)
	{}

	void Update()
	{
		
		if( currentState ) ///< 상태가 있을때만, 기존 상태를 업데이트
			currentState->Execute(owner);
	}

	void ChangeState(IState<T> *newState)
	{
		
		if(currentState) ///< 상태가 있을때만, 기존 상태를 종료
			currentState->Exit(owner);
		 
		currentState = newState; ///< 새로운 상태로 전환
		currentState->Init(owner); ///< 새로운 상태 초기화
	}
};

