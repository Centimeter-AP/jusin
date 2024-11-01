#include "../precom.h"
#include "../Info.h"
#include "../System/System.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Field = nullptr;
	cout << "CMainGame 생성자 호출" << endl;
}

CMainGame::~CMainGame()
{
	Release();
	cout << "CMainGame 소멸자 호출" << endl;
}

void	CMainGame::Initialize()
{
	if (Player == nullptr)
	{
		Player = new CPlayer;
		Player->Initialize();
	}
	Field = new CField;
	Field->Initialize();
}



void	CMainGame::Update()
{
	int iInput(0);

	while (1)
	{
		system("clear");
		CCharacter *Monster = new CPlayer("테스트몬스터", 100, 5);
		cout << "1. 공격\n";
		cin >> iInput;
		if (iInput == 1)
			Player->Attack(*Monster);
		
		delete Monster;
		// cout << "행선지를 정해주세요." << endl;
		// cout << "1. 필드  2. 상점  3. 저장  4. 종료" << endl;
		// cout << "입력 : ";
		// cin >> iInput;
		// CINEXCEPTION(4);
		// switch (iInput)
		// {
		// case MENU::FIELD:
			
		// 	break;
		
		// default:
		// 	break;
		// }
	}
}

void	CMainGame::Release()
{
	SAFEDELETE(Player);
	SAFEDELETE(Field);
}

