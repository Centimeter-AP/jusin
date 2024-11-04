#include "pch.h"
#include "CObj.h"

CObj::CObj()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CObj::CObj(const char* pName, int _iHp, int _iAttack)
{
	strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), pName);
	m_tInfo.iHp = _iHp;
	m_tInfo.iAttack = _iAttack;
}

CObj::~CObj()
{
}

void CObj::Render()
{
	cout << "=================================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}

void CObj::Release()
{
}
