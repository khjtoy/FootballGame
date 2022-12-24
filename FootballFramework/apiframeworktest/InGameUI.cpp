#include "pch.h"
#include "InGameUI.h"
#include "ResMgr.h"
#include "Image.h"
#include "Vec2.h"
#include "Flag.h"
#include "VSIcon.h"
#include "Core.h"
#include "KeyMgr.h"

InGameUI::InGameUI()
	:explation(L"Press S to Start"),
	 round(L"Round 1")
{
	// ´ëÇÑ¹Î±¹ ±¹±â
	flag1 = new Flag;
	flag1->SetCheck(true);
	flag1->SetcurIndex(5);
	flag1->SetIndexImage();
	flag1->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 100, Core::GetInst()->GetResolution().y / 2 + 200));
	flag1->SetScale(Vec2(0.2f, 0.2f));
	CreateObject(flag1, GROUP_TYPE::UI);

	// °æÀï ÆÀ ±¹±â
	flag2 = new Flag;
	flag2->SetCheck(true);
	flag2->SetcurIndex(0);
	flag2->SetIndexImage();
	flag2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 + 380, Core::GetInst()->GetResolution().y / 2 + 200));
	flag2->SetScale(Vec2(0.2f, 0.2f));
	CreateObject(flag2, GROUP_TYPE::UI);

	// VS ¾ÆÀÌÄÜ
	vsIcon = new VSIcon;
	vsIcon->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 158, Core::GetInst()->GetResolution().y / 2 - 70));
	vsIcon->SetScale(Vec2(3.5f, 3.5f));
	CreateObject(vsIcon, GROUP_TYPE::UI);
}

InGameUI::~InGameUI()
{
}

void InGameUI::Update()
{
	if (KEY_TAP(KEY::S) && !gameStart)
	{
		gameStart = true;
		DeleteObject(flag1);
		DeleteObject(flag2);
		DeleteObject(vsIcon);
	}
}

void InGameUI::Render(HDC _dc)
{
	if (!gameStart)
	{
		HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH, TEXT("±Ã¼­"));

		HFONT oldFont = (HFONT)SelectObject(_dc, hFont);
		SetBkMode(_dc, TRANSPARENT);

		SetTextColor(_dc, RGB(0, 0, 0));

		TextOut(_dc, 460, 250, round.c_str(), round.length());

		TextOut(_dc, 400, 420, explation.c_str(), explation.length());

		SelectObject(_dc, oldFont);
		SetBkMode(_dc, OPAQUE);
		DeleteObject(hFont);
	}
	Component_Render(_dc);
}
