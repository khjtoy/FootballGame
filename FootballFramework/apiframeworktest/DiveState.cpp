#include "pch.h"
#include "ActState.h"
#include "Goalkeeper.h"

DiveState::DiveState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
{
}

void DiveState::Enter()
{
	// ���̺� �ִϸ��̼� 
	// �̵� 
	this->m_owner->SetDebugText1(L"ACT_ENTER");
	this->m_owner->PlayLeftDivingAnim();

}

void DiveState::Stay()
{
	this->m_owner->SetDebugText1(L"ACT_ENTER");
}

void DiveState::Exit()
{
	this->m_owner->SetDebugText1(L"ACT_EXIT");
}
