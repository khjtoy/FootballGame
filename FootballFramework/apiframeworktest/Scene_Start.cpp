#include "pch.h"
#include "Scene_Start.h"
#include "KeyMgr.h"
#include "Staduim.h"
#include "StartPlayer.h"
#include "StartSceneText.h"
#include "Core.h"

<<<<<<< HEAD
#include "Goalkeeper.h"
#include "DiveCollider.h"
=======
>>>>>>> KHJWork
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}

void Scene_Start::Enter()
{
	// 맵 그리기
	Object* pObj = new Staduim;
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 + 110));
	pObj->SetScale(Vec2(0.7f, 0.7f));
	AddObject
    (pObj, GROUP_TYPE::MAP);

	// 사람들 생성
	for (int i = -200; i <= 200; i = i +=  100)
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

<<<<<<< HEAD
	// Object 추가
	Object* pPObj = new Player;
	pPObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
	pPObj->SetScale(Vec2(2.f,2.f));
	AddObject(pPObj, GROUP_TYPE::PLAYER);

	// 골키퍼 오브젝트
	Goalkeeper* goalkeeper = new Goalkeeper(30.f);
	goalkeeper->SetName(L"Goalkeeper");
	goalkeeper->SetFollower(pPObj);
	goalkeeper->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	goalkeeper->SetScale(Vec2(2.f, 2.f));
	AddObject(goalkeeper, GROUP_TYPE::AI);

	// 다이브 체크 콜라이더 오브젝트
	 DiveCollider* diveCol = new DiveCollider;
	diveCol->SetName(L"DiveCollider");
	diveCol->SetParent(goalkeeper);
	//diveCol->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2 - 100, (long)100));
	diveCol->SetScale(Vec2(1.f, 30.f));
	AddObject(diveCol, GROUP_TYPE::COLLIDER);
	goalkeeper->SetDiveCollider(diveCol); 

	pObj = new Ball;
	pObj->SetName(L"Ball"); 
	pObj->SetParent(pPObj);
	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2));
	pObj->SetScale(Vec2(2.5f,2.5f));
	AddObject(pObj, GROUP_TYPE::BALL);



//	Object* pOtherPlayer = new Player(*(Player*)pObj);
	/*Object* pOtherPlayer = pObj->Clone();
	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/
 

	// 충돌 지정
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::Goal);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BALL, GROUP_TYPE::AI);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::AI, GROUP_TYPE::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::COLLIDER, GROUP_TYPE::BALL);
=======

	pObj = new StartSceneText;
	AddObject(pObj, GROUP_TYPE::UI);
>>>>>>> KHJWork
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
