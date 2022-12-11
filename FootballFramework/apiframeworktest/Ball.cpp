#include "pch.h"
#include "Ball.h"
#include "Image.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Vec2.h"

Ball::Ball()
{
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"BallAni", L"Image\\Ball.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"BallAction", pImg, Vec2(0.f, 0.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 3, 0.2f);
	GetAnimator()->Play(L"BallAction", true);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	GetAnimator()->Update();
	SetPos(Vec2(0, 0));
}

void Ball::Render(HDC _dc)
{
	Component_Render(_dc);
}
