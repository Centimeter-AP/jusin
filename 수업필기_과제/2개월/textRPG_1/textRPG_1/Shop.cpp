#include "pch.h"
#include "Info.h"
#include "Potion.h"
#include "Player.h"
#include "Shop.h"
#include "System.h"

CShop::CShop()
{
	vecSales.reserve(4);
	Player = nullptr;
}
CShop::~CShop()
{
	Release();
}

void	CShop::Set_Player(CCharacter* _Player)
{
	Player = _Player;
}

void CShop::View_List()
{
	for (int i = 0; i < 4; ++i)
	{
		cout << i + 1 << ". " << vecSales[i]->Get_Name();
		cout << "\t\t" << vecSales[i]->Get_Price() << "��" << endl;
	}
}

void CShop::Select_Item(int idx)
{
	int iInput(0);
	
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "======================================================" << endl;
		cout << "����" << endl;
		cout << "======================================================" << endl;
		cout << idx + 1 << ". " << vecSales[idx]->Get_Name() << "\t\t���� : " << vecSales[idx]->Get_Price() << endl;
		dynamic_cast<CPotion*>(vecSales[idx])->Explain();
		cout << "======================================================" << endl;
		cout << "1. ����  2. ���� ���" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(2);
		break;
	}
	if (iInput == 1)
	{
		Player->Set_Item(vecSales[idx]);
	}	
}

void	CShop::Initialize()
{
	for (int i = 0; i < ITEMINVMAX; ++i)
	{
		vecSales.push_back(new CPotion);
	}
}

void	CShop::Update()
{
	int iInput(0);

	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		cout << "======================================================" << endl;
		cout << "����" << endl;
		cout << "======================================================" << endl;
		View_List();
		cout << "======================================================" << endl;
		cout << "������ �������� 5 �Է�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(5);
		if (iInput == 5)
			return;
		Select_Item(iInput - 1);
	}
}

void	CShop::Release()
{
	for (int i = 0; i < 4; ++i)
	{
		SAFEDELETE(vecSales[i]);
	}
}