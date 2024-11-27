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
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		cout << "1. ������  2. ���  3. �� �ܰ�" << endl;
		cout << "�Է� : ";
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
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		cout << "1. ������  2. ���  3. �� �ܰ�" << endl;
		cout << "�Է� : ";
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
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecArmorInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*pVecArmorInv)[i]->Get_Name() << "\t";
			if (i % 2) cout << endl;
		}
		cout << endl;
		if (pVecArmorInv->size() == 0)
			cout << "�ƹ��͵� �����ϴ�." << endl;
		cout << "======================================================" << endl;
		cout << "���� ������ 9, �ڷ� ���ư����� 0 �Է�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecArmorInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		iSelect = iInput - 1;
		if (iInput == 0)
			return;
		system("cls");
		Player->Print_Info();
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		cout << GREEN << "���� ���� ��� " << NOCOLOR << endl;
		(*pVecArmorInv)[iSelect]->Explain();
		View_Equipping(dynamic_cast<CArmor*>((*pVecArmorInv)[iSelect])->Get_Type());
		cout << "1. ����     2. �� �ܰ�\n�Է� : ";
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
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecItemInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*(pVecItemInv))[i]->Get_Name()
				 << "\t\t���� : " << (*(pVecItemInv))[i]->Get_Count()
				 << endl;
		}
		if (pVecItemInv->size() == 0)
			cout << "�ƹ��͵� �����ϴ�." << endl;
		cout << "======================================================" << endl;
		cout << "�ڷ� ���ư����� 0 �Է�\n�Է� : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecItemInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		if (iInput == 0)
			return;
		else
		{
			system("cls");
			Player->Print_Info();
			cout << "�κ��丮" << endl;
			cout << "======================================================" << endl;
			cout << " " << (*(pVecItemInv))[iInput - 1]->Get_Name()
				 << "\t\t" << (*(pVecItemInv))[iInput - 1]->Get_Count()
				 << "�� ������" << endl;
			(*(pVecItemInv))[iInput - 1]->Explain();
			cout << "======================================================" << endl;
			system("pause");
		}
	}
}

void CInventory::View_Equipping(ARMORSLOT _TYPE)
{
	cout << "======================================================" << endl;
	cout << GREEN << "���� ���� ���" << NOCOLOR << endl;
	if (dynamic_cast<CPlayer*>(Player)->Get_TypeSlot(_TYPE))
		dynamic_cast<CPlayer*>(Player)->Get_TypeSlot(_TYPE)->Explain();
	else
		cout << "======================================================\n"
			 << RED << "���� ���� ���� ��� ����\n" << NOCOLOR
			 << "======================================================"<< endl;
}

void CInventory::Sell_Armor()
{
	int iInput(0), iSelect(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < pVecArmorInv->size(); ++i)
		{
			cout << i + 1 << ". " << (*pVecArmorInv)[i]->Get_Name() << "\t";
			if (i % 2) cout << endl;
		}
		cout << endl;
		if (pVecArmorInv->size() == 0)
			cout << "�ƹ��͵� �����ϴ�." << endl;
		cout << "======================================================" << endl;
		cout << "�ڷ� ���ư����� 0 �Է�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		if (cin.fail() || iInput > pVecArmorInv->size() || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		iSelect = iInput - 1;
		if (iInput == 0)
			return;
		system("cls");
		Player->Print_Info();
		cout << "�κ��丮" << endl;
		cout << "======================================================" << endl;
		cout << GREEN << "���� ���� ��� " << NOCOLOR << endl;
		(*pVecArmorInv)[iSelect]->Explain();
		View_Equipping(dynamic_cast<CArmor*>((*pVecArmorInv)[iSelect])->Get_Type());
		cout << "1. ����     2. �� �ܰ�\n�Է� : ";
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
