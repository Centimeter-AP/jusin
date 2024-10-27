#pragma once
#ifndef CHARACTER_CPP
# define CHARACTER_CPP

# include "pch.h"

class CCharacter
{
	protected:
		char	m_szName[32];
		int		m_iMaxHP;
		int		m_iHP;
		int		m_iAtk;
		int		m_iCritChance;

	public:
		CCharacter();
		CCharacter(const char* _szName, int _iAtk, int _iMaxHP);
		virtual ~CCharacter();

		void	PrintInfo();
		int		Get_CritDamage();
		void	Damaged(int _iDmg);
		void	Initialize();
		void	Update();
		void	Release();

};

#endif
