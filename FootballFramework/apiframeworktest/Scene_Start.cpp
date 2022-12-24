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
	// �� �׸���
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject
	(pObj, GROUP_TYPE::MAP);

	// ����� ����
	for (int i = -200; i <= 200; i = i += 100)
	{
		int dir = rand() % 2;
		int speed = (rand() % 51) + 50;
		StartPlayer* pObj = new StartPlayer;
		pObj->SetDir(dir == 1 ? 1 : -1);
		pObj->SetSpeed(speed);
		pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + i));
		pObj->SetScale(Vec2(2.f, 2.f));
		AddObject(pObj, GROUP_TYPE::PLAYER);
	}
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
