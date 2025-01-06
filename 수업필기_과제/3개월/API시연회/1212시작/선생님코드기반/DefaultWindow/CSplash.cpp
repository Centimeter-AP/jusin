#include "pch.h"
#include "CSplash.h"
#include "Define.h"


void CSplash::Initialize()
{
	m_tInfo.fCX = m_tInfo.fCY = 48.f;
	
}

int CSplash::Update()
{
	return OBJ_NOEVENT;
}

void CSplash::Late_Update()
{
}

void CSplash::Render(HDC hDC)
{
}

void CSplash::Release()
{
}
