#include "pch.h"
#include "Info.h"
#include "System.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Field = nullptr;
	Shop = nullptr;
	cout << GREEN << "CMainGame" << NOCOLOR << " ������ ȣ��" << endl;
}

CMainGame::~CMainGame()
{
	Release();
	cout << RED << "CMainGame" << NOCOLOR << " �Ҹ��� ȣ��" << endl;
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
		cout << "�༱���� �����ּ���." << endl;
		cout << "1. �ʵ�  2. ����  3. ����  4. ����" << endl;
		cout << "�Է� : ";
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
			cout << "�������� ������ �Ⱦ˷�������" << endl;
			break;

		case MENU::EXIT:
			cout << "������ �����մϴ�." << endl;
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
