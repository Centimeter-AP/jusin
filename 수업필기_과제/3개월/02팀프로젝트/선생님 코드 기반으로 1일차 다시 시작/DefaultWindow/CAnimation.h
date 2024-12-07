#pragma once
#include "Define.h"


class CAnimation
{
public:
	CAnimation() { ZeroMemory(&m_tAnInfo, sizeof(m_tAnInfo)); }
	~CAnimation() { Release(); }

public:
	void	Update();
	void	Late_Update();
	void	Initialize();
	void	Render();
	void	Release();

public:
	//ANINFO	Get_AnInfo() const { return m_tAnInfo; };
	void	Create_Animation();


private:
	vector<ANINFO>	m_tAnInfo;
};

