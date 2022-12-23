#pragma once
#include "Object.h"
class Player;
class Ball :
    public Object
{
public:
    Ball();
    ~Ball();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    virtual void	EnterCollision(Collider* _pOther);
    CLONE(Ball);
private:
    int dir = -1;
    // -1:L 0:M 1:R
    int rot;
    float speedX;
    float speedY;
    Vec2 ballPos;
    bool isCheck = false;
private:
    void CreateGoalText();
};

