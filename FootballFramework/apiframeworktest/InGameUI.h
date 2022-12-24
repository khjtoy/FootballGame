#pragma once
#include "Object.h"
class Image;
class Flag;
class VSIcon;
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
    wstring explation;
    wstring round;
    bool gameStart = false;
};

