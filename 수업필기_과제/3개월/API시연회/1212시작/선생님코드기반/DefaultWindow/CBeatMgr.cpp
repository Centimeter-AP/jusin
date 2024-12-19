#include "pch.h"
#include "CBeatMgr.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;


CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
	, m_bIsBeatMissed(true), m_bIsPlayerActed(false), m_bRightTimeBeat(false)
{
	m_tTimeStart = m_tBGMStart = chrono::system_clock::now();
	
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	// 결국 박자는 시간체크 말고 노트충돌처리로..
	// ... 시간체크로?
	m_llTimeChecker = std::chrono::duration_cast<std::chrono::microseconds>(chrono::system_clock::now() - m_tBGMStart);
	if (m_llTimeChecker.count() >= 522000)
	{
		if (m_bRightTimeBeat == false)
		{
			m_tBGMStart = chrono::system_clock::now();
			m_tTimeStart = chrono::system_clock::now();
			m_bRightTimeBeat = true;
		}
	}
	if (std::chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now() - m_tTimeStart).count() > 100)
	{
		m_bRightTimeBeat = false;
	}
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
