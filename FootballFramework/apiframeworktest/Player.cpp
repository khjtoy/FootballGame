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
	 vSpeed(80.f),
	isShoot(false)
{

	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerFrontKick", L"Image\\PlayerKickF.bmp");

	pImg = ResMgr::GetInst()->ImgLoad(L"PlayerMove", L"Image\\PlayerRun.bmp");

	// animator 생성 및 animation 사용
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"PlayerRun", pImg, Vec2(0.f, 0.f), Vec2(16.f, 24.f), Vec2(16.f, 0.f), 4, 0.05f);
	GetAnimator()->Play(L"PlayerRun", true);

	// animation offset 위로 올리기. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"PlayerRun");
	//for(size_t i=0;i<pAnim->GetMaxFrame();i++)
	//	pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}
Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_NONE(KEY::SPACE) && !isShoot)
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
	else if (isShoot)
	{
		GetAnimator()->Stop();
	}
	else
	{
		// 숫 찰때 속도 줄이기
		vPos.y -= (vSpeed / 2) * fDT;
		if (KEY_AWAY(KEY::SPACE) && !isShoot)
			isShoot = true;
	}
	SetPos(vPos);
	GetAnimator()->Update();
}

void Player::Render(HDC _dc)
{

	if (isShoot)
	{
		Image* m_kickImage = ResMgr::GetInst()->ImgFind(L"PlayerFrontKick");
		int Width = (int)m_kickImage->GetWidth();
		int Height = (int)m_kickImage->GetHeight();

		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();

		vPos.x = vPos.x - (Width * vScale.x) / 2.f;
		vPos.y = vPos.y - (Height * vScale.y) / 2.f;
		//마젠타 색상 뺄때 transparent: 투명한
		TransparentBlt(_dc
			, (int)(vPos.x - (float)(Width / 2))
			, (int)(vPos.y - (float)(Height / 2))
			, Width * vScale.x, Height * vScale.y
			, m_kickImage->GetDC()
			, 0, 0, Width, Height
			, RGB(255, 0, 255));
	}
	Component_Render(_dc);
}
