#include "textrpg.h"

void	CinFailException(bool i)
{
	// system("cls");
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
	fLoadfile = fopen("./Data/Save.sav", "rb");
	fread(tInfo->sName, sizeof(char), STR_MIN, fLoadfile);
	fread(&(tInfo->iHp), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->iMaxHp), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->iAtk), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->iCritChance), sizeof(int), 1, fLoadfile);
	tInfo->tPlayerInfo = new PLAYER;
	fread(&(tInfo->tPlayerInfo->iLvl), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->tPlayerInfo->iExp), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->tPlayerInfo->iMaxExp), sizeof(int), 1, fLoadfile);
	fread(&(tInfo->tPlayerInfo->iEquip), sizeof(int), 1, fLoadfile);
	fclose(fLoadfile);
}

void	Save_Game(INFO *tInfo)
{
	FILE*	fSavefile = nullptr;
	fSavefile = fopen("./Data/Save.sav", "wb");
	//fwrite(tInfo, sizeof(char), STR_MIN, fSavefile);
	//fwrite(tInfo, sizeof(int), 4, fSavefile);
	//fwrite(tInfo->tPlayerInfo, sizeof(int), 4, fSavefile);

	fwrite(tInfo->sName, sizeof(char), STR_MIN, fSavefile);
	fwrite(&(tInfo->iHp), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->iMaxHp), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->iAtk), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->iCritChance), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->tPlayerInfo->iLvl), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->tPlayerInfo->iExp), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->tPlayerInfo->iMaxExp), sizeof(int), 1, fSavefile);
	fwrite(&(tInfo->tPlayerInfo->iEquip), sizeof(int), 1, fSavefile);

	// fwrite(tInfo->tPlayerInfo, sizeof(tInfo->tPlayerInfo), 1, fSavefile);
	fclose(fSavefile);
}
