#include "pch.h"
#include "Character.h"
#include "Info.h"

CCharacter::CCharacter()
{
	memset(&mInfo, 0, sizeof(mInfo));
	memset(&pItem, 0, sizeof(pItem));
	cout << GREEN << "CCHARACTER" << NOCOLOR << " ������ ȣ��" << endl;
}
CCharacter::~CCharacter()
{

	cout << RED << "CCHARACTER " << mInfo.szName << NOCOLOR << " �Ҹ��� ȣ��" << endl;
}

int	CCharacter::Get_CritDamage()
{
	rand() % 100 >= mInfo.iCritical ? mInfo.iCritical = 1 : mInfo.iCritical = 2;

	return(mInfo.iAtk * mInfo.iCritical);
}

void CCharacter::Set_Item(CItem* _pItem)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!pItem[i])
			pItem[i] = _pItem;
		else if (i == 3)
			cout << "�κ��丮�� ������ �����ϴ�." << endl;
	}
}

void	CCharacter::Attack(CCharacter* obj)
{
	if (this->mInfo.iHP <= 0)
		return;
	cout << mInfo.szName << "�� ����!" << endl;
	obj->Get_Info()->iHP -= this->mInfo.iAtk;
	cout << obj->Get_Info()->szName << "���� " << Get_CritDamage();
	if (mInfo.iCritical == 2) { cout << " ũ��Ƽ�� "; }
	cout << "�����" << endl;
}