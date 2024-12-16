#include "pch.h"
#include "CBeatMgr.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;


CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
{
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	return 0;
}

void CBeatMgr::Late_Update()
{
}

void CBeatMgr::Render(HDC hDC)
{
}

void CBeatMgr::Release()
{
}
