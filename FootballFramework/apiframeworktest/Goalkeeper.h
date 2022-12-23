#pragma once
#include "Object.h"
#include "State.h"

class Collider; 
class IdleState; 
class RunState;
class DiveState;
class TackleState; 
class StateMachine;
class Image; 
class Goalkeeper : 
	public Object
{
private:
	float m_runSpeed; 
	float m_idleDistance; 
	float m_tackleDistance; 
	Collider* m_diveCollider; // ���̺� üũ

private: 
	// FSM
	// STATE
	StateMachine* m_stateMachine;
	IdleState* m_idleState; 
	RunState* m_runState; 
	DiveState* m_diveState; 
	TackleState* m_tackleState; 
private:
	
private: // �����
	wstring m_debugText1;
	wstring m_debugText2;
	wstring m_debugText3;
public:
	Goalkeeper(float runSpeed);
	~Goalkeeper(); 
public:
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(Goalkeeper);
//	virtual Object* Clone() override;
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
	float GetTargetDistance(); 
	Vec2 GetTargetDir(); 

};
	
