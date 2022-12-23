#pragma once
#include "State.h"
class Player;
class DiveState :
    public State
{
public:
    DiveState(TestPlayer* owner, StateMachine* stateMachine, STATE_TYPE stateType);    // State을(를) 통해 상속됨
public:
    virtual void Enter() override;
    virtual void Stay() override;
    virtual void Exit() override;
};

