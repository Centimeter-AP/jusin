#pragma once
#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
	strcpy(m_szName, "");
	m_iMaxHP = 0;
	m_iHP = m_iMaxHP;
	m_iAtk = 0;
	m_iCritChance = 10;
	m_iCritical = 1;
	m_iExp = 0;
	cout << "CMONSTER Default ������ ȣ��" << endl;
}

CMonster::CMonster(const char* _szName, int _iMaxHP, int _iAtk)
{
	strcpy(m_szName, _szName);
	m_iMaxHP = _iMaxHP;
	m_iHP = m_iMaxHP;
	m_iAtk = _iAtk;
	m_iCritChance = 10;
	m_iCritical = 1;
	m_iExp = 0;
	cout << "CMONSTER " << _szName << " ������ ȣ��" << endl;
}

CMonster::~CMonster()
{
	cout << "CMONSTER " << m_szName << " �Ҹ��� ȣ��" << endl;
}

void CMonster::Initialize()
{}
void CMonster::Release()
{}

const char* CMonster::Get_Name()
{
	return m_szName;
}

int CMonster::Get_iHP()
{
	return m_iHP;
}

int CMonster::Get_iAtk()
{
	return m_iAtk;
}

void CMonster::Attack(CPlayer* Player)
{
	if (m_iHP <= 0)
		return;
	cout << m_szName << "�� ����!" << endl;
	cout << Player->Get_Name() << "���� " << Get_CritDamage();
	if (m_iCritical == 2)
	{
		cout << " ũ��Ƽ�� ";
	}
	cout << "�����" << endl;
}

void CMonster::RenderInfo()
{
	cout << "======================================================" << endl;
	cout << "�̸� : " << m_szName << endl;
	cout << "ü�� : " << m_iHP << "\t���ݷ� : " << m_iAtk << endl;
}

int	CMonster::Get_CritDamage()
{
	rand() % 100 >= m_iCritChance ? m_iCritical = 1 : m_iCritical = 2;

	return(m_iAtk * m_iCritical);
}

void CMonster::Damaged(int _iDmg)
{
	m_iHP -= _iDmg;
}
