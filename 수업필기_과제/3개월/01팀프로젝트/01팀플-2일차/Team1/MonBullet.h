#pragma once
#include "Bullet.h"
class MonBullet : public Bullet
{
public:
	MonBullet() {}
	MonBullet(float _Angle) { m_fAngle = _Angle; }
	~MonBullet() {}
public:
	void Initialize() override;
	int Update() override;
};

