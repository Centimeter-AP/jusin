#pragma once

class CObj;
class CBeatMgr
{
private:
	CBeatMgr();
	~CBeatMgr();

public:
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

public:
	//bool		Check_PlayerMove();
	bool		Get_PlayerActed() { return m_bIsPlayerActed; }
	bool		Get_BeatMissed() { return m_bIsBeatMissed; }
	bool		Get_RightTimeBeat() { return m_bRightTimeBeat; }
	bool		Get_AbleBeatInterval() { return m_bAbleBeatInterval; }
	int			Get_BeatGapFrameCount() { return m_iBeatGapFrameCount; }
	float		Get_BeatJudgementPx() { return m_fBeatJudgementPx; }
	bool		Get_ObjectAbleToMove() { return m_bObjectAbleToMove; }
	int			Get_BeatCombo() { return m_iBeatCombo; }

	void		Set_BeatCombo(int _Combo) { m_iBeatCombo = _Combo; }
	void		Set_ObjectAbleToMove(bool _Able) { m_bObjectAbleToMove = _Able; }
	void		Set_PlayerActed(bool _bAct) { m_bIsPlayerActed = _bAct; }
	void		Set_BeatMissed(bool _bMiss) { m_bIsBeatMissed = _bMiss; }
	void		Set_AbleBeatInterrval(bool _Able) { m_bAbleBeatInterval = _Able; }
	void		Set_BeatStart() { m_tBeatStart = chrono::system_clock::now(); }
	void		Set_TimeStart() { m_tTimerRightTime = chrono::system_clock::now(); }
	void		Set_MusicStart() { m_tMusicStart = chrono::system_clock::now(); m_tBeatStart = m_tMusicStart; }

	void		Set_Bar(CObj* _Bar);
	void		Delete_Bar(CObj* _Bar);
	void		Delete_Bar_Act();
	void		Plus_BeatCombo() { ++m_iBeatCombo; if (m_iBeatCombo > 3) m_iBeatCombo = 3; }

public:
	static CBeatMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CBeatMgr;

		return m_pInstance;
	}

	static void	Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CBeatMgr* m_pInstance;
	
	ULONGLONG	m_ullTimeChecker;
	ULONGLONG	m_ullTimeTicker;

	bool		m_bIsPlayerActed;
	bool		m_bIsBeatMissed;
	bool		m_bRightTimeBeat;
	bool		m_bAbleBeatInterval;

	bool		m_bObjectAbleToMove;

	chrono::system_clock::time_point m_tBeatStart;
	chrono::system_clock::time_point m_tTimerRightTime;
	chrono::system_clock::time_point m_tMusicStart;
	chrono::microseconds m_llTimeChecker;

	list<CObj*> m_BeatBarlist;

	int			m_iBeatGapFrameCount;
	float		m_fBeatJudgementPx;

	int			m_iBeatCombo;
};