#include "pch.h"
#include "Player.h"
#include "Bullet.h"

void CPlayer::Update()
{
	Get_KeyInput();
	Set_Rect();
}

void CPlayer::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CPlayer::Initialize()
{
	mInfo = { 400, 300, 50, 50 };
	Set_Rect();
	m_lSpeed = 10;
}

void CPlayer::Release()
{
}

void CPlayer::Get_KeyInput()
{
	if (GetAsyncKeyState('W'))
	{
		mInfo.fY -= m_lSpeed;
		enKeyDir = KUP;
	}
	if (GetAsyncKeyState('A'))
	{
		mInfo.fX -= m_lSpeed;
		enKeyDir = KLEFT;
	}
	if (GetAsyncKeyState('S'))
	{
		mInfo.fY += m_lSpeed;
		enKeyDir = KDOWN;
	}
	if (GetAsyncKeyState('D'))
	{
		mInfo.fX += m_lSpeed;
		enKeyDir = KRIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Make_Bullet());
	}
}

CObj* CPlayer::Make_Bullet()
{
	CObj* res = new CBullet;
	res->Initialize();
	res->Set_Pos(mInfo.fX, mInfo.fY);
	res->Set_Dir(enKeyDir);
	return res;
}
