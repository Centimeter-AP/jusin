#include "pch.h"
#include "Inventory.h"
#include "Item.h"
#include "Info.h"

void CInventory::Initialize()
{
	Set_ArmorInv();
}

void CInventory::Update()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		cout << "1. 아이템  2. 장비  3. 전 단계" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(3);
		if (iInput == 1)
			View_Item();
		else if (iInput == 2)
			View_Armor();
		else
			return;
	}
}

void CInventory::Sell_Update()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		cout << "1. 아이템  2. 장비  3. 전 단계" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(3);
		if (iInput == 1)
			View_Item();
		else if (iInput == 2)
			View_Armor();
		else
			return;
	}
}

void CInventory::View_Armor()
{
	int iInput(0), iSelect(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecArmorInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*pVecArmorInv)[i]->Get_Name() << "\t";
			if (i % 2) cout << endl;
		}
		cout << endl;
		if (pVecArmorInv->size() == 0)
			cout << "아무것도 없습니다." << endl;
		cout << "======================================================" << endl;
		cout << "장착 해제는 9, 뒤로 돌아가려면 0 입력" << endl;
		cout << "입력 : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecArmorInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		iSelect = iInput - 1;
		if (iInput == 0)
			return;
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		cout << GREEN << "선택 중인 장비 " << NOCOLOR << endl;
		(*pVecArmorInv)[iSelect]->Explain();
		View_Equipping(dynamic_cast<CArmor*>((*pVecArmorInv)[iSelect])->Get_Type());
		cout << "1. 장착     2. 전 단계\n입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 2)
			continue;
		else if (iInput == 1)
			dynamic_cast<CPlayer*>(Player)->Equip_Armor((*pVecArmorInv)[iSelect]);
			system("pause");
	}
}

void CInventory::View_Item()
{
	int iInput(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecItemInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*(pVecItemInv))[i]->Get_Name()
				 << "\t\t개수 : " << (*(pVecItemInv))[i]->Get_Count()
				 << endl;
		}
		if (pVecItemInv->size() == 0)
			cout << "아무것도 없습니다." << endl;
		cout << "======================================================" << endl;
		cout << "뒤로 돌아가려면 0 입력\n입력 : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecItemInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		if (iInput == 0)
			return;
		else
		{
			system("cls");
			Player->Print_Info();
			cout << "인벤토리" << endl;
			cout << "======================================================" << endl;
			cout << " " << (*(pVecItemInv))[iInput - 1]->Get_Name()
				 << "\t\t" << (*(pVecItemInv))[iInput - 1]->Get_Count()
				 << "개 보유중" << endl;
			(*(pVecItemInv))[iInput - 1]->Explain();
			cout << "======================================================" << endl;
			system("pause");
		}
	}
}

void CInventory::View_Equipping(ARMORSLOT _TYPE)
{
	cout << "======================================================" << endl;
	cout << GREEN << "착용 중인 장비" << NOCOLOR << endl;
	if (dynamic_cast<CPlayer*>(Player)->Get_TypeSlot(_TYPE))
		dynamic_cast<CPlayer*>(Player)->Get_TypeSlot(_TYPE)->Explain();
	else
		cout << "======================================================\n"
			 << RED << "현재 착용 중인 장비 없음\n" << NOCOLOR
			 << "======================================================"<< endl;
}

void CInventory::Sell_Armor()
{
	int iInput(0), iSelect(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecArmorInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*pVecArmorInv)[i]->Get_Name() << "\t";
			if (i % 2) cout << endl;
		}
		cout << endl;
		if (pVecArmorInv->size() == 0)
			cout << "아무것도 없습니다." << endl;
		cout << "======================================================" << endl;
		cout << "뒤로 돌아가려면 0 입력" << endl;
		cout << "입력 : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecArmorInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		iSelect = iInput - 1;
		if (iInput == 0)
			return;
		system("cls");
		Player->Print_Info();
		cout << "인벤토리" << endl;
		cout << "======================================================" << endl;
		cout << GREEN << "선택 중인 장비 " << NOCOLOR << endl;
		(*pVecArmorInv)[iSelect]->Explain();
		View_Equipping(dynamic_cast<CArmor*>((*pVecArmorInv)[iSelect])->Get_Type());
		cout << "1. 장착     2. 전 단계\n입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 2)
			continue;
		else if (iInput == 1)
			dynamic_cast<CPlayer*>(Player)->Equip_Armor((*pVecArmorInv)[iSelect]);
		system("pause");
	}
}

void CInventory::Sell_Item()
{
}
