#include "pch.h"
#include "BMonster.h"
#include "MonBullet.h"

void BMonster::Initialize()
{
	m_ullTick = GetTickCount64();
	m_ullRate = 500;
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_fSpeed = 1.5f;

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

int BMonster::Update()
{
	if (m_bDead) {
		return OBJ_DEAD;
	}
	if (m_ullTick + m_ullRate <= GetTickCount64()) {
		Create_Bullet();
		m_ullTick = GetTickCount64();
	}
	//m_fSpeed += 0.0005f;

	float   fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	fRadian = acosf(fWidth / fDiagonal);

	m_fAngle = fRadian * (180.f / PI);

	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;

	// degree to radian
	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	Obj::Update_Rect();

	return OBJ_NOEVENT;
}
void BMonster::Render(HDC _hdc)
{
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 140, 140));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, myBrush);
	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	SelectObject(_hdc, oldBrush);
	DeleteObject(myBrush);
}

void BMonster::Create_Bullet()
{
	m_pBulletMon->push_back(new MonBullet(m_fAngle));
	m_pBulletMon->back()->Initialize();
	m_pBulletMon->back()->Set_Pos(float(m_tInfo.fX), float(m_tInfo.fY));

}