#include "pch.h"
#include "CBeatMgr.h"
#include "Define.h"
#include "CObj.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;

using namespace std::chrono;

CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
	, m_bIsBeatMissed(true), m_bIsPlayerActed(false), m_bRightTimeBeat(false)
	, m_bAbleBeatInterval(false)
{
	m_tTimerRightTime = m_tBeatStart = chrono::system_clock::now();
	m_tMusicStart = m_tBeatStart = chrono::system_clock::now();
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	// 결국 박자는 시간체크 말고 노트충돌처리로..
	// ... 시간체크로?
	m_llTimeChecker = duration_cast<microseconds>(chrono::system_clock::now() - m_tBeatStart);
	if (m_llTimeChecker.count() >= 521500)
	{
		if (m_bRightTimeBeat == false)
		{
			m_tBeatStart = chrono::system_clock::now();
			m_tTimerRightTime = chrono::system_clock::now();
			m_bRightTimeBeat = true;
			//m_bAbleBeatInterval = true;
		}
	}
	if (duration_cast<milliseconds>(chrono::system_clock::now() - m_tTimerRightTime).count() > 30)
	{
		m_bRightTimeBeat = false;
	}
	//if (duration_cast<milliseconds>(chrono::system_clock::now() - m_tTimerRightTime).count() > 260000)
	//{
	//	//m_bAbleBeatInterval = false;
	//}
	return 0;
}

void CBeatMgr::Late_Update()
{
	if(!m_BeatBarlist.empty())
	{
		if (m_BeatBarlist.front()->Get_Info().fX <= (float)WINCX * 0.5f + 80.f
			&& m_BeatBarlist.front()->Get_Info().fX >= (float)WINCX * 0.5f - 80.f)
		{
			m_bAbleBeatInterval = true;
		}
		else
		{
			m_bAbleBeatInterval = false;
		}
	}
	//double dTemp = (duration_cast<system_clock::duration>(m_tBeatStart - m_tMusicStart)).count() / (60.0 / (double)STAGE1BPM);
	//duration<double> dRes = duration<double>(dTemp - (double)((int)dTemp));

	//if (dTemp - (double)((int)dTemp) > 0.150)
	//{
	//	m_tBeatStart = system_clock::now() - duration_cast<system_clock::duration>(dRes);
	//	//auto temp = system_clock::now() - duration_cast<system_clock::duration>(dRes);
	//}
}

void CBeatMgr::Render(HDC hDC)
{
	m_bIsBeatMissed = false;
	m_bIsPlayerActed = false;
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
		//m_BeatBarlist.front()->Set_Dead();
		//m_BeatBarlist.pop_front();
	}

}

void CBeatMgr::Delete_Bar_Act()
{
	// 입력 가능한 박자일 때만 삭제되게 조건 추가할 것 
	if (m_bAbleBeatInterval == true)
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
