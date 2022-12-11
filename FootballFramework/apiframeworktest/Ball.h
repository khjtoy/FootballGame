#pragma once
#include "Object.h"
class Ball :
    public Object
{
public:
    Ball();
    ~Ball();
private:
    virtual void    Update() override;
    virtual void	Render(HDC _dc) override;
    CLONE(Ball);
};

