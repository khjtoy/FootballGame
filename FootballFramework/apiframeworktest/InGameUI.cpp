#include "pch.h"
#include "InGameUI.h"
#include "ResMgr.h"
#include "Image.h"
#include "Vec2.h"
#include "Flag.h"
#include "Core.h"

InGameUI::InGameUI()
{
	Flag* flag = new Flag;
	flag->SetCheck(true);
	flag->SetcurIndex(5);
	flag->SetIndexImage();
	flag->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	flag->SetScale(Vec2(0.2f, 0.2f));
	CreateObject(flag, GROUP_TYPE::UI);
}

InGameUI::~InGameUI()
{
}

void InGameUI::Update()
{
}

void InGameUI::Render(HDC _dc)
{

}
