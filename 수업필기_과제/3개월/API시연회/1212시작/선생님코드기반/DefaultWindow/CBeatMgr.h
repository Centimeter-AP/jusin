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
};