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
	void		Set_PlayerActed(bool _bAct) { m_bIsPlayerActed = _bAct; }
	void		Set_BeatMissed(bool _bMiss) { m_bIsBeatMissed = _bMiss; }
	void		Set_BeatStart() { m_tBeatStart = chrono::system_clock::now(); }
	void		Set_TimeStart() { m_tTimerRightTime = chrono::system_clock::now(); }
	void		Set_MusicStart() { m_tMusicStart = chrono::system_clock::now(); m_tBeatStart = m_tMusicStart; }
	void		Set_RBar(CObj* _RBar);
	void		Set_LBar(CObj* _LBar);
	void		Set_Bar(CObj* _Bar);
	void		Delete_Bar(CObj* _Bar);
	void		Delete_Bar_Act();

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

	chrono::system_clock::time_point m_tBeatStart;
	chrono::system_clock::time_point m_tTimerRightTime;
	chrono::system_clock::time_point m_tMusicStart;
	chrono::microseconds m_llTimeChecker;

	list<CObj*> m_LBeatBarlist;
	list<CObj*> m_RBeatBarlist;
	list<CObj*> m_BeatBarlist;
};