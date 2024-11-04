#pragma once

#include "CPlayer.h"
#include "CMonster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void		Set_Player(CObj* pPlayer){ m_pCopyPlayer = pPlayer; }

public:
	void		Initialize();
	void		Update();
	void		Release();

private:
	int			Fight();

private:
	CObj*	m_pCopyPlayer;
	CObj*	m_pMonster;
};

