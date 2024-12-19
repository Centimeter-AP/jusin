#include "pch.h"
#include "CBeatMgr.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;


CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
	, m_bIsBeatMissed(true), m_bIsPlayerActed(false)
{
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	// 결국 박자는 시간체크 말고 노트충돌처리로..
	return 0;
}

void CBeatMgr::Late_Update()
{
}

void CBeatMgr::Render(HDC hDC)
{
	m_bIsBeatMissed = false;
	m_bIsPlayerActed = false;
}

void CBeatMgr::Release()
{
}
