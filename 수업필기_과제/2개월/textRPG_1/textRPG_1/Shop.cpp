#include "pch.h"
#include "Info.h"
#include "Potion.h"
#include "Player.h"
#include "Shop.h"
#include "System.h"

CShop::CShop()
{
	for (int i = 0; i < 4; ++i)
	{
		mSales[i] = nullptr;
	}
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
		cout << i + 1 << ". " << mSales[i]->Get_Name();
		cout << '\t' << endl;
	}
}

void CShop::Select_Item(int idx)
{
	int iInput(0);
	
	while (1)
	{
		//system("pause"); system("cls");

		cout << idx + 1 << ". " << mSales[idx]->Get_Name() << endl;
		dynamic_cast<CPotion*>(mSales[idx])->Explain();
		cout << "1. 구입  2. 선택 취소" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		break;
	}
	if (iInput == 1)
	{
		Player->Set_Item(mSales[idx]);
		cout << "구매하였습니다" << endl;
	}	

	
}

void	CShop::Initialize()
{
	for (int i = 0; i < 4; ++i)
	{
		mSales[i] = new CPotion;
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
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		View_List();
		cout << "======================================================" << endl;
		cout << "상점을 나가려면 5 입력" << endl;
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
		SAFEDELETE(mSales[i]);
	}
}