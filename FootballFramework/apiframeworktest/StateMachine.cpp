#include "pch.h"
#include "StateMachine.h"

template<typename T>
StateMachine<T>::StateMachine(T& owner) 
	: m_stateMap(nullptr)
	, m_prevState(nullptr)
	, m_nowState(nullptr)
{
	this->m_owner = owner; 
}

template<typename T>
StateMachine<T>::~StateMachine()
{
	if (m_owner != null)
		delete m_owner; 
	if (m_stateMap != null)
		delete m_stateMap;
	if (m_prevState != null)
		delete m_prevState;
	if (m_nowState != null)
		delete m_nowState;
}

template<typename T>
void StateMachine<T>::AddState(State<T>* state)
{
	m_stateMap.insert(make_pair(state->));
}

template<typename T>
State<T>* StateMachine<T>::GetState(STATE_TYPE state)
{
	return m_nowState;
}

template<typename T>
void StateMachine<T>::ChangeState(STATE_TYPE stateType)
{
	// ���°� �־��ٸ� Exit ���� 
	if (m_nowState != nullptr)
	{
		m_nowState->Exit(); 
	}
	// ������ prevState�� ���� 
	m_prevState = m_nowState; 
	
	// map���� stateType�� ���� nowState ���� 
	m_nowState = m_stateMap[stateType];
	m_nowState->Enter(); 
}


