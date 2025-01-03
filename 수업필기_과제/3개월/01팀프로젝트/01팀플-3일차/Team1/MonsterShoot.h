#pragma once
#include "Monster.h"

class MonsterShoot : public Monster
{
public:
	MonsterShoot();
	virtual ~MonsterShoot();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _hdc) override;
	virtual void Release() override;

protected:
	list<Obj*>* m_pBulletList;

public:
	virtual void        Set_Bullet(list<Obj*>* pBullet) { m_pBulletList = pBullet; }
	virtual void		Shoot();
};

