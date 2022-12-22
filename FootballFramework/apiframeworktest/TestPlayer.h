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
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	void Render(HDC _dc) override;
	virtual Object* Clone() override;
public : // 애니메이션 
	void PlayLeftDivingAnim(); // 왼쪽 다이빙 애니메이션 플레이
	void PlayRightDivingAnim(); // 오른쪽 다이빙 애니메이션 플레이
	void PlayRunAnim(); // 달리기 애니메이션 플레이  
	void PlayIdleAnim(); // 기본 상태 애니메이션 플레이 
public: // 디버그
	void SetDebugText1(wstring str) { m_debugText1 = str;}
	void SetDebugText2(wstring str) { m_debugText2 = str; }
	void SetDebugText3(wstring str) { m_debugText3 = str; }

};
	
