#pragma once
#include "State.h"
class Player;
class DiveState :
    public State
{
public:
    DiveState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State��(��) ���� ��ӵ�
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

