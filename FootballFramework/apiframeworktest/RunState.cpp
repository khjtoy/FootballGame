#include "pch.h"
#include "RunState.h"
#include "TestPlayer.h"
#include "StateMachine.h"

RunState::RunState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType)
	:State(owner,stateMachine,stateType)
{

}

void RunState::Enter()
{
	this->m_owner->SetDebugText1(L"RUN_ENTER");
}

void RunState::Stay()
{
	this->m_owner->SetDebugText2(L"RUN_STAY");
	this->m_owner->RunForward(); 
	this->m_owner->PlayRunAnim(); 
	if (this->m_owner->CheckDiveDistance() == true)
	{

	}
	if (this->m_owner->CheckIdleDistance() == true)
	{
		m_stateMachine->ChangeState(STATE_TYPE::IDLE);
	}
}

void RunState::Exit()
{
	this->m_owner->SetDebugText3(L"RUN_EXIT");
}
