#pragma once
#ifndef PLAYER_CPP
# define PLAYER_CPP

# include "pch.h"
# include "CMonster.h"
class CPlayer
{
private:
	char	m_szName[32];
	int		m_iMaxHP;
	int		m_iHP;
	int		m_iAtk;
	int		m_iCritChance;
	int		m_iCritical;
	int		m_iLvl;
	int		m_iExp;
	int		m_iMaxExp;

public:
	CPlayer();
	CPlayer(const char* _szName, int _iMaxHP, int _iAtk);
	~CPlayer();

	void	RenderInfo();

	void	Initialize();
	void	Release();

	void	Set_FullHP();
	void	Set_iHP(int _iHP);
	void	Set_iExp(int _iExp);
	const char* Get_Name();
	int		Get_iHP();


	void	Attack(CMonster* Monster);
	int		Get_CritDamage();
	void	Damaged(int _iDmg);
};

#endif
