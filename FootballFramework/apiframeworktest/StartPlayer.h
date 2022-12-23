#pragma once
#include "Object.h"
class StartPlayer :
    public Object
{
public:
    StartPlayer();
    ~StartPlayer();
private:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(StartPlayer);
private:
    int minX;
    int maxX;
    int dir;
private:
    void SetDirAni();
};

