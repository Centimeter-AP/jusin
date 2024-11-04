#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::Select_Job()
{
	int		iInput(0);

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
	cin >> iInput;

	switch (iInput)
	{
	case CPlayer::WARRIOR:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	case CPlayer::MAGE:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	case CPlayer::THIEF:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "도적");
		m_tInfo.iHp = 100;
		m_tInfo.iAttack = 10;
		break;

	default:
		cout << "잘못 입력" << endl;
		break;
	}
}
