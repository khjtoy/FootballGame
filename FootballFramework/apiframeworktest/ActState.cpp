#include "pch.h"
#include "ActState.h"
#include "TestPlayer.h"

DiveState::DiveState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
{
}

void DiveState::Enter()
{
	this->m_owner->SetDebugText1(L"ACT_ENTER");
}

void DiveState::Stay()
{
	this->m_owner->SetDebugText1(L"ACT_ENTER");
}

void DiveState::Exit()
{
	this->m_owner->SetDebugText1(L"ACT_EXIT");
}
