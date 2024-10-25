#include "pch.h"

CCharacter::CCharacter()
{
	strcpy(m_szName, "");
	m_iMaxHP = 0;
	m_iHP = m_iMaxHP;
	m_iAtk = 0;
	m_iCritChance = 10;
	cout << "CCHARACTER Default 생성자 호출" << endl;
}

CCharacter::CCharacter(const char* _szName, int _iAtk, int _iMaxHP)
{
	strcpy(m_szName, _szName);
	m_iMaxHP = _iMaxHP;
	m_iHP = m_iMaxHP;
	m_iAtk = _iAtk;
	m_iCritChance = 10;
	cout << "CCHARACTER "<< _szName << " 생성자 호출" << endl;
}

CCharacter::~CCharacter()
{
	cout << "CCHARACTER "<< m_szName << " 소멸자 호출" << endl;
	Release();
}

void CCharacter::Damaged(int _iDmg)
{
	m_iHP -= _iDmg;
}

void CCharacter::Initialize()
{
	m_iMaxHP = 0;
	m_iHP = 0;
	m_iAtk = 0;
	m_iCritChance = 0;
	strcpy(m_szName, "");
}
void	CCharacter::Update()
{}
void	CCharacter::Release()
{

}
