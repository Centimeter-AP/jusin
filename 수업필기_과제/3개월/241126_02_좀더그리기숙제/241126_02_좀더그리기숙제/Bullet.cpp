#include "pch.h"
#include "Bullet.h"

void CBullet::Update()
{
	switch (enKeyDir)
	{
	case KUP:
		mInfo.fY -= m_lSpeed;
		break;
	case KDOWN:
		mInfo.fY += m_lSpeed;
		break;
	case KLEFT:
		mInfo.fX -= m_lSpeed;
		break;
	case KRIGHT:
		mInfo.fX += m_lSpeed;
		break;
	}
	Set_Rect();
}

void CBullet::Render(HDC _hdc)
{
	Ellipse(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CBullet::Initialize()
{
	mInfo.fCX = mInfo.fCY = 20.f;
	m_lSpeed = 10;
}

void CBullet::Release()
{
}

void CBullet::Late_Update()
{
}
