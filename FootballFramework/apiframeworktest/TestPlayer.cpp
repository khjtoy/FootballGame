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
TestPlayer::TestPlayer()
	:m_stateMachine(nullptr)
	,idleState(nullptr)
	,runState(nullptr)
	,actState(nullptr)
{
	// collider 새성
	CreateCollider();
	GetCollider()->SetScale(Vec2(20.f, 30.f));

	// FSM 초기화 및 설정 
	m_stateMachine = new StateMachine(this); 
	idleState = new IdleState(this, m_stateMachine, STATE_TYPE::IDLE);
	runState = new RunState(this, m_stateMachine, STATE_TYPE::RUN);
	actState = new ActState(this, m_stateMachine, STATE_TYPE::ACT);
	m_stateMachine->AddState(idleState);
	m_stateMachine->AddState(runState);
	m_stateMachine->AddState(actState);

	m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	// FSM 끝 

	Image* pImg = ResMgr::GetInst()->ImgLoad(L"AILeftDiving", L"Image\\GoalkeeperFrontLeft.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"AILeftDiving", pImg, Vec2(138.f, 0.f), Vec2(23.f, 22.f), Vec2(-23.f, 0.f), 7, 0.1f);
	GetAnimator()->Play(L"AILeftDiving", true);
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