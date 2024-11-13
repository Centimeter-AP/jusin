#include "pch.h"
#include "Bomb.h"
#include "Character.h"
#include "Info.h"
#include "System.h"

void	CBomb::Explain()
{
	cout << "��ź\n����� �ִ� ü���� �� 30% �� ���� ���ظ� �ݴϴ�." << endl;
}
void	CBomb::Use(CCharacter* obj)
{
	cout << obj->Get_Info()->szName << "���� ��ź�� ����մϴ�." << endl;
	obj->Get_Info()->iHP -= (int)((obj->Get_Info()->iMaxHP) * 0.3f);
	if (obj->Get_Info()->iHP < 0)
		obj->Get_Info()->iHP = 0;
	cout << (int)((obj->Get_Info()->iMaxHP) * 0.3f) << "����� !" << endl;
}

CItem* CBomb::Clone()
{
	CItem* pNew = new CBomb;
	return pNew;
}