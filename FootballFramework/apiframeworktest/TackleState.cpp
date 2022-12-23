#include "pch.h"
#include "TackleState.h"
#include "Goalkeeper.h"
#include "StateMachine.h"

TackleState::TackleState(Goalkeeper* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner, stateMachine, stateType)
{
}

void TackleState::Enter()
{
	this->m_owner->SetDebugText1(L"TACKLE_ENTER");
}

void TackleState::Stay()
{
	this->m_owner->SetDebugText1(L"TACKLE_ENTER");
}

void TackleState::Exit()
{
	this->m_owner->SetDebugText1(L"TACKLE_ENTER");
}
