#pragma once

#include "CLine.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	bool	Collision_Line(float _fX, float* pY);
	bool	isClose(float _Dst, float _Src, float ep = 0.1f);

public:
	void	Initialize();
	void	Render(HDC hDC);
	void	Release();

public:
	static CLineMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CLineMgr;

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
	static CLineMgr*		m_pInstance;

	list<CLine*>			m_Linelist;
};

