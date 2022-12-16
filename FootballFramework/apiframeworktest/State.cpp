#include "pch.h"
#include "State.h"
template<typename T>
State<T>::State(T& owner, StateMachine<T>& stateMachine, STATE_TYPE stateType)
{
	this->m	_owner = owner; 
	this->m_stateMachine = stateMachine; 
	this->m_stateType = stateType; 
}

template<typename T>
State<T>::~State()
{
	if (m_owner != nullptr)
	{
		delete m_owner;
	}
	if (m_stateMachine != nullptr)
	{
		delete m_stateMachine;
	}
}


