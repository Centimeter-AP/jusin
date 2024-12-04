#include "pch.h"
#include "Player.h"
#include "Define.h"
#include "Bullet.h"
#include "RotBullet.h"
#include "AbFactory.h"
#include "SubPlayer.h"

void CPlayer::Initialize()
{
	mInfo = { 400, 500, 25, 25 };
	m_fSpeed = 5;
	m_fDistance = 30;
	m_iFireRate = 10;
	Set_Rect();
}

int CPlayer::Update()
{
	Get_KeyInput();
	__super::Set_Rect();

	return STAT_NOEVENT;
}

void CPlayer::Late_Update()
{
	GetCursorPos(&m_Mouse);
	ScreenToClient(g_hWnd, &m_Mouse);
	Set_Posin();
	for (auto& SP : *m_SubPlayer)
	{
		SP->Set_Pos(mInfo.fX, mInfo.fY);
	}
	++m_iDelay;
	//m_SubPlayer->back()->Set_Pos(mInfo.fX, mInfo.fY);
}

void CPlayer::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);

	MoveToEx(_hdc, (int)mInfo.fX, (int)mInfo.fY, nullptr);
	LineTo(_hdc, m_Posin.x, m_Posin.y);
}

void CPlayer::Release()
{

}
 
void CPlayer::Get_KeyInput()
{
	if (GetAsyncKeyState('W'))
	{
		if (GetAsyncKeyState('A'))
		{
			mInfo.fX -= m_fSpeed / sqrtf(2.0f);
			mInfo.fY -= m_fSpeed / sqrtf(2.0f);
			if (mInfo.fX < (WINCX + GAME_WINCX) / 2 - mInfo.fCX / 2)
				mInfo.fX = (WINCX + GAME_WINCX) / 2 - mInfo.fCX / 2;
		}
		else if (GetAsyncKeyState('D'))
		{
			mInfo.fX += m_fSpeed / sqrtf(2.0f);
			mInfo.fY -= m_fSpeed / sqrtf(2.0f);
		}
		else
			mInfo.fY -= m_fSpeed;
	}
	else if (GetAsyncKeyState('S'))
	{
		if (GetAsyncKeyState('A'))
		{
			mInfo.fX -= m_fSpeed / sqrtf(2.0f);
			mInfo.fY += m_fSpeed / sqrtf(2.0f);
		}
		else if (GetAsyncKeyState('D'))
		{
			mInfo.fX += m_fSpeed / sqrtf(2.0f);
			mInfo.fY += m_fSpeed / sqrtf(2.0f);
		}
		else
			mInfo.fY += m_fSpeed;
		enKeyDir = KDOWN;
	}
	else if (GetAsyncKeyState('A'))
	{
		mInfo.fX -= m_fSpeed;
		enKeyDir = KLEFT;
	}
	else if (GetAsyncKeyState('D'))
	{
		mInfo.fX += m_fSpeed;
		enKeyDir = KRIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (m_iDelay > m_iFireRate)
		{
			m_Bullet->push_back(CAbFactory<CBullet>::Create());
			m_Bullet->back()->Initialize();
			m_Bullet->back()->Set_Pos(m_Posin.x, m_Posin.y);
			m_Bullet->back()->Set_Angle(m_fAngle);
			m_iDelay = 0;
		}
	}
	if (GetAsyncKeyState('F'))
	{
		if (m_iDelay > m_iFireRate)
		{
			m_RotBullet->push_back(CAbFactory<CRotBullet>::Create());
			m_RotBullet->back()->Initialize();
			m_RotBullet->back()->Set_Pos(cosf(m_fAngle) * m_fDistance + mInfo.fX, sinf(m_fAngle) * m_fDistance + mInfo.fY);
			m_RotBullet->back()->Set_Angle(m_fAngle);
			m_iDelay = 0;
		}
	}
	if (GetAsyncKeyState(VK_UP))
	{
		--m_iFireRate;
		if (m_iFireRate < 0)
			m_iFireRate = 1;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		++m_iFireRate;
		if (m_iFireRate > 200)
			m_iFireRate = 200;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_iDelay > m_iFireRate)
		{
			++m_fSpeed;
			if (m_fSpeed > 30)
				m_fSpeed = 30;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		--m_fSpeed;
		if (m_fSpeed < 0)
			m_fSpeed = 1;
	}
}
//git
void CPlayer::Set_Posin()
{
	float fWidth  = m_Mouse.x - mInfo.fX;
	float fHeight = m_Mouse.y - mInfo.fY;
	float fDiagonal = sqrtf(SQUARE(fWidth) + SQUARE(fHeight));

	m_fAngle = acosf(fWidth / fDiagonal);
	if (fHeight < 0)
		m_fAngle = -m_fAngle;

	m_Posin.x = cosf(m_fAngle) * m_fDistance + mInfo.fX;
	m_Posin.y = sinf(m_fAngle) * m_fDistance + mInfo.fY;
}
