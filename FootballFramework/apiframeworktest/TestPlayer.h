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
	Collider* m_diveCollider; // 다이빙 체크 
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
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	void Render(HDC _dc) override;
	virtual Object* Clone() override;
public : // 애니메이션 
	void SetAnimations(); // 애니메이션 설정 
	void PlayLeftDivingAnim(); // 왼쪽 다이빙 애니메이션 플레이
	void PlayRightDivingAnim(); // 오른쪽 다이빙 애니메이션 플레이
	void PlayRunAnim(); // 달리기 애니메이션 플레이  
	void PlayIdleAnim(); // 기본 상태 애니메이션 플레이 
public: //FSM
	// 체크 
	bool CheckIdleDistance(); 
	bool CheckDiveDistance(); 
	bool CheckTackleDistance(); 
	// 행동
	void Idle(); // 기본 
	void RunForward(); // 앞으로 달려가기 
	void Dive(); // 다이빙 
	void Tackle(); // 태클
public: // 디버그
	void SetDebugText1(wstring str) { m_debugText1 = str;}
	void SetDebugText2(wstring str) { m_debugText2 = str; }
	void SetDebugText3(wstring str) { m_debugText3 = str; }
public:
	//Collider* GetCollider() { return m_diveCollider; }
	void CreateDiveCollider(); 
};
	
