#include "pch.h"
#include "Info.h"
#include "Potion.h"
#include "Bomb.h"
#include "Player.h"
#include "Shop.h"
#include "System.h"

CShop::CShop() : sPlayerWeapon("")
{
	Player = nullptr;
}

CShop::~CShop()
{
	Release();
}

void	CShop::Set_Player(CCharacter* _Player)
{
	Player = _Player;
	if (Player->Get_Info()->sName == "전사")
		sPlayerWeapon = "도끼";
	else if (Player->Get_Info()->sName == "마법사")
		sPlayerWeapon = "지팡이";
	else if (Player->Get_Info()->sName == "도적")
		sPlayerWeapon = "붕대";
}

//void CShop::View_List(vector<CItem*>& vecSales)
//{
//	for (int i = 0; i < vecSales.size(); ++i)
//	{
//		cout << i + 1 << ". " << vecSales[i]->Get_Name();
//		cout << "\t\t" << vecSales[i]->Get_Price() << "원" << endl;
//	}
//	//for_each(vecItemSales.begin(), vecItemSales.end(), Show_List);
//}

void CShop::Select_Item(int idx)
{
	
}


void	CShop::Initialize()
{


}


void	CShop::Update()
{
	//int iInput(0);

	//while (1)
	//{
	//	system("pause"); system("cls");
	//	Player->Print_Info();
	//	cout << "상점" << endl;
	//	cout << "======================================================" << endl;

	//	cout << "1. 아이템  2. 장비  3. 전 단계" << endl;
	//	cout << "입력 : ";
	//	cin >> iInput;
	//	CINEXCEPTION(3);
	//	if (iInput == 3)
	//		return;
	//	if (iInput == 1)
	//		View_List(vecItemSales); //아이템
	//	if (iInput == 2)
	//	{
	//		cout << "1. 머리  2. 몸통  3. 장갑  4. 신발  5. 무기  6. 악세사리  7. 전 단계" << endl;
	//		cout << "입력 : ";
	//		cin >> iInput;
	//		CINEXCEPTION(7);
	//		//if (iInput == 7)

	//	}
	//	//View_List();
	//	cout << "======================================================" << endl;
	//	cout << "상점을 나가려면 5 입력" << endl;
	//	cout << "입력 : ";
	//	cin >> iInput;
	//	CINEXCEPTION(5);
	//	if (iInput == 5)
	//		return;
	//	Select_Item(iInput - 1);
	//}
}
