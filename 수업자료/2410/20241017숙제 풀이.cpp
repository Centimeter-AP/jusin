// 241017.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

// https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/find-memory-leaks-using-the-crt-library?view=msvc-170

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;

typedef struct tagInfo
{
    char    szName[32];
    int     iAttack;
    int     iHp;

}INFO;

enum JOB { WARRIOR = 1, MAGE, THIEF, END };

INFO*       Select_Job();
void        Main_Game(INFO* pPlayer);
void        Render(INFO* pInfo);
void        Field(INFO* pPlayer);
void        Create_Obj(INFO** ppMonster, const char* pName, int _iAttack, int _iHp);
int         Fight(INFO* pPlayer, INFO* pMonster);

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    INFO* pPlayer = Select_Job();

    if (nullptr == pPlayer)
    {
        cout << "플레이어 할당 안됨" << endl;
        return 0;
    }

    Main_Game(pPlayer);

    if (nullptr != pPlayer)
    {
        delete pPlayer;
        pPlayer = nullptr;
    }  

    return 0;
}

INFO*   Select_Job()
{
    INFO*       pTemp(nullptr);
    int         iInput(0);
    bool        bSelect(false);

    while (!bSelect)
    {
        system("cls");

        cout << "직업을 선택하세요(1. 전사 2. 도적 3. 마법사 4. 종료) : ";
        cin >> iInput;

        switch (iInput)
        {
        case WARRIOR:
            pTemp = new INFO;

            strcpy_s(pTemp->szName, sizeof(pTemp->szName), "전사");
            pTemp->iAttack = 10;
            pTemp->iHp = 100;
            bSelect = true;
            break;

        case MAGE:
           /* pTemp = new INFO;
            strcpy_s(pTemp->szName, sizeof( pTemp->szName), "마법사");
            pTemp->iAttack = 10;
            pTemp->iHp = 100;*/

            Create_Obj(&pTemp, "마법사", 10, 100);
            bSelect = true;
            break;

        case THIEF:
            pTemp = new INFO;
            strcpy_s( pTemp->szName, sizeof( pTemp->szName), "도적");
            pTemp->iAttack = 10;
            pTemp->iHp = 100;
            bSelect = true;
            break;

        case END:
            cout << "게임을 종료합니다" << endl;
            bSelect = true;
            break;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            break;
        }
    }   

    return pTemp;
}
void        Main_Game(INFO* pPlayer)
{
    int iInput(0);

    while (true)
    {
        system("cls");

        Render(pPlayer);
        cout << "1. 사냥터 2. 종료 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Field(pPlayer);
            break;

        case 2:
            return;
        }
    }
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

    INFO* pMonster = nullptr;

    while (true)
    {
        system("cls");

        Render(pPlayer);
        cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            Create_Obj(&pMonster, "초급", 3, 30);
            break;

        case 2:
            Create_Obj(&pMonster, "중급", 6, 60);
            break;

        case 3:
            Create_Obj(&pMonster, "고급", 9, 90);
            break;

        case 4:
            return;

        default:
            cout << "잘못 입력하셨습니다" << endl;
            continue;
       }

        int iResult = Fight(pPlayer, pMonster);

        if (1 == iResult)
        {
            pPlayer->iHp = 100;
        }

        if(nullptr != pMonster)
        {
            delete pMonster;
            pMonster = nullptr;
        }
    }
}
void        Create_Obj(INFO** ppInfo, const char* pName, int _iAttack, int _iHp)
{
   (*ppInfo) = new INFO;

   strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
   (*ppInfo)->iAttack    = _iAttack;
   (*ppInfo)->iHp        = _iHp;
}

int Fight(INFO* pPlayer, INFO* pMonster)
{
    int iInput(0);

    while (true)
    {
        system("cls");

        Render(pPlayer);
        Render(pMonster);

        cout << "1. 공격 2. 도망 : ";
        cin >> iInput;

        switch (iInput)
        {
        case 1:
            pMonster->iHp -= pPlayer->iAttack;
            pPlayer->iHp -= pMonster->iAttack;
            break;

        case 2:
            return 0;

        default:
            cout << "잘못 입력" << endl;
            break;
       }
                    
       if (0 >= pPlayer->iHp)
       {
           cout << "사망" << endl;
           system("pause");

           return 1;
       }

      if (0 >= pMonster->iHp)
      {
          cout << "승리" << endl;

          system("pause");
          return 0;
      }

    }
}
