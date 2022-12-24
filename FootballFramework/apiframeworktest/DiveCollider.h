#pragma once
#include "Object.h"
#include "Ball.h"
class DiveCollider : public Object
{
private:
	bool m_isCollision; 
	Ball* m_target; 
public:
	DiveCollider(); 
	~DiveCollider(); 
public:
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(DiveCollider); 
	void EnterCollision(Collider* collider) override; 
	void ExitCollision(Collider* collider) override; 
public:
	bool GetIsCollision() { return m_isCollision; } // 공과 충돌했는가 
	Ball* GetTarget() { return m_target; }
};

