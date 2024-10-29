#include "./Player.h"

CPlayer::CPlayer()
{
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
}

void	CPlayer::Initialize()
{
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

void	CPlayer::Release()
{
	
}
