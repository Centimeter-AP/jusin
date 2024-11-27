#include "pch.h"
#include "Info.h"
#include "System.h"
#include "MainGame.h"
#include "Field.h"
#include "Player.h"
#include "ItemShop.h"
#include "ArmorShop.h"
#include "Inventory.h"

CMainGame::CMainGame(): Player(nullptr), Field(nullptr), ItemShop(nullptr), ArmorShop(nullptr), Inven(nullptr)
{
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
	if (ItemShop == nullptr)
	{
		ItemShop = new CItemShop;
		ItemShop->Set_Player(Player);
		ItemShop->Initialize();
	}
	if (ArmorShop == nullptr)
	{
		ArmorShop = new CArmorShop;
		ArmorShop->Set_Player(Player);
		ArmorShop->Initialize();
	}
	if (Inven == nullptr)
	{
		Inven = new CInventory;
		Inven->Set_Player(Player);
		Inven->Initialize();
	}
}

void	CMainGame::Update()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "행선지를 정해주세요." << endl;
		cout << "1. 필드  2. 상점  3. 인벤토리  4. 종료" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case MENU::FIELD:
			Field->Update();
			break;

		case MENU::SHOP:
			Select_Shop();
			break;

		case MENU::INVEN:
			Inven->Update();
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
	Safe_Delete<CCharacter*>(Player);
	Safe_Delete<CField*>(Field);
	Safe_Delete<CShop*>(ItemShop);
	Safe_Delete<CShop*>(ArmorShop);
}

void CMainGame::Select_Shop()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		cout << "1. 아이템  2. 장비  3. 판매  4. 전 단계" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		if (iInput == 4)
			return;
		else if (iInput == 1)
			ItemShop->Update();
		else if (iInput == 2)
			ArmorShop->Update();
		else if (iInput == 3)

		break;
	}
}
