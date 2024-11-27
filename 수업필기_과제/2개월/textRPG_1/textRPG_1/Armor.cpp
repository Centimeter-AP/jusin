#include "pch.h"
#include "Player.h"
#include "Armor.h"

void CArmor::Use(CCharacter* obj)
{
	cout << "���� ������ �����մϴ�." << endl;
}

CItem* CArmor::Clone()
{
	CItem* pNew = new CArmor(*this);
	return pNew;
}

void CArmor::Explain()
{
	cout << "======================================================" << endl;
	cout << "�̸� : " << m_sName <<	(isEquip ? "(������)" : "") << endl;
	cout << "��� Ÿ�� : ";
	switch (enType)
	{
	case ARMOR_HEAD: cout << "�Ӹ�" << endl; break;
	case ARMOR_BODY: cout << "����" << endl; break;
	case ARMOR_GLOVE: cout << "�尩" << endl; break;
	case ARMOR_FEET: cout << "�Ź�" << endl; break;
	case ARMOR_WEAPON: cout << "����" << endl; break;
	case ARMOR_ACC: cout << "�Ǽ��縮" << endl; break;
	case ARMOR_END: cout << "�������� ����" << endl; break;
	}
	cout <<  "ü�� : " << iHP << " \t���ݷ� : " << iAtk << endl;
	cout << "======================================================" << endl;
}

void CArmor::Initialize()
{
	if (enType == ARMOR_END)
		Make_Armor();
}

void CArmor::Equip(CCharacter* obj)
{
	//dynamic_cast<CPlayer*>(obj)->
}

void CArmor::Unequip(CCharacter* obj)
{
}

void CArmor::Make_Armor()
{
	int iInput(0);
	cout << "������ ����� Ÿ�� ����" << endl;
	cout << "1. �Ӹ� 2. �� 3. �尩 4. �Ź� 5. ���� 6.�Ǽ����� : ";
	cin >> iInput;
	enType = static_cast<ARMORSLOT>(iInput - 1);
	cout << "�ο� �� ���ݷ� : ";
	cin >> iAtk;
	cout << "�ο� �� ü�� : ";
	cin >> iHP;
	cout << "����� �̸���? : ";
	cin >> m_sName;
	cout << "��� ���� �Ϸ�" << endl;
	this->Explain();
}
