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
	void AddState(State<T>* state); // ó���� ���� �߰��ϱ�
	State<T>* GetState(STATE_TYPE state); // ���� ���� ��ȯ
	void ChangeState(STATE_TYPE stateType); // ���� ���� 
	Update() { nowState->Stay(); } // ���� ���� ������Ʈ 

};

