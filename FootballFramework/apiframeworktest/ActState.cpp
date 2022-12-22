#include "pch.h"
#include "ActState.h"
#include "TestPlayer.h"

ActState::ActState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
{
}

void ActState::Enter()
{
	this->m_owner->SetDebugText1(L"ACT_ENTER");
}

void ActState::Stay()
{
	this->m_owner->SetDebugText1(L"ACT_ENTER");
}

void ActState::Exit()
{
	this->m_owner->SetDebugText1(L"ACT_EXIT");
}
