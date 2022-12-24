#include "pch.h"
#include "DiveCollider.h"
#include "Collider.h"
#include "Ball.h"

DiveCollider::DiveCollider()
	:m_isCollision(false)
	, m_target(nullptr)
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(200.f, 60.f));
	GetCollider()->SetOffsetPos(Vec2(-8.f, 0.f));

}

DiveCollider::~DiveCollider()
{
	//if (m_target != nullptr)
	//	delete m_target; 
}

void DiveCollider::Update()
{
	SetPos(Vec2(0, 0));
}

void DiveCollider::Render(HDC _dc)
{
	Component_Render(_dc); 
}

void DiveCollider::EnterCollision(Collider* collider)
{
		Object* target = collider->GetObj(); 
		if (target->GetName() == L"Ball")// 공과 충돌했다면 
		{
			m_target = (Ball*) target; // 타겟 설정
			m_isCollision = true;  // 충돌 했다 
		}
}

void DiveCollider::ExitCollision(Collider* collider)
{
	m_isCollision = false; 
}
