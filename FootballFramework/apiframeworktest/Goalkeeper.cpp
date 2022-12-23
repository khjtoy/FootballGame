#include "pch.h"
#include "define.h"
#include "KeyMgr.h"
#include "Goalkeeper.h"
#include "StateMachine.h"
#include "State.h"
#include "IdleState.h"
#include "RunState.h"
#include "ActState.h"
#include "TackleState.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "TimeMgr.h"
#include "SelectGDI.h"


Goalkeeper::Goalkeeper(float runSpeed)
	:m_stateMachine(nullptr)
	,m_idleState(nullptr)
	,m_runState(nullptr)
	, m_diveState(nullptr)
	, m_diveCollider(nullptr)
	, m_idleDistance(100)
	, m_tackleDistance(30)
{
	m_runSpeed = runSpeed; 
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));
	GetCollider()->SetOffsetPos(Vec2(-10.f, -10.f));

	// FSM 초기화 및 설정 
	m_stateMachine = new StateMachine(this); 
	m_idleState = new IdleState(this, m_stateMachine, STATE_TYPE::IDLE);
	m_runState = new RunState(this, m_stateMachine, STATE_TYPE::RUN);
	m_diveState = new DiveState(this, m_stateMachine, STATE_TYPE::DIVE);
	m_tackleState = new TackleState(this, m_stateMachine, STATE_TYPE::TACKLE); 
	m_stateMachine->AddState(m_idleState);
	m_stateMachine->AddState(m_runState);
	m_stateMachine->AddState(m_diveState);
	m_stateMachine->AddState(m_tackleState);

	m_stateMachine->ChangeState(STATE_TYPE::RUN);
	// FSM 끝 

	// 애니메이션 설정
	SetAnimations(); 

}

Goalkeeper::~Goalkeeper()
{
	if (m_stateMachine != nullptr)
		delete m_stateMachine;
	if (m_idleState != nullptr)
		delete m_idleState; 
	if (m_runState != nullptr)
		delete m_runState;
	if (m_diveState != nullptr)
		delete m_diveState;
	if (m_diveCollider != nullptr)
		delete m_diveCollider;
}

void Goalkeeper::Update()
{
	if(KEY_TAP(KEY::A))
	{
		m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	}
	else if (KEY_TAP(KEY::S))
	{
		m_stateMachine->ChangeState(STATE_TYPE::RUN);
	}
	else if (KEY_TAP(KEY::D))
	{
		m_stateMachine->ChangeState(STATE_TYPE::DIVE);
	}
	else if (KEY_TAP(KEY::Q))
	{
		PlayLeftDivingAnim(); 
	}
	else if (KEY_TAP(KEY::W))
	{
		PlayRightDivingAnim();
	}
	else if (KEY_TAP(KEY::E))
	{
		PlayRunAnim();
	}
	m_stateMachine->Update();
	GetAnimator()->Update();

}

void Goalkeeper::Render(HDC _dc)
{
	Component_Render(_dc);

	// 디버그용 코드 시작 
	wstring curStateName = m_stateMachine->GetCurStateName();
	TextOut(_dc, 10, 10, curStateName.c_str(), curStateName.length()); // 현재 상태 이름 
	TextOut(_dc, 10, 40, m_debugText1.c_str(), m_debugText1.length()); // Enter
	TextOut(_dc, 10, 70, m_debugText2.c_str(), m_debugText2.length()); // Stay
	TextOut(_dc, 10, 200, m_debugText3.c_str(), m_debugText3.length()); // Exit

	PEN_TYPE ePen = PEN_TYPE::RED;
	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	// 멈추는 범위 디버그
	Ellipse(_dc, GetPos().x - m_idleDistance,
		GetPos().y + m_idleDistance ,
		GetPos().x + m_idleDistance,
		GetPos().y - m_idleDistance );

	// 태클 범위 디버그
	Ellipse(_dc, GetPos().x - m_tackleDistance,
		GetPos().y + m_tackleDistance ,
		GetPos().x + m_tackleDistance ,
		GetPos().y - m_tackleDistance);

	// 골키퍼 포지션 -> 플레이어 포지션 
	MoveToEx(_dc, GetPos().x, GetPos().y, NULL); 
	LineTo(_dc, GetFollower()->GetPos().x, GetFollower()->GetPos().y);
	// 디버그용 코드 끝
}

// 애니메이션 플레이 함수 

void Goalkeeper::SetAnimations()
{
	CreateAnimator();

	Image* pImg1 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperLeftDiving", L"Image\\GoalkeeperFrontLeft.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperLeftDiving", pImg1, Vec2(138.f, 0.f), Vec2(23.f, 22.f), Vec2(-23.f, 0.f), 6, 0.1f);

	Image* pImg2 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRightDiving", L"Image\\GoalkeeperFrontRight.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRightDiving", pImg2, Vec2(0.f, 0.f), Vec2(23.f, 22.f), Vec2(23.f, 0.f), 6, 0.1f);

	Image* pImg3 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRunFront", L"Image\\GoalkeeperRunFront.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRunFront", pImg3, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.1f);
}

void Goalkeeper::PlayLeftDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperLeftDiving", false);
}

void Goalkeeper::PlayRightDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperRightDiving", false);
}

void Goalkeeper::PlayRunAnim()
{
	GetAnimator()->Play(L"GoalkeeperRunFront", true);
}

void Goalkeeper::PlayIdleAnim()
{
}

bool Goalkeeper::CheckIdleDistance()
{
	if (GetTargetDistance() < m_idleDistance)
	{
		return true;
	}
	return false;
}

bool Goalkeeper::CheckDiveDistance()
{

	return false;
}

bool Goalkeeper::CheckTackleDistance()
{
	if (GetTargetDistance() < m_tackleDistance)
	{
		return true;
	}
	return false;
}

void Goalkeeper::Idle()
{
}

void Goalkeeper::RunForward()
{


	//wstring str; 
	//str.assign(to_string(dir.x).begin(), to_string(dir.x).end()); 
	//SetDebugText2(str);
	Vec2 vPos = GetPos();
	Vec2 dir = GetTargetDir(); 
	vPos.x += dir.x * m_runSpeed * fDT;
	vPos.y += dir.y * m_runSpeed * fDT;
	SetPos(vPos);
}

void Goalkeeper::Dive()
{
	Vec2 vPos = GetPos();
	vPos.x += 100.f * fDT;
	SetPos(vPos);
}

void Goalkeeper::Tackle()
{
}

void Goalkeeper::CreateDiveCollider()
{
}

float Goalkeeper::GetTargetDistance()
{
	Vec2 v = this->GetFollower()->GetPos(); // 타겟 위치
	Vec2 v2 = this->GetPos(); // 내 위치
	return (v - v2).Length();
}

Vec2 Goalkeeper::GetTargetDir()
{
	Vec2 vPos = GetPos();
	Vec2 followPos = this->GetFollower()->GetPos();
	return (followPos - vPos).Normalize();
}
