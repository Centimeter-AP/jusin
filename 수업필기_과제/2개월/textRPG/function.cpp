#include "textrpg.h"


void	Print_Info(INFO	*_tInfo)
{
	cout << "============================" << endl;
	cout << "이름 : " << _tInfo->sName << endl;
	cout << "체력 : " << _tInfo->iHp << "  \t공격력 : " << _tInfo->iAtk << endl;
	if (_tInfo->isMob == false)
		cout << "레벨 : " << _tInfo->tPlayerInfo.iLvl << "  \t다음 레벨까지 : " << (_tInfo->tPlayerInfo.iMaxExp - _tInfo->tPlayerInfo.iExp) << endl;
}

void	Attack(INFO *_tClass, INFO *_tEnemy)
{
	int iCritical(1);
	rand() % 100 > _tClass->iCritChance ? iCritical = 1 : iCritical = 2;
	_tEnemy->iHp -= _tClass->iAtk * iCritical;
	if (iCritical == 2){
		cout << _tClass->sName << "의 크리티컬 히트!" << endl; sleep(1);}
	cout << _tEnemy->sName << "에게 " << _tClass->iAtk * iCritical << " 대미지" << endl;
	sleep(1);
	if (_tEnemy->iHp <= 0)
		return ;
	rand() % 100 > _tEnemy->iCritChance ? iCritical = 1 : iCritical = 2;
	_tClass->iHp -= _tEnemy->iAtk * iCritical;
	if (iCritical == 2){
		cout << _tEnemy->sName << "의 크리티컬 히트!" << endl; sleep(1);}
	cout << _tClass->sName << "에게 " << _tEnemy->iAtk * iCritical << " 대미지" << endl;
	sleep(1);
}

void	Heal_Hp(INFO *_tClass, int _iValue)
{
	switch (_iValue)
	{
	case HPMAX:
		cout << "HP가 최대로 회복되었습니다. " << endl;
		_tClass->iHp = _tClass->iMaxHp;
		sleep(1);
		break;

	case HPEIGHTYP:
		cout << "최대 HP의 80%가 회복되었습니다. " << endl;
		(_tClass->iHp + _tClass->iMaxHp / 5 * 4 > _tClass->iMaxHp)\
		? (_tClass->iHp = _tClass->iMaxHp) : (_tClass->iHp += _tClass->iMaxHp / 5 * 4);
		sleep(1);
		break;
	
	case HPHALF:
		cout << "최대 HP의 절반이 회복되었습니다." << endl;
		(_tClass->iHp + _tClass->iMaxHp / 2 > _tClass->iMaxHp)\
		? (_tClass->iHp = _tClass->iMaxHp) : (_tClass->iHp += _tClass->iMaxHp / 2);
		sleep(1);
		break;

	case HPFOURTYP:
		cout << "최대 HP의 40%가 회복되었습니다." << endl;
		(_tClass->iHp + _tClass->iMaxHp / 5 * 2 > _tClass->iMaxHp)\
		? (_tClass->iHp = _tClass->iMaxHp) : (_tClass->iHp += _tClass->iMaxHp / 5 * 2);
		sleep(1);
		break;

	case HPTWENTYP:
		cout << "최대 HP의 20%가 회복되었습니다." << endl;
		(_tClass->iHp + _tClass->iMaxHp / 5 > _tClass->iMaxHp)\
		? (_tClass->iHp = _tClass->iMaxHp) : (_tClass->iHp += _tClass->iMaxHp / 5);
		sleep(1);
		break;

	case HPZEROP:
		cout << "회복하지 못했습니다..." << endl;
		sleep(1);
		break;

		
	default:
		cout << "\n!!회복 비율에 문제 있음!!\n" << endl;
		sleep(10);
		break;
	}
	
}

void	imsi()
{
	void;
}

void	Healing_Station(INFO *_tClass)
{
	int	iInput(0), iRand(10);

	while(1)
	{
		system("clear");
		Print_Info(_tClass);
		cout << "============================" << endl;
		cout << "잘 찾아보면 휴식처를 발견할 수 있을 것 같다.\n" << endl;
		cout << "1. 그냥 쉰다 (최대 HP의 20%가 회복된다)" << endl;
		cout << "2. 휴식처를 탐색한다 (확률에 따라 HP를 더 회복하는 곳을 찾거나...?)" << endl;
		cout << "3. 그냥 돌아간다" << endl;
		cout << "입력: ";
		cin >> iInput;
		if (cin.fail() || iInput > 3 || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		break ;
	}
	
	if (iInput == 3)
		return ;
	else if (iInput == 1)
		iRand = 7;
	else if (iInput == 2)
		iRand = rand() % 10;

	if (iRand == 0)
	{
		system("clear");
		cout << "축복받은 물이 흐르는 훌륭한 휴식처를 발견했다." << endl;
		Heal_Hp(_tClass, HPMAX);
	}
	else if (iRand == 1)
	{
		system("clear");
		cout << "누군가 쉰 흔적이 보이는 좋은 휴식처를 발견했다." << endl;
		Heal_Hp(_tClass, HPEIGHTYP);
	}
	else if (iRand <= 3)
	{
		system("clear");
		cout << "적당히 깨끗한 휴식처를 발견했다." << endl;
		Heal_Hp(_tClass, HPHALF);
	}
	else if (iRand <= 7)
	{
		system("clear");
		cout << "그다지 편하지는 않지만 쉴 수는 있었다." << endl;
		Heal_Hp(_tClass, HPTWENTYP);
	}
	else if (iRand == 8)
	{
		system("clear");
		cout << "휴식처에 쉬고 있던 적과 조우했다..!" << endl;
		sleep(1);
		Battle(_tClass, rand() % 3 + 1, true);
	}
	else if (iRand == 9)
	{
		system("clear");
		cout << "이곳에서는 도저히 쉴 수 없을 것 같다.." << endl;
		Heal_Hp(_tClass, HPZEROP);
	}
}
