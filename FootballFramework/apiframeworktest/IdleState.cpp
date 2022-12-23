#include "pch.h"
#include "IdleState.h"
#include "TestPlayer.h"


IdleState::IdleState(TestPlayer* owner, StateMachine* stateMachine,
	STATE_TYPE stateType)
	:State(owner,stateMachine,stateType)
{

}

void IdleState::Enter()
{
	this->m_owner->SetDebugText1(L"IDLE ENTER");
}

void IdleState::Stay()
{
	this->m_owner->SetDebugText2(L"IDLE STAY");
}

void IdleState::Exit()
{
	this->m_owner->SetDebugText3(L"IDLE EXIT");
}
