#include "pch.h"
#include "CBeatMgr.h"
#include "Define.h"
#include "CObj.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;

using namespace std::chrono;

CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
	, m_bIsBeatMissed(true), m_bIsPlayerActed(false), m_bRightTimeBeat(false)
	, m_bAbleBeatInterval(false), m_iBeatGapFrameCount(0), m_fBeatJudgementPx(80.f)
{
	m_tTimerRightTime = m_tBeatStart = system_clock::now();
	m_tMusicStart = m_tBeatStart = system_clock::now();
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	// 결국 박자는 시간체크 말고 노트충돌처리로..
	// ... 시간체크로?
	++m_iBeatGapFrameCount;
	m_llTimeChecker = duration_cast<microseconds>(system_clock::now() - m_tBeatStart);
	if (m_llTimeChecker.count() >= STAGE1BPMSEC)
	{
		if (m_bRightTimeBeat == false)
		{
			m_tBeatStart += microseconds(STAGE1BPMSEC);
			m_tTimerRightTime = system_clock::now();
			m_bRightTimeBeat = true;
			m_fBeatJudgementPx = (float)m_iBeatGapFrameCount * 0.5f * 3.f;
			m_iBeatGapFrameCount = 0;
		}
	}
	if (duration_cast<milliseconds>(system_clock::now() - m_tTimerRightTime).count() > 80)
	{
		m_bRightTimeBeat = false;
	}

	if (m_bIsBeatMissed == true)
	{
		// true인 상태에서 beatbar삭제시 object 행동 true?
	}

	return 0;
}

void CBeatMgr::Late_Update()
{

	if(!m_BeatBarlist.empty())
	{
		if (m_BeatBarlist.front()->Get_Info().fX <= (float)WINCX * 0.5f + m_fBeatJudgementPx
			&& m_BeatBarlist.front()->Get_Info().fX >= (float)WINCX * 0.5f - m_fBeatJudgementPx)
		{
			m_bAbleBeatInterval = true;
		}
		else
		{
			m_bAbleBeatInterval = false;
		}
	}
}

void CBeatMgr::Render(HDC hDC)
{
	m_bIsBeatMissed = false;
	m_bIsPlayerActed = false;
	
	//TCHAR szText[32];
	//wsprintf(szText, L"m_iBeatGapFrameCount : %d ", m_iBeatGapFrameCount);
	//TextOut(hDC, 0, 0, szText, lstrlen(szText));
}

void CBeatMgr::Release()
{
}

void CBeatMgr::Set_Bar(CObj* _Bar)
{
	m_BeatBarlist.push_back(_Bar);
}

void CBeatMgr::Delete_Bar(CObj* _pBar)
{
	if (!m_BeatBarlist.empty())
	{
		auto iter = m_BeatBarlist.begin();
		for (iter = m_BeatBarlist.begin(); iter != m_BeatBarlist.end(); ++iter)
		{
			if ((*iter) == _pBar)
			{
				break;
			}
		}
		if (iter == m_BeatBarlist.end())
			return;
		iter = m_BeatBarlist.erase(iter);
	}
}

void CBeatMgr::Delete_Bar_Act()
{
	 //입력 가능한 박자일 때만 삭제되게 조건 추가할 것 
	//if (m_bAbleBeatInterval == true)
	{
		if (!m_BeatBarlist.empty())
		{
			m_BeatBarlist.front()->Set_Dead();
			m_BeatBarlist.pop_front();
			m_BeatBarlist.front()->Set_Dead();
			m_BeatBarlist.pop_front();
		}
	}
}
