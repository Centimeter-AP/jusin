#include "pch.h"
#include "SubPlayer.h"
#include "Define.h"

int CSubPlayer::Update()
{
	m_fAngle += 5;
	//__super::Set_Rect();
	m_MyPos.x = long(cosf(m_fAngle * (PI / 180.f)) * m_fDistance + mInfo.fX);
	m_MyPos.y = long(sinf(m_fAngle * (PI / 180.f)) * m_fDistance + mInfo.fY);
	Set_MyRect();
	return STAT_NOEVENT;
}

void CSubPlayer::Late_Update()
{
	/*if (GetAsyncKeyState(VK_SPACE))
	{
		m_Bullet->push_back(CAbFactory<CBullet>::Create());
		m_Bullet->back()->Initialize();
		m_Bullet->back()->Set_Pos(m_Posin.x, m_Posin.y);
		m_Bullet->back()->Set_Angle(m_fAngle);
	}*/
}

void CSubPlayer::Render(HDC _hdc)
{
    Rectangle(_hdc, m_MyRect.left, m_MyRect.top, m_MyRect.right, m_MyRect.bottom);
}

void CSubPlayer::Initialize()
{
	mInfo.fCX = 15;
	mInfo.fCY = 15;
	//m_fSpeed = 1;
	m_fDistance = 50;
}

void CSubPlayer::Release()
{
}

void CSubPlayer::Get_KeyInput()
{
	
}

void CSubPlayer::Set_MyRect()
{
	m_MyRect.left   = static_cast<LONG>(m_MyPos.x - (mInfo.fCX / 2));
	m_MyRect.top    = static_cast<LONG>(m_MyPos.y - (mInfo.fCX / 2));
	m_MyRect.right  = static_cast<LONG>(m_MyPos.x + (mInfo.fCX / 2));
	m_MyRect.bottom = static_cast<LONG>(m_MyPos.y + (mInfo.fCX / 2));
}
