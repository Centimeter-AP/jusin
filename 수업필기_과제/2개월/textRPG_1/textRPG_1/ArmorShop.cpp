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
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(1, 10, 3000, ARMOR_HEAD, "�����̾� �������"));
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(2, 15, 5000, ARMOR_HEAD, "�̽��� �����︧"));
	vecArmorSales[ARMOR_HEAD].push_back(new CArmor(5, 50, 10000, ARMOR_HEAD, "�ƴٸ�Ƽ�� ��������"));

	vecArmorSales[ARMOR_BODY].push_back(new CArmor(3, 20, 5000, ARMOR_BODY, "�����̾� �������"));
	vecArmorSales[ARMOR_BODY].push_back(new CArmor(7, 40, 8000, ARMOR_BODY, "�̽��� ��������"));
	vecArmorSales[ARMOR_BODY].push_back(new CArmor(15, 80, 12000, ARMOR_BODY, "�ƴٸ�Ƽ�� �����߰�"));

	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(1, 8, 3000, ARMOR_GLOVE, "�����̾� �����尩"));
	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(2, 13, 5000, ARMOR_GLOVE, "�̽��� �����尩"));
	vecArmorSales[ARMOR_GLOVE].push_back(new CArmor(5, 30, 10000, ARMOR_GLOVE, "�ƴٸ�Ƽ�� ����ü��"));

	vecArmorSales[ARMOR_FEET].push_back(new CArmor(1, 8, 3000, ARMOR_FEET, "�����̾� ������"));
	vecArmorSales[ARMOR_FEET].push_back(new CArmor(2, 13, 5000, ARMOR_FEET, "�̽��� ������ȭ"));
	vecArmorSales[ARMOR_FEET].push_back(new CArmor(5, 30, 10000, ARMOR_FEET, "�ƴٸ�Ƽ�� �����׸���"));

	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(5, 0, 3000, ARMOR_WEAPON, "�����̾� ����" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(10, 0, 5000, ARMOR_WEAPON, "�̽��� ����" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(20, 0, 10000, ARMOR_WEAPON, "�ƴٸ�Ƽ�� ����" + sPlayerWeapon));
	vecArmorSales[ARMOR_WEAPON].push_back(new CArmor(100, 0, 50000, ARMOR_WEAPON, "�ӱ��� ������"));

	vecArmorSales[ARMOR_ACC].push_back(new CArmor(2, 5, 2000, ARMOR_ACC, "�����̾� �������"));
	vecArmorSales[ARMOR_ACC].push_back(new CArmor(4, 6, 5000, ARMOR_ACC, "�̽��� ���������"));
	vecArmorSales[ARMOR_ACC].push_back(new CArmor);
}

void CArmorShop::Update()
{
	int iInput(0);
	while (1)
	{
		system("cls");
		Player->Print_Info();
		cout << "����\t\t\t\t��� �κ��丮 : ";
		cout << dynamic_cast<CPlayer*>(Player)->Get_ArmorInv()->size() << " / " << ARMORINVMAX << endl;
		cout << "======================================================" << endl;
		cout << "1. �Ӹ�     2. ����     3. �尩     4. �Ź�\n5. ����     6. �Ǽ��縮     7. �� �ܰ�" << endl;
		cout << "�Է� : ";
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
		cout << "����" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < vecArmorSales[_TYPE].size(); ++i)
		{
			cout << i + 1 << ". " << vecArmorSales[_TYPE][i]->Get_Name();
			cout << "\t\t" << vecArmorSales[_TYPE][i]->Get_Price() << "��" << endl;
		}
		////////
		cout << "======================================================" << endl;
		cout << "�ڷ� ���ư����� 0 �Է�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		if (_TYPE != ARMOR_WEAPON)
			if (cin.fail() || iInput > 4 || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		else if (cin.fail() || iInput > 3 || iInput < 0) { CSystem::CinFailException(cin.fail()); continue; }
		if (iInput == 0)
			return;
		////////
		system("cls");
		Player->Print_Info();
		cout << "����" << endl;
		cout << "======================================================" << endl;
		for (int i = 0; i < vecArmorSales[_TYPE].size(); ++i)
		{
			cout << i + 1 << ". " << vecArmorSales[_TYPE][i]->Get_Name();
			cout << "\t\t" << vecArmorSales[_TYPE][i]->Get_Price() << "��" << endl;
		}
		////////
		iSelect = iInput - 1;
		vecArmorSales[_TYPE][iSelect]->Explain();
		cout << "1. ����  2. ���� ���\n�Է� : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 2)
			continue;
		if (iInput == 1)	
			dynamic_cast<CPlayer*>(Player)->Buy_Armor(vecArmorSales[_TYPE][iSelect]);
		system("pause");
	}
}
