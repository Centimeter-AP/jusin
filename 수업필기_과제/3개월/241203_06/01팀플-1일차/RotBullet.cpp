#include "pch.h"
#include "RotBullet.h"

int CRotBullet::Update()
{
	if (isDead)
		return STAT_DEAD;
	m_fBulletAngle -= 30.f;
	mInfo.fX = long(cosf(m_fBulletAngle * (PI / 180.f)) * m_fDistance + mInfo.fX);
	mInfo.fY = long(sinf(m_fBulletAngle * (PI / 180.f)) * m_fDistance + mInfo.fY);
	mInfo.fX += m_fSpeed * cosf(m_fAngle);
	mInfo.fY += m_fSpeed * sinf(m_fAngle);
	Set_Rect();
	return STAT_NOEVENT;
}

void CRotBullet::Late_Update()
{
	if ((WINCX - GAME_WINCX) / 2 >= mRect.left ||
		(WINCX + GAME_WINCX) / 2 <= mRect.right ||
		(WINCY - GAME_WINCY) / 2 >= mRect.top ||
		(WINCY + GAME_WINCY) / 2 <= mRect.bottom)
	{
		isDead = true;
	}
}

void CRotBullet::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CRotBullet::Initialize()
{
	mInfo.fCX = mInfo.fCY = 20.f;
	m_fSpeed = 5;
	m_fDistance = 10;
	m_fBulletAngle = 0;
}

void CRotBullet::Release()
{
}

void CRotBullet::Set_MyRect()
{
	m_MyRect.left   = static_cast<LONG>(m_MyPos.x - (mInfo.fCX / 2));
	m_MyRect.top    = static_cast<LONG>(m_MyPos.y - (mInfo.fCX / 2));
	m_MyRect.right  = static_cast<LONG>(m_MyPos.x + (mInfo.fCX / 2));
	m_MyRect.bottom = static_cast<LONG>(m_MyPos.y + (mInfo.fCX / 2));
}
