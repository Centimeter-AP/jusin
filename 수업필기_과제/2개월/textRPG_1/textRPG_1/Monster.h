#pragma once
#ifndef MONSTER_H
# define MONSTER_H

# include "Character.h"
# include "Info.h"
# include "pch.h"

class CMonster : public CCharacter
{
private:
	MONSTERINFO mMInfo;
public:
	CMonster();
	CMonster(const char* szName, int _iLvl);
	~CMonster();

	void	Initialize();
	void	Release();

	void	Print_Info();

};

#endif

