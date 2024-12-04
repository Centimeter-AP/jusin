#include "pch.h"
#include "Obj.h"

CObj::CObj() : m_fSpeed(0.f), m_fAngle(0.f), m_fDistance(0.f), enKeyDir(KUP), isDead(false)
{
	ZeroMemory(&mInfo, sizeof(INFO));
	ZeroMemory(&mRect, sizeof(RECT));
}

void CObj::Set_Rect()
{
	mRect.left = static_cast<LONG>(mInfo.fX - (mInfo.fCX / 2));
	mRect.top = static_cast<LONG>(mInfo.fY - (mInfo.fCX / 2));
	mRect.right = static_cast<LONG>(mInfo.fX + (mInfo.fCX / 2));
	mRect.bottom = static_cast<LONG>(mInfo.fY + (mInfo.fCX / 2));
}
