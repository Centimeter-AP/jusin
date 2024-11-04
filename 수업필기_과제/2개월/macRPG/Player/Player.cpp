#include "./Player.h"
#include "../Info.h"
#include "../System/System.h"

CPlayer::CPlayer()
{
	cout << GREEN << "CPLAYER" << NOCOLOR << " 생성자 호출" << endl;
	memset(&mInfo, 0, sizeof(mInfo));
	memset(&mPInfo, 0, sizeof(mPInfo));
}

CPlayer::CPlayer(const char* szName, int _iHP, int _iAtk)
{
	strcpy(mInfo.szName, szName);
	mInfo.iMaxHP = _iHP;
	mInfo.iHP = mInfo.iMaxHP;
	mInfo.iAtk = _iAtk;
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100;
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

CPlayer::~CPlayer()
{
	Release();
	cout << RED << "CPLAYER " << mInfo.szName << NOCOLOR << " 소멸자 호출" << endl;
}

void	CPlayer::Initialize()
{
	int iInput(0);
	while(1)
	{
		// system("clear");
		cout << "직업을 선택하세요" << endl;
		cout << "1. 전사  2. 마법사  3. 도적" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(3);
		switch (iInput)
		{
		case CLASS::WARRIOR:
			strcpy(mInfo.szName, "전사");
			mInfo.iMaxHP = 100;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 9;
			break ;
		
		case CLASS::MAGE:
			strcpy(mInfo.szName, "마법사");
			mInfo.iMaxHP = 100;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 10;
			break ;
		
		case CLASS::ROGUE:
			strcpy(mInfo.szName, "도적");
			mInfo.iMaxHP = 90;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 12;
			break ;
		
		default:
			return;
		}
		break ;
	}
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100;
	mPInfo.iMaxExp = 10000;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

void	CPlayer::Release()
{
	return ;
}

void	CPlayer::Print_Info()
{
	cout << "======================================================" << endl;
	cout << setw(55) << right << "소지 골드: " << mInfo.iGold << endl;
	cout << left << "직업 : " << mInfo.szName << "\t레벨 : " << setw(3) << mPInfo.iLvl << right << setw(29) << "다음 레벨까지 : " << setw(5) << mPInfo.iMaxExp - mPInfo.iExp << endl;
	cout << "체력 : " << mInfo.iHP << "\t공격력 : " << mInfo.iAtk << endl;
}
