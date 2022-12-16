#pragma once

#include "State.h"
template <typename T> 
class StateMachine
{
private:
	T* m_owner;
	map< STATE_TYPE, *State<T>> m_stateMap;
	State<T>* m_prevState;
	State<T>* m_nowState;
public:
	StateMachine(T& owner);
	~StateMachine();
public:
	void AddState(State<T>* state); // 처음에 상태 추가하기
	State<T>* GetState(STATE_TYPE state); // 현재 상태 반환
	void ChangeState(STATE_TYPE stateType); // 상태 변경 
	Update() { nowState->Stay(); } // 현재 상태 업데이트 

};

