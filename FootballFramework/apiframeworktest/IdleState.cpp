#include "pch.h"
#include "IdleState.h"
#include "Goalkeeper.h"
#include "StateMachine.h"

IdleState::IdleState(Goalkeeper* owner, StateMachine* stateMachine,
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
	if (this->m_owner->CheckTackleDistance() == true)
	{
		m_stateMachine->ChangeState(STATE_TYPE::TACKLE);
	}
	this->m_owner->SetDebugText2(L"IDLE STAY");
}

void IdleState::Exit()
{
	this->m_owner->SetDebugText3(L"IDLE EXIT");
}
