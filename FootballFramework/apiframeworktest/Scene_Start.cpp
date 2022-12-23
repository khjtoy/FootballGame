#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"
#include "Staduim.h"
#include "StartPlayer.h"
#include "StartSceneText.h"
#include "Core.h"

Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	// ¸Ê ±×¸®±â
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject
    (pObj, GROUP_TYPE::MAP);

	pObj = new StartPlayer;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(2.f, 2.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	pObj = new StartSceneText;
	AddObject(pObj, GROUP_TYPE::UI);
}

void Scene_Start::Exit()
{
	DeleteAll();
}

void Scene_Start::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::STAGE);
	}
}
