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
	cout << "CMONSTER Default 생성자 호출" << endl;
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
	cout << "CMONSTER " << _szName << " 생성자 호출" << endl;
}

CMonster::~CMonster()
{
	cout << "CMONSTER " << m_szName << " 소멸자 호출" << endl;
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
	cout << m_szName << "의 공격!" << endl;
	cout << Player->Get_Name() << "에게 " << Get_CritDamage();
	if (m_iCritical == 2)
	{
		cout << " 크리티컬 ";
	}
	cout << "대미지" << endl;
}

void CMonster::RenderInfo()
{
	cout << "======================================================" << endl;
	cout << "이름 : " << m_szName << endl;
	cout << "체력 : " << m_iHP << "\t공격력 : " << m_iAtk << endl;
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
