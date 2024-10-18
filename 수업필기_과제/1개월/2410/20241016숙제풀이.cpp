// 241016.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

typedef struct tagInfo
{
    char    szName[32];
    int     iAttack;
    int     iHp;

}INFO;

void	check_leak(void)
{
	system("leaks a.out");
}

enum JOB { WARRIOR = 1, MAGE, THIEF, END };

INFO*       Select_Job();
void        Render(INFO* pInfo);
void        Field(INFO* pPlayer);
INFO*       Create_Monster(int iInput);
void        Fight(INFO* pPlayer, INFO* pMonster);

int main()
{
    INFO    *tPlayer;

    tPlayer = Select_Job();

    int iInput(0);
    while (true)
    {
        system("clear");

        Render(tPlayer);
        cout << "1. 사냥터 2. 종료 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Field(tPlayer);
            break;

        case 2:
			
            return 0;
        }           
    }

    return 0;
}

INFO*        Select_Job()
{
    INFO        *tTemp = new INFO;
    int         iInput(0);

    cout << "직업을 선택하세요(1. 전사 2. 도적 3. 마법사) : ";
    cin >> iInput;

    switch (iInput)
    {
    case WARRIOR :
        // strcpy_s(tTemp->szName, sizeof(tTemp->szName), "전사");
		strcpy(tTemp->szName, "전사");
        tTemp->iAttack = 10;
        tTemp->iHp = 100;
        break;

    case MAGE :
        // strcpy_s(tTemp->szName, sizeof(tTemp->szName), "마법사");
		strcpy(tTemp->szName, "마법사");
        tTemp->iAttack = 10;
        tTemp->iHp = 100;
        break;

    case THIEF :
        // strcpy_s(tTemp->szName, sizeof(tTemp->szName), "도적");
		strcpy(tTemp->szName, "도적");
        tTemp->iAttack = 10;
        tTemp->iHp = 100;
        break;    
    }

    return tTemp;
}
void        Render(INFO* pInfo)
{
    cout << "================================" << endl;
    cout << "이름 : " << pInfo->szName << endl;
    cout << "체력 : " << pInfo->iHp << "\t공격력 : " << pInfo->iAttack << endl;
}

void        Field(INFO* pPlayer)
{
    int     iInput(0);

    INFO    *tMonster = nullptr;

    while (true)
    {
        system("clear");
		if (tMonster)
			{delete tMonster; tMonster = nullptr;}
        Render(pPlayer);
        cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
        cin >> iInput;
           
        if (4 == iInput)
            return;

        else if (3 >= iInput)
        {
			tMonster = Create_Monster(iInput);
            Fight(pPlayer, tMonster);
        }

    }
}
INFO*       Create_Monster(int iInput)
{
	INFO	*tMonster = new INFO;

	if (iInput == 1)
		strcpy(tMonster->szName, "초급");
	if (iInput == 2)
		strcpy(tMonster->szName, "중급");
	if (iInput == 3)
		strcpy(tMonster->szName, "고급");
	tMonster->iHp = (iInput + 1) * 30;
	tMonster->iAttack = (iInput + 1) * 3;

	return tMonster;
}

void Fight(INFO* pPlayer, INFO* pMonster)
{
    int iInput(0);

    while (true)
    {
        system("clear");

        Render(pPlayer);
        Render(pMonster);

        cout << "1. 공격 2. 도망 : ";
        cin >> iInput;

        if (1 == iInput)
        {
            pMonster->iHp -= pPlayer->iAttack;
            pPlayer->iHp -= pMonster->iAttack;

            if (0 >= pPlayer->iHp)
            {
                cout << "사망" << endl;
                pPlayer->iHp = 100;
                // system("pause");
                return;
            }

            if (0 >= pMonster->iHp)
            {
                cout << "승리" << endl;

                // system("pause");
                return;
            }

        }
        else if (2 == iInput)
            return;
    }
}
