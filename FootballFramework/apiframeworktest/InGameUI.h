#pragma once
#include "Object.h"
class Image;
class Flag;
class VSIcon;
class Player;
class Ball;
class Goalkeeper;
class DiveCollider;
class GoalText;
class InGameUI :
    public Object
{
public:
    InGameUI();
    ~InGameUI();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(InGameUI);
private:
    Flag* flag1;
    Flag* flag2;
    VSIcon* vsIcon;

    Player* pPObj;
    Ball*   pBObj;
    Goalkeeper* goalkeeper;
    DiveCollider* diveCol;

    GoalText* myGoldText;

    wstring explation;
    int round;
    bool gameStart = false;
private:
    void UISpawn();
    void IngameSpawn();
};

