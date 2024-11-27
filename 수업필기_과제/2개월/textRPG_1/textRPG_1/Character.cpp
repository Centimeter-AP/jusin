#include "pch.h"
#include "Character.h"
#include "Info.h"
#include "Item.h"
#include "System.h"

CCharacter::CCharacter()
{
	memset(&mInfo, 0, sizeof(mInfo));
	vecItemInv.reserve(ITEMINVMAX);

	cout << GREEN << "CCHARACTER" << NOCOLOR << " ������ ȣ��" << endl;
}
CCharacter::~CCharacter()
{
	//for_each(vecItemInv.begin(), vecItemInv.end(), Safe_Delete<CItem*>);
	cout << RED << "CCHARACTER " << mInfo.sName << NOCOLOR << " �Ҹ��� ȣ��" << endl;
}

int	CCharacter::Get_CritDamage()
{
	rand() % 100 >= mInfo.iCritChance ? mInfo.iCritical = 1 : mInfo.iCritical = 2;

	return(mInfo.iAtk * mInfo.iCritical);
}

void CCharacter::Set_Item(CItem* _pItem)
{
	if (vecItemInv.size() < ITEMINVMAX)
	{
		vecItemInv.push_back(_pItem->Clone());
		cout << "�����Ͽ����ϴ�" << endl;
	}
	else
		cout << "�κ��丮�� ������ �����ϴ�." << endl;
}

void	CCharacter::Attack(CCharacter* obj)
{
	if (this->mInfo.iHP <= 0)
		return;
	cout << mInfo.sName << "�� ����!" << endl;
	obj->Get_Info()->iHP -= this->mInfo.iAtk;
	cout << obj->Get_Info()->sName << "���� " << Get_CritDamage();
	if (mInfo.iCritical == 2) { cout << " ũ��Ƽ�� "; }
	cout << "�����" << endl;
}