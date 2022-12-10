#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
Player::Player()
	:hSpeed(150.f),
	 vSpeed(80.f)
{

	// image ���ε�
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");

	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 100.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset ���� �ø���. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for(size_t i=0;i<pAnim->GetMaxFrame();i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_NONE(KEY::D))
	{
		vPos.y -= vSpeed * fDT;
		if (KEY_HOLD(KEY::LEFT))
		{
			vPos.x -= hSpeed * fDT;
		}
		if (KEY_HOLD(KEY::RIGHT))
		{
			vPos.x += hSpeed * fDT;
		}
	}
	else
	{
		// �� ���� �ӵ� ���̱�
		vPos.y -= (vSpeed / 2) * fDT;
	}
	SetPos(vPos);
	GetAnimator()->Update();
}

void Player::Render(HDC _dc)
{
	Component_Render(_dc);
}
