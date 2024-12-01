#include "pch.h"
#include "BMonster.h"

void BMonster::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_fSpeed = 2.f;

	m_iHp = 30;
	m_iDamage = 1;

	m_iDir = rand() % 4;
	int iXorY = 0;

	switch (m_iDir)
	{
	case LEFT:
		iXorY = rand() % int(GAME_WINCY + GAME_WIN_TOP);
		m_tInfo.fX = int(GAME_WIN_LEFT) + m_tInfo.fCX;
		m_tInfo.fY = (float)iXorY;
		break;
	case TOP:
		iXorY = rand() % int(GAME_WINCX + GAME_WIN_LEFT);
		m_tInfo.fY = int(GAME_WIN_TOP) + m_tInfo.fCY;
		m_tInfo.fX = (float)iXorY;
		break;
	case RIGHT:
		iXorY = rand() % int(GAME_WINCY + GAME_WIN_TOP);
		m_tInfo.fX = int(GAME_WIN_RIGHT) - m_tInfo.fCX;
		m_tInfo.fY = (float)iXorY;
		break;
	case BOTTOM:
		iXorY = rand() % int(GAME_WINCX + GAME_WIN_LEFT);
		m_tInfo.fY = int(GAME_WIN_BOTTOM) - m_tInfo.fCY;
		m_tInfo.fX = (float)iXorY;
		break;
	case NODIR:
		break;
	default:
		break;
	}
}
void BMonster::Render(HDC _hdc)
{
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 140, 140));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, myBrush);
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(_hdc, oldBrush);
	DeleteObject(myBrush);
}
