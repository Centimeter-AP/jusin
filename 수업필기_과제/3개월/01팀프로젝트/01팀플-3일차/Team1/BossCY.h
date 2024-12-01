#pragma once
#include "MonsterShoot.h"
class BossCY : public MonsterShoot
{
public:
	BossCY() {}
	~BossCY() {}
public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC _hdc) override;
	virtual void	Release() override;

public:
	virtual void    Set_Bullet(list<Obj*>* pBullet) { m_pBulletList = pBullet; }
	virtual void	Shoot();

private:
	void			RandomPattern1();
	void			RandomPattern2();
	void			RandomPattern3();

private:
	enum BOSSMOVE	{ MOVEPAT1, MOVEPAT2, MOVEPAT3, MOVEPAT4, MOVEPATEND };
	bool			m_bMovingPattern[MOVEPATEND];
};

