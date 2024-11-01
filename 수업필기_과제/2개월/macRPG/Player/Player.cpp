#include "./Player.h"
#include "../Info.h"
#include "../System/System.h"

CPlayer::CPlayer()
{
	cout << "CPLAYER 생성자 호출" << endl;
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
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

CPlayer::~CPlayer()
{
	Release();
	cout << "CPLAYER " << mInfo.szName << " 소멸자 호출" << endl;
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
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

void	CPlayer::Release()
{
	return ;
}

void	CPlayer::Attack(CCharacter &obj)
{
	if (this->mInfo.iHP <= 0)
		return;
	cout << mInfo.szName << "의 공격!" << endl;
	obj.Get_Info()->iHP -= this->mInfo.iAtk;
	cout << obj.Get_Info()->szName << "에게 " << Get_CritDamage();
	if (mInfo.iCritical == 2){ cout << " 크리티컬 "; }
	cout << "대미지" << endl;
}