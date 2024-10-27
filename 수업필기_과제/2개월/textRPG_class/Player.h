#pragma once
#ifndef PLAYER_CPP
# define PLAYER_CPP

# include "Character.h"
# include "Monster.h"

class CPlayer : public CCharacter
{
	private:
		int m_iLvl;
		int m_iExp;
		int m_iMaxExp;
		int m_i;

	public:
		CPlayer();
		CPlayer(const char* _szName, int _iMaxHP, int _iAtk);
		~CPlayer();

		void	RenderInfo();

		void	Initialize();
		void	Update();
		void	Release();
};

#endif

