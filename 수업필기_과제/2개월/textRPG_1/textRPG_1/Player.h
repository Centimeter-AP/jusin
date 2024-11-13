#pragma once
#ifndef PLAYER_H
# define PLAYER_H

# include "Character.h"
# include "Info.h"
# include "pch.h"

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

	PLAYERINFO* Get_PInfo() { return &mPInfo; };

	void	Level_Up();
	void	Player_Lose();
	void	Player_Win();

	void	Print_Info();
};

#endif
