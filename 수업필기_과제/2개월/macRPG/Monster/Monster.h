#pragma once
#ifndef MONSTER_H
# define MONSTER_H

# include "../Character/Character.h"
# include "../Info.h"
# include "../precom.h"

class CMonster : public CCharacter
{
	private:
		MONSTERINFO mMInfo;
	public:
		CMonster();
		~CMonster();
		void	Initialize();
		void	Release();

};

#endif


CMonster::CMonster()
{
	memset(&mInfo, 0, sizeof(mInfo));
	memset(&mMInfo, 0, sizeof(mMInfo));
}
CMonster::~CMonster()
{
	Release();
}

void	CMonster::Initialize()
{

}
void	CMonster::Release()
{}
