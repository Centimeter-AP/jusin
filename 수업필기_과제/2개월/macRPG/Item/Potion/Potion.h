#pragma once
#ifndef POTION_H
# define POTION_H

# include "../Item.h"

class CCharacter;

class CPotion : public CItem
{
	public:
		CPotion(){strcpy(m_szName, "포션");};;
		~CPotion();

		void	Use(CCharacter *obj);
		void	Explain();
		CItem*	Clone();
};

#endif

#include "../../Character/Character.h"
using namespace std;

CPotion::CPotion()
{}
CPotion::~CPotion()
{}

void	CPotion::Explain()
{
	cout << "포션\n사용자의 체력을 약 40% 회복시켜 줍니다." << endl;
}
void	CPotion::Use(CCharacter *obj)
{
	cout << obj->Get_Info()->szName << "이 포션을 사용합니다." << endl;
	obj->Get_Info()->iHP += (int)((obj->Get_Info()->iMaxHP) * 0.4f);
	if (obj->Get_Info()->iHP > obj->Get_Info()->iMaxHP)
		obj->Get_Info()->iHP = obj->Get_Info()->iMaxHP;
	cout << "최대 체력의 40%가 회복되었습니다." << endl;
}

CItem*	CPotion::Clone()
{
	CItem *pNew = new CPotion;
	return pNew;
}