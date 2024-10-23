#include "textrpg.h"


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

void	Battle(INFO *_tClass, int _iEnemyNum)
{
	INFO	*tEnemy = nullptr;
	int		iInput(0), iFlag(1);

	tEnemy = Make_Enemy(_iEnemyNum);

	while(iFlag)
	{
		system("clear");
		Print_Info(_tClass);
		Print_Info(tEnemy);
		cout << ATTACK << ". 공격  " << FLEE << ". 도망 : ";
		cin >> iInput;
		if (cin.fail() || iInput > FLEE || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		switch (iInput)
		{
		case ATTACK:
			Attack(_tClass, tEnemy);
			break;
		
		case FLEE:
			iFlag = 0;
			break ;
		
		default:
			iFlag = 0;
			break ;
		}
		if (_tClass->iHp <= 0)
		{
			cout << _tClass->sName << " 패배..." << endl;
			Make_Hp_Full(_tClass);
			//sleep(1);
			iFlag = 0;
			break ;
		}
		else if (tEnemy->iHp <= 0)
		{
			cout << _tClass->sName << " 승리!" << endl;
			//sleep(1);
			iFlag = 0;
			break ;
		}
	}
	DELETE_INFO(tEnemy)
}

void	Enter_Dungeon(INFO *_tClass)
{
	int 	iInput(0), iHeal(1);

	while(1)
	{
		rand() % 3 == 0 ? iHeal = 0 : iHeal = 1;
		while(1)
		{	
			system("clear");
			Print_Info(_tClass);
			cout << EASY << ". 초급  ";
			cout << NORMAL << ". 중급  ";
			cout << HARD << ". 고급  ";
			if (!iHeal)						  	//iheal == 0일 때 휴식처 등장
				cout << HEAL << ". 휴식처  ";		// BACK은 기본 5
			cout << BACK - iHeal << ". 전 단계 : ";	// 휴식처가 없을 경우 목록 - 1개의 선택지
			cin >> iInput;
			if (cin.fail() || iInput > BACK - iHeal || iInput < 1) {
				CinFailException(cin.fail()); continue;
			}
			break;
		}
		if (iInput == BACK - iHeal)
			return ;
		else if (iInput == HEAL)
		{
			cout << "휴식처를 발견했다." << endl;
			Make_Hp_Full(_tClass);
		}
		else
			Battle(_tClass, iInput);
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
			Save_Game(tClass);
			Exit_Game();

		default:
			DELETE_INFO(tClass)
			return ;
		}
	}
	DELETE_INFO(tClass)
}

int main()
{
	srand((unsigned int)time(NULL));
	Main_Game_Loop();

	return 0;
}
