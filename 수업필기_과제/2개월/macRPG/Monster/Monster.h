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

		void	Print_Info();

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
void 	CMonster::Print_Info()
{
	cout << "======================================================" << endl;
	cout << "이름 : " << mInfo.szName << endl;
	cout << "체력 : " << mInfo.iHP << "\t공격력 : " << mInfo.iAtk << endl;
}