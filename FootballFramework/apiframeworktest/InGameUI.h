#pragma once
#include "Object.h"
class Image;
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
    Image* koreaImg;
    Image* opponentImg;
    Image* vsImg;
};

