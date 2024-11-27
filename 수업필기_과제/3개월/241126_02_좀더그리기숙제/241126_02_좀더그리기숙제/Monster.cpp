#include "pch.h"
#include "Monster.h"

void CMonster::Update()
{
	if (false == isWall)
	{
		if (mInfo.fX < WINCX - 125)
			mInfo.fX += m_lSpeed;
		else
			isWall = true;
	}
	else
	{
		if (mInfo.fX > 125)
			mInfo.fX -= m_lSpeed;
		else
			isWall = false;
	}

	Set_Rect();
}

void CMonster::Render(HDC _hdc)
{
	Rectangle(_hdc, mRect.left, mRect.top, mRect.right, mRect.bottom);
}

void CMonster::Initialize()
{
	mInfo = { 125, 150, 50, 50 };
	Set_Rect();
	m_lSpeed = 5;
}

void CMonster::Release()
{
}
