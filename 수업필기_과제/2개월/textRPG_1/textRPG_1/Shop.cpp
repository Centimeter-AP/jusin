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
	if (Player->Get_Info()->sName == "����")
		sPlayerWeapon = "����";
	else if (Player->Get_Info()->sName == "������")
		sPlayerWeapon = "������";
	else if (Player->Get_Info()->sName == "����")
		sPlayerWeapon = "�ش�";
}

//void CShop::View_List(vector<CItem*>& vecSales)
//{
//	for (int i = 0; i < vecSales.size(); ++i)
//	{
//		cout << i + 1 << ". " << vecSales[i]->Get_Name();
//		cout << "\t\t" << vecSales[i]->Get_Price() << "��" << endl;
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
	//	cout << "����" << endl;
	//	cout << "======================================================" << endl;

	//	cout << "1. ������  2. ���  3. �� �ܰ�" << endl;
	//	cout << "�Է� : ";
	//	cin >> iInput;
	//	CINEXCEPTION(3);
	//	if (iInput == 3)
	//		return;
	//	if (iInput == 1)
	//		View_List(vecItemSales); //������
	//	if (iInput == 2)
	//	{
	//		cout << "1. �Ӹ�  2. ����  3. �尩  4. �Ź�  5. ����  6. �Ǽ��縮  7. �� �ܰ�" << endl;
	//		cout << "�Է� : ";
	//		cin >> iInput;
	//		CINEXCEPTION(7);
	//		//if (iInput == 7)

	//	}
	//	//View_List();
	//	cout << "======================================================" << endl;
	//	cout << "������ �������� 5 �Է�" << endl;
	//	cout << "�Է� : ";
	//	cin >> iInput;
	//	CINEXCEPTION(5);
	//	if (iInput == 5)
	//		return;
	//	Select_Item(iInput - 1);
	//}
}
