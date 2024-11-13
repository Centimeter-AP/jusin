#include "pch.h"
#include "Bomb.h"
#include "Character.h"
#include "Info.h"
#include "System.h"

void	CBomb::Explain()
{
	cout << "폭탄\n상대의 최대 체력의 약 30% 의 고정 피해를 줍니다." << endl;
}
void	CBomb::Use(CCharacter* obj)
{
	cout << obj->Get_Info()->szName << "에게 폭탄을 사용합니다." << endl;
	obj->Get_Info()->iHP -= (int)((obj->Get_Info()->iMaxHP) * 0.3f);
	if (obj->Get_Info()->iHP < 0)
		obj->Get_Info()->iHP = 0;
	cout << (int)((obj->Get_Info()->iMaxHP) * 0.3f) << "대미지 !" << endl;
}

CItem* CBomb::Clone()
{
	CItem* pNew = new CBomb;
	return pNew;
}