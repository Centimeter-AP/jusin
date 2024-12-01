#pragma once	
#include "Monster.h"
class BMonster : public Monster
{
public:
	BMonster() : m_pBulletMon(nullptr), m_ullTick(0) {}
	BMonster(float _fAngle) : m_pBulletMon(nullptr), m_ullTick(0) { m_fAngle = _fAngle; }
	~BMonster() {}

public:
	void	Initialize();
	void	Render(HDC _hdc);

public:
	void	Set_BulletMon(list<Obj*>* _BulletList) { m_pBulletMon = _BulletList; }

private:
	list<Obj*>* m_pBulletMon;
	ULONGLONG	m_ullTick;
};

