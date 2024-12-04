#pragma once
#include "Obj.h"
#include "Define.h"

class CMainGame
{
public:
	CMainGame() {}
	~CMainGame() {}
public:
	void	Initialize();
	void	Update();
	void	Late_Update();
	void	Render();
	void	Release();

private:
	HDC			m_hdc;
	list<CObj*>	m_ObjList[OBJ_END];
};

