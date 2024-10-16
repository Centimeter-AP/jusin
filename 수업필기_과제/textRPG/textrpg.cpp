#include <iostream>
#include <unistd.h>

typedef struct s_info{
	char	sName[32];
	int		iHp;
	int		iMaxHp;
	int		iAtk;
	int		iCritChance;
}INFO;

enum CLASS{
	WARRIOR = 1,
	MAGE,
	ROGUE
};

enum MONSTER{
	EASY = 1,
	NORMAL,
	HARD,
	HEAL,
	BACK
};

enum BATTLE{
	ATTACK = 1,
	FLEE
};

enum FIELD{
	DUNGEON = 1,
	EXITGAME
};

using namespace std;

void	CinFailException(bool i)
{
	// system("clear");
	cout << "잘못 입력하셨습니다." << endl;
	// system("pause");
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}

void	Print_Info(INFO	*_tInfo)
{
	cout << "============================" << endl;
	cout << "이름 : " << _tInfo->sName << endl;
	cout << "체력 : " << _tInfo->iHp << "  \t공격력 : " << _tInfo->iAtk << endl;
}

INFO	*Make_Class()
{
	INFO	*tTmp = new INFO;
	int		iInput(0);

	while (1)
	{
		system("clear");
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		if (cin.fail() || iInput > 3 || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		break;
	}

	switch (iInput)
	{
	case WARRIOR:
		strcpy(tTmp->sName, "전사");
		tTmp->iMaxHp = 100;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 10;
		tTmp->iCritChance = 10;
		break;

	case MAGE:
		strcpy(tTmp->sName, "마법사");
		tTmp->iMaxHp = 90;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 12;
		tTmp->iCritChance = 10;
		break;

	case ROGUE:
		strcpy(tTmp->sName, "도적");
		tTmp->iMaxHp = 115;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 9;
		tTmp->iCritChance = 10;
		break;
	
	default:
		return nullptr;
	}
	return tTmp;
}

INFO	*Make_Enemy(int _iInput)
{
	INFO	*tTmp = new INFO;

	switch (_iInput)
	{
	case EASY:
		strcpy(tTmp->sName, "초급 몬스터");
		tTmp->iMaxHp = 30;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 5;
		tTmp->iCritChance = 10;
		break;

	case NORMAL:
		strcpy(tTmp->sName, "중급 몬스터");
		tTmp->iMaxHp = 50;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 7;
		tTmp->iCritChance = 10;
		break;

	case HARD:
		strcpy(tTmp->sName, "상급 몬스터");
		tTmp->iMaxHp = 90;
		tTmp->iHp = tTmp->iMaxHp;
		tTmp->iAtk = 9;
		tTmp->iCritChance = 10;
		break;
	
	default:
		return nullptr;
	}
	return tTmp;
}

int		Field(INFO *_tClass)
{
	int	iInput(0);

	while(1)
	{
		system("clear");
		Print_Info(_tClass);
		cout << DUNGEON << ". 사냥터  " << EXITGAME << ". 종료 : ";
		cin >> iInput;
		if (cin.fail() || iInput > EXITGAME || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		break;
	}
	return (iInput);
}

void	Exit_Game() //금단의시스템콜(딱히금단은아니긴함)
{
	write(1, "게임 종료", 14);
	usleep(500000);
	write(1, ".", 1);
	usleep(500000);
	write(1, ".", 1);
	usleep(500000);
	write(1, ".\n", 2);
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
}

void	Battle(INFO *_tClass, INFO *_tEnemy)
{
	int	iInput(0);

	while(1)
	{
		system("clear");
		Print_Info(_tClass);
		Print_Info(_tEnemy);
		cout << ATTACK << ". 공격  " << FLEE << ". 도망 : ";
		cin >> iInput;
		if (cin.fail() || iInput > FLEE || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		switch (iInput)
		{
		case ATTACK:
			Attack(_tClass, _tEnemy);
			break;
		
		case FLEE:
			return ;
		
		default:
			return ;
		}
		if (_tClass->iHp <= 0)
		{
			cout << _tClass->sName << " 패배..." << endl;
			Make_Hp_Full(_tClass);
			sleep(1);
			return ;
		}
		else if (_tEnemy->iHp <= 0)
		{
			cout << _tClass->sName << " 승리!" << endl;
			sleep(1);
			return ;
		}
	}
}

void	Enter_Dungeon(INFO *_tClass)
{
	INFO	*tEnemy = nullptr;
	int 	iInput(0), iHeal(1);

	while(1)
	{
		system("clear");
		Print_Info(_tClass);
		if (iHeal == 1)
			iHeal = rand() % 2;
		cout << EASY << ". 초급  ";
		cout << NORMAL << ". 중급  ";
		cout << HARD << ". 고급  ";
		if (!iHeal)						//iheal == 0일 때 휴식처 등장
			cout << HEAL << ". 휴식처  ";		// BACK은 기본 5
		cout << BACK - iHeal << ". 전 단계 : ";	// 휴식처가 없을 경우 목록 - 1개의 선택지
		cin >> iInput;
		if (cin.fail() || iInput > BACK - iHeal || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		if (tEnemy)
		{
			delete tEnemy;
			tEnemy = nullptr;
		}
		if (iInput == HEAL)
		{
			cout << "휴식처를 발견했다." << endl;
			Make_Hp_Full(_tClass);
		}
		if (iInput == BACK - iHeal)
			return ;
		else
		{
			tEnemy = Make_Enemy(iInput);
			Battle(_tClass, tEnemy);
		}
	}
		
}

void	Main_Game_Loop()
{
	INFO	*tClass;
	int 	iInput(0);

	tClass = Make_Class();			// 직업 선택

	while(1)
	{
		iInput = Field(tClass);		// 사냥터&종료 선택
		switch (iInput)
		{
		case DUNGEON:
			Enter_Dungeon(tClass);	// 난이도 선택
			break;

		case EXITGAME:
			Exit_Game();

		default:
			if (tClass)
			{
				delete tClass;
				tClass = nullptr;
			}
			return ;
		}
	}
	delete tClass;
}

int main()
{
	srand((unsigned int)time(NULL));
	Main_Game_Loop();

	return 0;
}
