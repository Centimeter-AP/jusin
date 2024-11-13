#include "pch.h"
#include "Character.h"
#include "Info.h"

CCharacter::CCharacter()
{
	memset(&mInfo, 0, sizeof(mInfo));
	memset(&pItem, 0, sizeof(pItem));
	cout << GREEN << "CCHARACTER" << NOCOLOR << " 생성자 호출" << endl;
}
CCharacter::~CCharacter()
{

	cout << RED << "CCHARACTER " << mInfo.szName << NOCOLOR << " 소멸자 호출" << endl;
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
			cout << "인벤토리에 공간이 없습니다." << endl;
	}
}

void	CCharacter::Attack(CCharacter* obj)
{
	if (this->mInfo.iHP <= 0)
		return;
	cout << mInfo.szName << "의 공격!" << endl;
	obj->Get_Info()->iHP -= this->mInfo.iAtk;
	cout << obj->Get_Info()->szName << "에게 " << Get_CritDamage();
	if (mInfo.iCritical == 2) { cout << " 크리티컬 "; }
	cout << "대미지" << endl;
}