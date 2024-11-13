#include "pch.h"
#include "Info.h"
#include "System.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Field = nullptr;
	Shop = nullptr;
	cout << GREEN << "CMainGame" << NOCOLOR << " 생성자 호출" << endl;
}

CMainGame::~CMainGame()
{
	Release();
	cout << RED << "CMainGame" << NOCOLOR << " 소멸자 호출" << endl;
}

void	CMainGame::Initialize()
{
	if (Player == nullptr)
	{
		Player = new CPlayer;
		Player->Initialize();
	}
	if (Field == nullptr)
	{
		Field = new CField;
		Field->Initialize();
		Field->Set_Player(Player);
	}
	if (Shop == nullptr)
	{
		Shop = new CShop;
		Shop->Initialize();
		Shop->Set_Player(Player);
	}
}



void	CMainGame::Update()
{
	int iInput(0);

	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		cout << "행선지를 정해주세요." << endl;
		cout << "1. 필드  2. 상점  3. 저장  4. 종료" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case MENU::FIELD:
			Field->Update();
			break;

		case MENU::SHOP:
			Shop->Update();
			break;

		case MENU::SAVE:
			cout << "선생님이 저장을 안알려줬지롱" << endl;
			break;

		case MENU::EXIT:
			cout << "게임을 종료합니다." << endl;
			return;

		default:
			break;
		}
	}
}

void	CMainGame::Release()
{
	SAFEDELETE(Player);
	SAFEDELETE(Field);
	SAFEDELETE(Shop);
}
