#include "pch.h"
#include "ItemShop.h"
#include "Potion.h"
#include "Bomb.h"
#include "Player.h"

void CItemShop::Initialize()
{
	vecItemSales.push_back(new CPotion);
	vecItemSales.push_back(new CBomb);
}

void CItemShop::Select_Item(int idx)
{
	int iInput(0);

	while(1)
	{
		system("cls");
		Player->Print_Info();
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		View_List();
		cout << "======================================================" << endl;
		cout << idx + 1 << ". " << vecItemSales[idx]->Get_Name() << "\t\t가격 : " << vecItemSales[idx]->Get_Price() << endl;
		vecItemSales[idx]->Explain();
		cout << "======================================================" << endl;
		cout << "1. 구입  2. 선택 취소" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 1)
			dynamic_cast<CPlayer*>(Player)->Buy_Item(vecItemSales[idx]);
		break;
	}
}

void CItemShop::Update()
{
	int iInput(0), idx(0);

	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		View_List();
		cout << "======================================================" << endl;
		cout << "뒤로 돌아가려면 0 입력" << endl;
		cin >> iInput;
		if (cin.fail() || iInput > vecItemSales.size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		if (iInput == 0)
			return;
		Select_Item(iInput - 1);
	}
}

void CItemShop::View_List()
{
	for (int i = 0; i < vecItemSales.size(); ++i)
	{
		cout << i + 1 << ". " << vecItemSales[i]->Get_Name();
		cout << "\t\t" << vecItemSales[i]->Get_Price() << "원" << endl;
	}
}
