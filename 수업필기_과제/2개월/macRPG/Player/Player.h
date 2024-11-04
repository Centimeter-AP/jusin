#pragma once
#ifndef PLAYER_H
# define PLAYER_H

# include "../Character/Character.h"
# include "../Info.h"
# include "../precom.h"

class CPlayer : public CCharacter
{
	private:
		PLAYERINFO	mPInfo;
	public:
		CPlayer();
		CPlayer(const char* szName, int _iHP, int _iAtk);
		~CPlayer();

		void	Initialize();
		void	Release();

		void	Print_Info();
};

#endif

