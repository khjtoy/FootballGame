#pragma once
#include "pch.h"

class TestPlayer; 
class State; 
//template <typename T> 
class StateMachine
{
private:
	TestPlayer* m_owner;
	map< STATE_TYPE, State* > m_stateMap;
	State* m_prevState;
	State* m_nowState;
public:

	StateMachine(TestPlayer* owner);
	~StateMachine();
public:
	void Update(); // ���� ���� ������Ʈ 

public:
	void AddState(State* state); // ó���� ���� �߰��ϱ�
	// ���� ���� ��ȯ
	State* GetCurState() {return m_nowState;}
	wstring GetCurStateName(); 
	void ChangeState(STATE_TYPE stateType); // ���� ���� 
	

};

