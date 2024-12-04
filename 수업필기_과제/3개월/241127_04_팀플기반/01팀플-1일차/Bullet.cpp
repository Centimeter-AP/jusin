#include "pch.h"
#include "Bullet.h"
#include "Define.h"

int CBullet::Update()
{
	if (isDead)
		return STAT_DEAD;
	mInfo.fX += m_fSpeed * cosf(m_fAngle);
	mInfo.fY += m_fSpeed * sinf(m_fAngle);

	Set_Rect();
	return STAT_NOEVENT;
}

void CBullet::Late_Update()
{
	if ((WINCX - GAME_WINCX) /2 >= mRect.left   ||
		(WINCX + GAME_WINCX) / 2 <= mRect.right	||
		(WINCY - GAME_WINCY) / 2 >= mRect.top   ||
		(WINCY + GAME_WINCY) / 2 <= mRect.bottom)
	{
		isDead = true;
	}
}

void CBullet::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CBullet::Initialize()
{
	mInfo.fCX = mInfo.fCY = 20.f;
	m_fSpeed = 10;
}

void CBullet::Release()
{
}
