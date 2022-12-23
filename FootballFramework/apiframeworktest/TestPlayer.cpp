#include "pch.h"
#include "define.h"
#include "KeyMgr.h"
#include "TestPlayer.h"
#include "StateMachine.h"
#include "State.h"
#include "IdleState.h"
#include "RunState.h"
#include "ActState.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "TimeMgr.h"
TestPlayer::TestPlayer()
	:m_stateMachine(nullptr)
	,m_idleState(nullptr)
	,m_runState(nullptr)
	,m_actState(nullptr)
	, m_diveCollider(nullptr)
{
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// FSM 초기화 및 설정 
	m_stateMachine = new StateMachine(this); 
	m_idleState = new IdleState(this, m_stateMachine, STATE_TYPE::IDLE);
	m_runState = new RunState(this, m_stateMachine, STATE_TYPE::RUN);
	m_actState = new DiveState(this, m_stateMachine, STATE_TYPE::ACT);
	m_stateMachine->AddState(m_idleState);
	m_stateMachine->AddState(m_runState);
	m_stateMachine->AddState(m_actState);

	m_stateMachine->ChangeState(STATE_TYPE::RUN);
	// FSM 끝 

	// 애니메이션 설정
	SetAnimations(); 

}

TestPlayer::~TestPlayer()
{
	if (m_stateMachine != nullptr)
		delete m_stateMachine;
}

void TestPlayer::Update()
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
		m_stateMachine->ChangeState(STATE_TYPE::ACT);
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

Object* TestPlayer::Clone()
{
	return nullptr;
}


void TestPlayer::Render(HDC _dc)
{
	Component_Render(_dc);

	// 디버그용 코드 시작 
	wstring curStateName = m_stateMachine->GetCurStateName();
	TextOut(_dc, 10, 10, curStateName.c_str(), curStateName.length()); // 현재 상태 이름 
	TextOut(_dc, 10, 40, m_debugText1.c_str(), m_debugText1.length()); // Enter
	TextOut(_dc, 10, 70, m_debugText2.c_str(), m_debugText2.length()); // Stay
	TextOut(_dc, 10, 100, m_debugText3.c_str(), m_debugText3.length()); // Exit
	// 디버그용 코드 끝
}

// 애니메이션 플레이 함수 

void TestPlayer::SetAnimations()
{
	CreateAnimator();

	Image* pImg1 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperLeftDiving", L"Image\\GoalkeeperFrontLeft.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperLeftDiving", pImg1, Vec2(138.f, 0.f), Vec2(23.f, 22.f), Vec2(-23.f, 0.f), 7, 0.1f);

	Image* pImg2 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRightDiving", L"Image\\GoalkeeperFrontRight.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRightDiving", pImg2, Vec2(0.f, 0.f), Vec2(23.f, 22.f), Vec2(23.f, 0.f), 6, 0.1f);

	Image* pImg3 = ResMgr::GetInst()->ImgLoad(L"GoalkeeperRunFront", L"Image\\GoalkeeperRunFront.bmp");
	GetAnimator()->CreateAnimation(L"GoalkeeperRunFront", pImg3, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.1f);
}

void TestPlayer::PlayLeftDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperLeftDiving", true);
}

void TestPlayer::PlayRightDivingAnim()
{
	GetAnimator()->Play(L"GoalkeeperRightDiving", true);
}

void TestPlayer::PlayRunAnim()
{
	GetAnimator()->Play(L"GoalkeeperRunFront", true);
}

void TestPlayer::PlayIdleAnim()
{
}

bool TestPlayer::CheckIdleDistance()
{
	return false;
}

bool TestPlayer::CheckDiveDistance()
{
	return false;
}

bool TestPlayer::CheckTackleDistance()
{
	return false;
}

void TestPlayer::Idle()
{
}

void TestPlayer::RunForward()
{
	Vec2 vPos = GetPos();
	vPos.y += 100.f * fDT;
	SetPos(vPos);

}

void TestPlayer::Dive()
{
}

void TestPlayer::Tackle()
{
}

void TestPlayer::CreateDiveCollider()
{
}
