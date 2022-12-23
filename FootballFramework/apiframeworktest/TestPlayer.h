#pragma once
#include "Object.h"
#include "State.h"

class Collider; 
class IdleState; 
class RunState;
class DiveState;
class StateMachine;
class Image; 
class TestPlayer : 
	public Object
{
private:
	Collider* m_diveCollider; // ���̺� üũ 
private: 
	StateMachine* m_stateMachine;
	IdleState* m_idleState; 
	RunState* m_runState; 
	DiveState* m_actState; 

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
	void SetAnimations(); // �ִϸ��̼� ���� 
	void PlayLeftDivingAnim(); // ���� ���̺� �ִϸ��̼� �÷���
	void PlayRightDivingAnim(); // ������ ���̺� �ִϸ��̼� �÷���
	void PlayRunAnim(); // �޸��� �ִϸ��̼� �÷���  
	void PlayIdleAnim(); // �⺻ ���� �ִϸ��̼� �÷��� 
public: //FSM
	// üũ 
	bool CheckIdleDistance(); 
	bool CheckDiveDistance(); 
	bool CheckTackleDistance(); 
	// �ൿ
	void Idle(); // �⺻ 
	void RunForward(); // ������ �޷����� 
	void Dive(); // ���̺� 
	void Tackle(); // ��Ŭ
public: // �����
	void SetDebugText1(wstring str) { m_debugText1 = str;}
	void SetDebugText2(wstring str) { m_debugText2 = str; }
	void SetDebugText3(wstring str) { m_debugText3 = str; }
public:
	//Collider* GetCollider() { return m_diveCollider; }
	void CreateDiveCollider(); 
};
	
