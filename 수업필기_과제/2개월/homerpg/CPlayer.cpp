#pragma once
#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	strcpy(m_szName, "");
	m_iMaxHP = 0;
	m_iHP = m_iMaxHP;
	m_iAtk = 0;
	m_iCritChance = 10;
	m_iCritical = 1;
	m_iLvl = 1;
	m_iExp = 0;
	m_iMaxExp = 100;
	cout << "CPLAYER Default 생성자 호출" << endl;
}

CPlayer::CPlayer(const char* _szName, int _iMaxHP, int _iAtk)
{
	strcpy(m_szName, _szName);
	m_iMaxHP = _iMaxHP;
	m_iHP = m_iMaxHP;
	m_iAtk = _iAtk;
	m_iCritChance = 10;
	m_iCritical = 1;
	m_iLvl = 1;
	m_iExp = 0;
	m_iMaxExp = 100;
	cout << "CPLAYER " << _szName << " 생성자 호출" << endl;
}

CPlayer::~CPlayer()
{
	
	cout << "CPLAYER " << m_szName << " 소멸자 호출" << endl;
}

void CPlayer::RenderInfo()
{
	cout << "======================================================" << endl;
	cout << "직업 : " << m_szName << "\t레벨 : " << m_iLvl << "\t다음 레벨까지 : " << m_iMaxExp - m_iExp << endl;
	cout << "체력 : " << m_iHP << "\t공격력 : " << m_iAtk << endl;
}

int	CPlayer::Get_CritDamage()
{
	rand() % 100 >= m_iCritChance ? m_iCritical = 1 : m_iCritical = 2;

	return(m_iAtk * m_iCritical);
}


void CPlayer::Initialize()
{}
void	CPlayer::Release()
{}

void CPlayer::Set_FullHP()
{
	m_iHP = m_iMaxHP;
}

void CPlayer::Set_iHP(int _iHP)
{
	m_iHP = _iHP;
}

void CPlayer::Set_iExp(int _iExp)
{
	if (m_iExp + _iExp < m_iMaxExp && m_iExp + _iExp > 0)
		m_iExp += _iExp;
	else if (m_iExp + _iExp < 0)
		m_iExp = 0;
	else if (m_iExp + _iExp >= m_iMaxExp)
	{
		m_iExp = m_iExp + _iExp - m_iMaxExp;
		m_iLvl++;
		cout << "레벨 업 !\n체력이 회복됩니다." << endl;
		Set_FullHP();
		m_iMaxExp = (int)(1.1f * m_iMaxExp);
	}
}

const char* CPlayer::Get_Name()
{
	return m_szName;
}

int CPlayer::Get_iHP()
{
	return m_iHP;
}

void CPlayer::Attack(CMonster* Monster)
{
	if (m_iHP <= 0)
		return;
	cout << m_szName << "의 공격!" << endl;
	Monster->Damaged(m_iAtk);
	cout << Monster->Get_Name() << "에게 " << Get_CritDamage();
	if (m_iCritical == 2)
	{
		cout << " 크리티컬 ";
	}
	cout <<"대미지" << endl;
}

void CPlayer::Damaged(int _iDmg)
{
	m_iHP -= _iDmg;
}
