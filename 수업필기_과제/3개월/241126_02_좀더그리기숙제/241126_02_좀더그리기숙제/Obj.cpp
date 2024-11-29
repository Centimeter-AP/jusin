#include "pch.h"
#include "Obj.h"


void CObj::Set_Rect()
{
	mRect.left   = static_cast<LONG>(mInfo.fX - (mInfo.fCX / 2));
	mRect.top    = static_cast<LONG>(mInfo.fY - (mInfo.fCX / 2));
	mRect.right  = static_cast<LONG>(mInfo.fX + (mInfo.fCX / 2));
	mRect.bottom = static_cast<LONG>(mInfo.fY + (mInfo.fCX / 2));
}
