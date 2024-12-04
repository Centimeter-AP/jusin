#include "pch.h"
#include "Monster.h"
#include "Define.h"

int	 CMonster::Update()
{
	if (isDead)
		return STAT_DEAD;
	else
	{
		if (false == isWall)
		{
			if (mInfo.fX < (WINCX + GAME_WINCX) / 2 - mInfo.fCX / 2)
				mInfo.fX += m_fSpeed;
			else
				isWall = true;
		}
		else
		{
			if (mInfo.fX > (WINCX - GAME_WINCX) / 2 + mInfo.fCX / 2)
				mInfo.fX -= m_fSpeed;
			else
				isWall = false;
		}
		//mInfo.fX += m_fSpeed;
		mInfo.fY += m_fSpeed * 0.1f * (rand() % 10);
		Set_Rect();
		return STAT_NOEVENT;
	}
}

void CMonster::Late_Update()
{
	/*if ((WINCX - GAME_WINCX) / 2 >= mRect.left ||
		(WINCX + GAME_WINCX) / 2 <= mRect.right ||
		(WINCY - GAME_WINCY) / 2 >= mRect.top ||
		(WINCY + GAME_WINCY) / 2 <= mRect.bottom)
		m_fSpeed *= -1.f;*/
}

void CMonster::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CMonster::Initialize()
{
	mInfo.fX = (WINCX - GAME_WINCX) / 2 + rand() % GAME_WINCX;
	mInfo.fY = WINCY - GAME_WINCY + rand() % 100;
	mInfo.fCX = 30;
	mInfo.fCY = 30;
	Set_Rect();
	m_fSpeed = 3 + rand()%4;
}

void CMonster::Release()
{

}
