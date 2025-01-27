#pragma once
//#include "Box.h" // �� �� ����
#include "Block.h"

class CBlockMgr
{
private:
	CBlockMgr();
	~CBlockMgr();

public:
	//bool	Collision_Box(float _fX, float* pY);

public:
	void	Initialize();
	int		Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();

	void	Save_Block();
	void	Load_Block();
	void	Load_Block(LPCWSTR _FilePath);


public:
	static CBlockMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CBlockMgr;

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
	static CBlockMgr*		m_pInstance;
	list<CObj*>				m_BlockList;
	POINT					m_tBlockPoint[DRAWPOINT_END];
	float					m_fBlockSize;
	DRAWDIR					m_eDrawDir;
	list<int>				m_iUndo_Stack;
	int						m_iWidth;
	int						m_iHeight;
};

