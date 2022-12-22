#include "pch.h"
#include "Ball.h"
#include "Image.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
#include "Vec2.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Collider.h"

Ball::Ball()
	:ballPos(8.0f,3.0f),
	rot(0),
	speedX(300),
	speedY(1000)
{

	Image* pImg = ResMgr::GetInst()->ImgLoad(L"BallAni", L"Image\\Ball.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"BallAction", pImg, Vec2(0.f, 0.f), Vec2(16.f, 16.f), Vec2(16.f, 0.f), 3, 0.05f);
	GetAnimator()->Play(L"BallAction", true);

	CreateCollider();
	GetCollider()->SetOffsetPos(Vec2(-10.f, -10.f));
	GetCollider()->SetScale(Vec2(20.f, 20.f));
}

Ball::~Ball()
{
}

void Ball::Update()
{
	GetAnimator()->Update();
	if (KEY_TAP(KEY::LEFT))
	{
		dir = -1;
	}
	if (KEY_TAP(KEY::RIGHT))
	{
		dir = 1;
	}
	if (KEY_AWAY(KEY::SPACE))
	{
		if (KEY_HOLD(KEY::LEFT) || KEY_AWAY(KEY::LEFT))
		{
			rot = -1;
		}
		else if (KEY_HOLD(KEY::RIGHT) || KEY_AWAY(KEY::RIGHT))
		{
			rot = 1;
		}
		isCheck = true;
	}
	if (isCheck)
	{
		
		if (rot == -1)
		{
			ballPos.x -= speedX * fDT;
		}
		else if (rot == 1)
		{
			ballPos.x += speedX * fDT;
		}
		ballPos.y -= speedY * fDT;
		SetPos(Vec2(ballPos.x , ballPos.y));
		//y -= ballSpeed * fDT;
	}
	else
		SetPos(Vec2(8 * dir, -3));
}

void Ball::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Ball::EnterCollision(Collider* _pOther)
{
	speedX = 0;
	speedY = 0;
	Object* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetName() == L"Goal")
	{
		speedX = 0;
		speedY = 0;
	}
}
