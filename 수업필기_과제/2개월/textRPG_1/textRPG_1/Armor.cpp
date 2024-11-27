#include "pch.h"
#include "Player.h"
#include "Armor.h"

void CArmor::Use(CCharacter* obj)
{
	cout << "장비는 장착만 가능합니다." << endl;
}

CItem* CArmor::Clone()
{
	CItem* pNew = new CArmor(*this);
	return pNew;
}

void CArmor::Explain()
{
	cout << "======================================================" << endl;
	cout << "이름 : " << m_sName <<	(isEquip ? "(착용중)" : "") << endl;
	cout << "장비 타입 : ";
	switch (enType)
	{
	case ARMOR_HEAD: cout << "머리" << endl; break;
	case ARMOR_BODY: cout << "몸통" << endl; break;
	case ARMOR_GLOVE: cout << "장갑" << endl; break;
	case ARMOR_FEET: cout << "신발" << endl; break;
	case ARMOR_WEAPON: cout << "무기" << endl; break;
	case ARMOR_ACC: cout << "악세사리" << endl; break;
	case ARMOR_END: cout << "정해지지 않음" << endl; break;
	}
	cout <<  "체력 : " << iHP << " \t공격력 : " << iAtk << endl;
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
	cout << "생성할 장비의 타입 선택" << endl;
	cout << "1. 머리 2. 몸 3. 장갑 4. 신발 5. 무기 6.악세서리 : ";
	cin >> iInput;
	enType = static_cast<ARMORSLOT>(iInput - 1);
	cout << "부여 할 공격력 : ";
	cin >> iAtk;
	cout << "부여 할 체력 : ";
	cin >> iHP;
	cout << "장비의 이름은? : ";
	cin >> m_sName;
	cout << "장비 생성 완료" << endl;
	this->Explain();
}
