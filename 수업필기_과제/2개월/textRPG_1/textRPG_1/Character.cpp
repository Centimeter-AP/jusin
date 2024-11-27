#include "pch.h"
#include "Character.h"
#include "Info.h"
#include "Item.h"
#include "System.h"

CCharacter::CCharacter()
{
	memset(&mInfo, 0, sizeof(mInfo));
	vecItemInv.reserve(ITEMINVMAX);

	cout << GREEN << "CCHARACTER" << NOCOLOR << " 생성자 호출" << endl;
}
CCharacter::~CCharacter()
{
	//for_each(vecItemInv.begin(), vecItemInv.end(), Safe_Delete<CItem*>);
	cout << RED << "CCHARACTER " << mInfo.sName << NOCOLOR << " 소멸자 호출" << endl;
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
		cout << "구매하였습니다" << endl;
	}
	else
		cout << "인벤토리에 공간이 없습니다." << endl;
}

void	CCharacter::Attack(CCharacter* obj)
{
	if (this->mInfo.iHP <= 0)
		return;
	cout << mInfo.sName << "의 공격!" << endl;
	obj->Get_Info()->iHP -= this->mInfo.iAtk;
	cout << obj->Get_Info()->sName << "에게 " << Get_CritDamage();
	if (mInfo.iCritical == 2) { cout << " 크리티컬 "; }
	cout << "대미지" << endl;
}