#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Staduim.h"
#include "Ball.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	// 맵 그리기
	Staduim*  pObj2 = new Staduim;
	pObj2->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj2->SetScale(Vec2(1.f, 1.f));
	AddObject(pObj2, GROUP_TYPE::PLAYER);


	// Object 추가
	Object* pPObj = new Player;
	pPObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
	//pObj->SetScale(Vec2(1.f,1.f));
	AddObject(pPObj, GROUP_TYPE::PLAYER);

	Object* pObj = new Ball;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	//pObj->SetScale(Vec2(1.f,1.f));
	AddObject(pObj, GROUP_TYPE::BALL);
	pObj->SetParent(pPObj);
}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{  
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
}
