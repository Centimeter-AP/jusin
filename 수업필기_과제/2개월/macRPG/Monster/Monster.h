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
		CMonster(const char* szName, int _iLvl);
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

CMonster::CMonster(const char* szName, int _iLvl)
{
	strcpy(mInfo.szName, szName);

	mMInfo.iInitHP = 50 + rand() % 10;
	mMInfo.iInitAtk = 7 + rand() % 4;
	for (int i = 0; i < _iLvl; ++i){ mMInfo.iInitHP *= 1.1f; mMInfo.iInitAtk *= 1.1f; }
	mInfo.iMaxHP = (int)(mMInfo.iInitHP);
	mInfo.iHP = mInfo.iMaxHP;
	mInfo.iAtk = (int)(mMInfo.iInitAtk);
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100;
	mMInfo.iLvl = _iLvl;
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
	cout << "======================================================" << endl;
}