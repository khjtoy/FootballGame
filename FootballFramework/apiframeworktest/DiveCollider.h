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
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void Render(HDC _dc) override;
	CLONE(DiveCollider); 
	void EnterCollision(Collider* collider) override; 
	void ExitCollision(Collider* collider) override; 
public:
	bool GetIsCollision() { return m_isCollision; } // ���� �浹�ߴ°� 
	Ball* GetTarget() { return m_target; }
};

