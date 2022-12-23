#pragma once
#include "State.h"
class TestPlayer; 

class IdleState :
    public State 
{
public:
    IdleState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State��(��) ���� ��ӵ�
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

