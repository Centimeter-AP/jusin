#include "pch.h"
#include "MonBullet.h"


void MonBullet::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 10.f;
	m_iHp = 1;
	m_iDamage = 10;
}

int MonBullet::Update()
{
	if (m_bDead) {
		return OBJ_DEAD;
	}

	m_tInfo.fX = float(m_tInfo.fX + (m_fSpeed * cosf(m_fAngle * (PI / 180.f))));
	m_tInfo.fY = float(m_tInfo.fY - (m_fSpeed * sinf(m_fAngle * (PI / 180.f))));

	Obj::Update_Rect();
	return OBJ_NOEVENT;
}

