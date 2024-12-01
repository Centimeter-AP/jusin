#include "pch.h"
#include "BulletCY.h"

void BulletCY::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 5.f;
	m_iHp = 1;
	m_iDamage = 10;

	m_fRotAngle = 0.f;
	m_fRotSpeed = 3.f;
	m_fDistance = 100.f;

	m_bStart = true;

}

int BulletCY::Update()
{
	if (m_bDead) {
		return OBJ_DEAD;
	}
	//m_enType = PATSCREW;

	switch (m_enType)
	{
	case BulletCY::PATCIRCLE:
		CirclePattern();
		break;
	case BulletCY::PATSIDE:
		SidePattern();
		break;
	case BulletCY::PATROTATE:
		RotatePattern();
		break;
	case BulletCY::PATSCREW:
		ScrewPattern();
		break;
	default:
		break;
	}

	//m_tInfo.fX = float(m_tInfo.fX + (m_fSpeed * cosf(m_fAngle * (PI / 180.f))));
	//m_tInfo.fY = float(m_tInfo.fY - (m_fSpeed * sinf(m_fAngle * (PI / 180.f))));

	Obj::Update_Rect();
	return OBJ_NOEVENT;
}

void BulletCY::CirclePattern()
{
}

void BulletCY::SidePattern()
{
}

void BulletCY::RotatePattern()
{
}

void BulletCY::ScrewPattern()
{
	m_fSpeed = 3.f;

	if (m_bStart)
	{
		m_tCenter.x = (long)m_tInfo.fX;
		m_tCenter.y = (long)m_tInfo.fY;
		m_bStart = false;
	}

	m_tCenter.x += long(m_fSpeed * cosf(m_fAngle * (PI / 180.f)));
	m_tCenter.y -= long(m_fSpeed * sinf(m_fAngle * (PI / 180.f)));

	m_fRotAngle += m_fRotSpeed;

	m_tInfo.fX = m_tCenter.x + (m_fDistance * cosf(m_fRotAngle * (PI / 180.f)));
	m_tInfo.fY = m_tCenter.y - (m_fDistance * sinf(m_fRotAngle * (PI / 180.f)));
}
