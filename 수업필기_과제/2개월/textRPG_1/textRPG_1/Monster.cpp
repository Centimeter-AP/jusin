#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
{
	memset(&mInfo, 0, sizeof(mInfo));
	memset(&mMInfo, 0, sizeof(mMInfo));
}

CMonster::CMonster(string sName, int _iLvl)
{
	mInfo.sName = sName;
	mMInfo.iInitHP = (float)(50 + rand() % 10);
	mMInfo.iInitAtk = (float)(7 + rand() % 4);
	for (int i = 0; i < _iLvl; ++i) { mMInfo.iInitHP *= 1.1f; mMInfo.iInitAtk *= 1.1f; }
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
	cout << "이름 : " << mInfo.sName << endl;
	cout << "체력 : " << mInfo.iHP << "\t공격력 : " << mInfo.iAtk << endl;
	cout << "======================================================" << endl;
}