#include "textrpg.h"


void	Print_Info(INFO	*_tInfo)
{
	cout << "============================" << endl;
	cout << "이름 : " << _tInfo->sName << endl;
	cout << "체력 : " << _tInfo->iHp << "  \t공격력 : " << _tInfo->iAtk << endl;
}

void	Attack(INFO *_tClass, INFO *_tEnemy)
{
	int iCritical(1);
	rand() % 100 > _tClass->iCritChance ? iCritical = 1 : iCritical = 2;
	_tEnemy->iHp -= _tClass->iAtk * iCritical;
	if (iCritical == 2){
		cout << _tClass->sName << "의 크리티컬 히트!" << endl; sleep(1);}
	rand() % 100 > _tEnemy->iCritChance ? iCritical = 1 : iCritical = 2;
	_tClass->iHp -= _tEnemy->iAtk * iCritical;
	if (iCritical == 2){
		cout << _tEnemy->sName << "의 크리티컬 히트!" << endl; sleep(1);}
}

void	Make_Hp_Full(INFO *_tClass)
{
	cout << "HP가 최대로 회복되었습니다. " << endl;
	_tClass->iHp = _tClass->iMaxHp;
	sleep(1);
}
