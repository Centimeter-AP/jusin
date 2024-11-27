#include "pch.h"
#include "ArmorShop.h"
#include "Armor.h"
#include "Item.h"
#include "Player.h"

CArmorShop::CArmorShop()
{
	for (int i = 0; i < ARMOR_END; ++i)
	{
		vecArmorSales[i].reserve(3);
	}
}

CArmorShop::~CArmorShop()
{
	Release();
}

void CArmorShop::Initialize()
{
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(1, 10, 3000, ARMOR_HEAD, "프리미엄 뉴비모자"));
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(2, 15, 5000, ARMOR_HEAD, "미스릴 전투헬름"));
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(5, 50, 10000, ARMOR_HEAD, "아다만티움 전설투구"));

	vecArmorSales[ARMOR_BODY].push_back(new CArmor(3, 20, 5000, ARMOR_BODY, "프리미엄 뉴비웨어"));
	vecArmorSales[ARMOR_BODY].push_back(new CArmor(7, 40, 8000, ARMOR_BODY, "미스릴 전투갑옷"));
	vecArmorSales[ARMOR_BODY].push_back(new CArmor(15, 80, 12000, ARMOR_BODY, "아다만티움 전설중갑"));

	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(1, 8, 3000, ARMOR_GLOVE, "프리미엄 뉴비장갑"));
	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(2, 13, 5000, ARMOR_GLOVE, "미스릴 전투장갑"));
	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(5, 30, 10000, ARMOR_GLOVE, "아다만티움 전설체인"));

	vecArmorSales[ARMOR_FEET].push_back(new CArmor(1, 8, 3000, ARMOR_FEET, "프리미엄 뉴비슈즈"));
	vecArmorSales[ARMOR_FEET].push_back(new CArmor(2, 13, 5000, ARMOR_FEET, "미스릴 전투장화"));
	vecArmorSales[ARMOR_FEET].push_back(new CArmor(5, 30, 10000, ARMOR_FEET, "아다만티움 전설그리브"));

	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(5, 0, 3000, ARMOR_WEAPON, "프리미엄 뉴비" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(10, 0, 5000, ARMOR_WEAPON, "미스릴 전투" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(20, 0, 10000, ARMOR_WEAPON, "아다만티움 전설" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(100, 0, 50000, ARMOR_WEAPON, "머글의 지팡이"));

	vecArmorSales[ARMOR_ACC].push_back(new CArmor(2, 5, 2000, ARMOR_ACC, "프리미엄 뉴비반지"));
	vecArmorSales[ARMOR_ACC].push_back(new CArmor(4, 6, 5000, ARMOR_ACC, "미스릴 전투목걸이"));
	vecArmorSales[ARMOR_ACC].push_back(new CArmor);
}

void CArmorShop::Update()
{
	int iInput(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "상점\t\t\t\t장비 인벤토리 : ";
		cout << dynamic_cast<CPlayer*>(Player)->Get_ArmorInv()->size() << " / " << ARMORINVMAX << endl;
		cout << "======================================================" << endl;
		cout << "1. 머리     2. 몸통     3. 장갑     4. 신발\n5. 무기     6. 악세사리     7. 전 단계" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(7);
		if (iInput == 7)
			return;
		View_List(static_cast<ARMORSLOT>(iInput - 1));
	}
}

void CArmorShop::Release()
{

	for (int i = 0; i < ARMOR_END; ++i)
		for_each(vecArmorSales[i].begin(), vecArmorSales[i].end(), Safe_Delete<CItem*>);
}

void CArmorShop::View_List(ARMORSLOT _TYPE)
{
	int iInput(0), iSelect(0);
	while (1)
	{
		////////
		system("cls");
		Player->Print_Info();
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < vecArmorSales[_TYPE].size(); ++i)
		{
			cout << i + 1 << ". " << vecArmorSales[_TYPE][i]->Get_Name();
			cout << "\t\t" << vecArmorSales[_TYPE][i]->Get_Price() << "원" << endl;
		}
		////////
		cout << "======================================================" << endl;
		cout << "뒤로 돌아가려면 0 입력" << endl;
		cout << "입력 : ";
		cin >> iInput;
		if (_TYPE != ARMOR_WEAPON)
			if (cin.fail() || iInput > 4 || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		else if (cin.fail() || iInput > 3 || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		if (iInput == 0)
			return;
		////////
		system("cls");
		Player->Print_Info();
		cout << "상점" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < vecArmorSales[_TYPE].size(); ++i)
		{
			cout << i + 1 << ". " << vecArmorSales[_TYPE][i]->Get_Name();
			cout << "\t\t" << vecArmorSales[_TYPE][i]->Get_Price() << "원" << endl;
		}
		////////
		iSelect = iInput - 1;
		vecArmorSales[_TYPE][iSelect]->Explain();
		cout << "1. 구매  2. 선택 취소\n입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 2)
			continue;
		if (iInput == 1)	
			dynamic_cast<CPlayer*>(Player)->Buy_Armor(vecArmorSales[_TYPE][iSelect]);
		system("pause");
	}
}
