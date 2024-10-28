#pragma once
#ifndef MONSTER_H
# define MONSTER_H

# include "pch.h"
# include "CPlayer.h"

class CMonster
{
private:
	char	m_szName[32];
	int		m_iMaxHP;
	int		m_iHP;
	int		m_iAtk;
	int		m_iCritChance;
	int		m_iCritical;
	int		m_iExp;

public:
	CMonster();
	CMonster(const char* _szName, int _iMaxHP, int _iAtk);
	~CMonster();

	void	RenderInfo();
	int		Get_CritDamage();

	void	Initialize();
	void	Release();

	const char* Get_Name();
	int		Get_iHP();
	int		Get_iAtk();

	void Damaged(int _iDmg);
	void	Attack(CPlayer *Player);
};


#endif