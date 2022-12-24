#include "pch.h"
#include "Scene_InGame.h"
#include "Object.h"
#include "Player.h"
#include "Staduim.h"
#include "Goal.h"
#include "Ball.h"
#include "InGameUI.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "Goalkeeper.h"
#include "DiveCollider.h"
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
	Object* pPObj = new Player;
	pPObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
	pPObj->SetScale(Vec2(2.f,2.f));
	AddObject(pPObj, GROUP_TYPE::PLAYER);

	pObj = new Ball;                                                     
	pObj->SetParent(pPObj);
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(2.5f,2.5f));
	pObj->SetName(L"Ball");
	AddObject(pObj, GROUP_TYPE::BALL);

	// 골키퍼 오브젝트
	Goalkeeper* goalkeeper = new Goalkeeper(30.f,600.f);
	goalkeeper->SetName(L"Goalkeeper");
	goalkeeper->SetFollower(pPObj);
	goalkeeper->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	goalkeeper->SetScale(Vec2(2.f, 2.f));
	AddObject(goalkeeper, GROUP_TYPE::AI);

	// 다이브 체크 콜라이더 오브젝트
	DiveCollider* diveCol = new DiveCollider(60.f);
	diveCol->SetName(L"DiveCollider");
	diveCol->SetParent(goalkeeper);
	//diveCol->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	diveCol->SetScale(Vec2(1.f, 30.f));
	AddObject(diveCol, GROUP_TYPE::COLLIDER);
	goalkeeper->SetDiveCollider(diveCol);

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
