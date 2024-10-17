#include "textrpg.hpp"

void	CinFailException(bool i)
{
	// system("clear");
	cout << "잘못 입력하셨습니다." << endl;
	// system("pause");
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}

void	Exit_Game() //금단의시스템콜(딱히금단은아니긴함)
{
	write(1, "게임 종료", 14);
	usleep(500000);
	write(1, ".", 1);
	usleep(500000);
	write(1, ".", 1);
	usleep(500000);
	write(1, ".\n", 2);
}

void	Load_Game(INFO *tInfo)
{
	// INFO	*tTmp = new INFO;
	FILE*	fLoadfile = nullptr;
	fLoadfile = fopen("./Save.sav", "rb");
	fread(tInfo, sizeof(tInfo), 1, fLoadfile);
	// Init_info(tInfo, tTmp->sName, tTmp->iHp, tTmp->iAtk, false);
	// tTmp->tPlayerInfo = new PLAYER;
	// fread(tInfo->tPlayerInfo, sizeof(tInfo->tPlayerInfo), 1, fLoadfile);
	// tInfo->tPlayerInfo->iEquip = tTmp->tPlayerInfo->iEquip;
	// tInfo->tPlayerInfo->iExp = tTmp->tPlayerInfo->iExp;
	// tInfo->tPlayerInfo->iLvl = tTmp->tPlayerInfo->iLvl;
	// tInfo->tPlayerInfo->iMaxExp = tTmp->tPlayerInfo->iMaxExp;
	fclose(fLoadfile);
}

void	Save_Game(INFO *tInfo)
{
	FILE*	fSavefile = nullptr;
	fSavefile = fopen("./Save.sav", "wb");
	fwrite(tInfo, sizeof(tInfo), 1, fSavefile);
	// fwrite(tInfo->tPlayerInfo, sizeof(tInfo->tPlayerInfo), 1, fSavefile);
	fclose(fSavefile);
}
