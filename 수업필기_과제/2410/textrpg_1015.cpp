#include <iostream>

#define FULLHP 100

using namespace std;

enum BATTLE {
	DEAD = 500,
	ALIVE
};

typedef struct sInfo {
	char	sName[32];
	int		iHp;
	int		iAtk;
}INFO;

void	CinFailException(bool i)
{
	system("clear");
	cout << "잘못 입력하셨습니다." << endl;
	// system("pause");
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}
INFO* InitInfo(const char* _sName, int _iHp, int _iAtk)
{
	INFO* tClass = new INFO;
	strcpy(tClass->sName, _sName);
	tClass->iHp = _iHp;
	tClass->iAtk = _iAtk;

	return tClass;
}

INFO** DeleteInfo(INFO** tClass, int iCount)
{
	for (int i = 0; i < iCount; ++i)
	{
		delete tClass[i];
		tClass[i] = nullptr;
	}
	delete[] tClass;
	tClass = nullptr;

	return nullptr;
}

void	PrintInfo(INFO _tInfo, const char* _sMessage)
{
	cout << "================================" << endl;
	cout << "이름: " << _tInfo.sName << endl;
	cout << "체력: " << _tInfo.iHp << '\t';
	cout << "공격력: " << _tInfo.iAtk << endl;
	cout << _sMessage;
}

int	Battle(INFO* _tClass, INFO _tEnemy)
{
	int		iInput(0);
	while (1)
	{
		system("clear");
		PrintInfo(*_tClass, "");
		PrintInfo(_tEnemy, "1. 공격  2. 도망 : ");
		cin >> iInput;
		if (iInput == 2)
			return ALIVE;
		else if (iInput == 1)
		{
			_tClass->iHp -= _tEnemy.iAtk;
			_tEnemy.iHp -= _tClass->iAtk;
			if (_tClass->iHp <= 0)
			{
				cout << "플레이어 사망" << endl;
				// system("pause");
				return DEAD;
			}
			else if (_tEnemy.iHp <= 0)
			{
				cout << "승리! " << endl;
				// system("pause");
				return ALIVE;
			}
		}
		else
		{
			CinFailException(cin.fail()); continue;
		}

	}
}


int main()
{
	const int	iClassCount(3);
	const int	iEnemyCount(3);

	INFO** tClass = new INFO * [iClassCount];
	INFO** tEnemy = new INFO * [iEnemyCount];
	int		iInput(0), iClass(0), iEnemy(0), iStatus(0);

	tEnemy[0] = InitInfo("초급", 30, 5);
	tEnemy[1] = InitInfo("중급", 50, 7);
	tEnemy[2] = InitInfo("고급", 90, 9);

	tClass[0] = InitInfo("전사", FULLHP, 8);
	tClass[1] = InitInfo("마법사", FULLHP, 10);
	tClass[2] = InitInfo("도적", FULLHP, 13);		// 직업이나 난이도를 입력 받는 것도 나중에 만들 수 있게

	system("clear");
	while (1)
	{
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) :";
		cin >> iInput;
		if (cin.fail() || iInput > 3 || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		break;
	}
	iClass = iInput - 1;

	system("clear");
	while (1)
	{
		PrintInfo(*tClass[iClass], "1. 사냥터  2. 종료 : ");
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			system("clear");
			while (1)
			{
				PrintInfo(*tClass[iClass], "1. 초급  2. 중급  3. 고급  4. 전 단계 : ");
				cin >> iInput;
				if (cin.fail() || !(iInput > 0 && iInput < 5)) {
					CinFailException(cin.fail()); continue;
				}
				if (iInput == 4)
					break;
				iEnemy = iInput - 1;
				iStatus = Battle(tClass[iClass], *tEnemy[iEnemy]);
				if (ALIVE == iStatus) {
					system("clear");
					continue;
				}
				else if (DEAD == iStatus)
				{
					tClass[iClass]->iHp = FULLHP;
					system("clear");
					continue;
				}
			}
			if (iInput == 4)
			{
				system("clear");
				break;
			}
				
			iEnemy = iInput - 1;
			Battle(tClass[iClass], *tEnemy[iEnemy]);
			break;

		case 2:
			tClass = DeleteInfo(tClass, iClassCount);
			tEnemy = DeleteInfo(tEnemy, iEnemyCount);
			return 0;

		default:
			CinFailException(cin.fail());
			break;
		}
	}
	return 0;
}
