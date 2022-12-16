#pragma once
#include "StateMachine.h"

template <typename T> class State
{
protected:
	STATE_TYPE m_stateType;
	T* m	_owner;
	StateMachine<T>* m_stateMachine;
public:
	State(T& owner, StateMachine<T>& stateMachine, STATE_TYPE stateType);
	virtual ~State();

	virtual void Enter() = 0;
	virtual void Stay() = 0;
	virtual void Exit() = 0;

	STATE_TYPE GetStateType() { return m_stateType; }

};

