#include "pch.h"
#include "Potion.h"
#include "Character.h"
#include "Info.h"
#include "System.h"

void	CPotion::Explain()
{
	cout << "������� ü���� �� 40 % ȸ������ �ݴϴ�.";
}
void	CPotion::Use(CCharacter* obj)
{
	cout << obj->Get_Info()->szName << "�� ������ ����մϴ�." << endl;
	obj->Get_Info()->iHP += (int)((obj->Get_Info()->iMaxHP) * 0.4f);
	if (obj->Get_Info()->iHP > obj->Get_Info()->iMaxHP)
		obj->Get_Info()->iHP = obj->Get_Info()->iMaxHP;
	cout << "�ִ� ü���� 40%�� ȸ���Ǿ����ϴ�." << endl;
}

CItem* CPotion::Clone()
{
	CItem* pNew = new CPotion;
	return pNew;
}