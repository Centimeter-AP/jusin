#pragma once


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
	void		Set_BGMStart() { m_tBGMStart = chrono::system_clock::now(); }
	void		Set_TimeStart() { m_tTimeStart = chrono::system_clock::now(); }
	

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

	chrono::system_clock::time_point m_tBGMStart;
	chrono::system_clock::time_point m_tTimeStart;
	chrono::microseconds m_llTimeChecker;
};