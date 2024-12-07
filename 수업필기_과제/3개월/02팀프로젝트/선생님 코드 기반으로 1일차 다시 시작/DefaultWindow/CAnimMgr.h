#pragma once
class CAnimMgr
{
private:
	CAnimMgr();
	~CAnimMgr() { Release(); }

public:
	void	Render(HDC _hDc, const TCHAR* _pImgKey);
	void	Release();

public:
	static CAnimMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CAnimMgr;

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
	static	CAnimMgr* m_pInstance;

};

