# include "pch.h"
#include "Player.h"

CPlayer::CPlayer()
{
	strcpy(m_szName, "");
	m_iMaxHP = 0;
	m_iHP = m_iMaxHP;
	m_iAtk = 0;
	m_iCritChance = 10;
	m_iLvl = 1;
	m_iExp = 0;
	m_iMaxExp = 100;
	cout << "CPLAYER Default 생성자 호출" << endl;
}

CPlayer::CPlayer(const char *_szName, int _iMaxHP, int _iAtk)
{
	strcpy(m_szName, _szName);
	m_iMaxHP = _iMaxHP;
	m_iHP = m_iMaxHP;
	m_iAtk = _iAtk;
	m_iCritChance = 10;
	m_iLvl = 1;
	m_iExp = 0;
	m_iMaxExp = 100;
	cout << "CPLAYER " << _szName << " 생성자 호출" << endl;
}

CPlayer::~CPlayer()
{
	cout << "CPLAYER "<< m_szName << " 소멸자 호출" << endl;
}

void CPlayer::RenderInfo()
{
	cout << "======================================================" << endl;
	cout << "직업 : " << m_szName << "\t레벨 : " << m_iLvl << "\t다음 레벨까지 : " << m_iMaxExp - m_iLvl << endl;
	cout << "체력 : " << m_iHP << "\t공격력 : " << m_iAtk << endl;
}

void CPlayer::Initialize()
{}
void	CPlayer::Update()
{}
void	CPlayer::Release()
{}
