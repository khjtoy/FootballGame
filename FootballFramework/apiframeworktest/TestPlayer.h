#pragma once
#include "Object.h"
#include "State.h"

class IdleState; 
class RunState;
class ActState;
class StateMachine;
class Image; 
class TestPlayer : 
	public Object
{
private: 
	StateMachine* m_stateMachine;
	IdleState* idleState; 
	RunState* runState; 
	ActState* actState; 

	wstring m_debugText1;
	wstring m_debugText2;
	wstring m_debugText3;
public:
	TestPlayer(); 
	~TestPlayer(); 
public:
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void Render(HDC _dc) override;
	virtual Object* Clone() override;
public : // �ִϸ��̼� 
	void PlayLeftDivingAnim(); // ���� ���̺� �ִϸ��̼� �÷���
	void PlayRightDivingAnim(); // ������ ���̺� �ִϸ��̼� �÷���
	void PlayRunAnim(); // �޸��� �ִϸ��̼� �÷���  
	void PlayIdleAnim(); // �⺻ ���� �ִϸ��̼� �÷��� 
public: // �����
	void SetDebugText1(wstring str) { m_debugText1 = str;}
	void SetDebugText2(wstring str) { m_debugText2 = str; }
	void SetDebugText3(wstring str) { m_debugText3 = str; }

};
	
