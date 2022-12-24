#include "pch.h"
#include "Scene_InGame.h"
#include "Object.h"
#include "Staduim.h"
#include "Goal.h"
#include "InGameUI.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
Scene_InGame::Scene_InGame()
{
}

Scene_InGame::~Scene_InGame()
{
}
void Scene_InGame::Enter()
{
	//SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	//SoundMgr::GetInst()->Play(L"BGM");
	SoundMgr::GetInst()->Stop(SOUND_CHANNEL::SC_BGM);
	SoundMgr::GetInst()->Play(L"KoreaBgm");
	// 맵 그리기
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject(pObj, GROUP_TYPE::MAP);

	pObj = new Goal;
	pObj->SetName(L"Goal");
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 80, Core::GetInst()->GetResolution().y / 8 - 10));
	pObj->SetScale(Vec2(2.f, 2.f));
	AddObject(pObj, GROUP_TYPE::Goal);

	// Object 추가
	pObj = new InGameUI();
	AddObject(pObj, GROUP_TYPE::UI);
 

	// 충돌 지정
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::Goal);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::AI);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::AI, GROUP_TYPE::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::COLLIDER, GROUP_TYPE::BALL);
}

void Scene_InGame::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_InGame::Update()
{  
	Scene::Update();
}
