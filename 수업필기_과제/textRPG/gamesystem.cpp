#include "textrpg.h"

void	CinFailException(bool i)
{
	// system("clear");
	cout << "잘못 입력하셨습니다." << endl;
	sleep(1);
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
	FILE*	fLoadfile = nullptr;
	fLoadfile = fopen("./Data/Save.sav", "rb");

	if (fLoadfile)
	{
		fread(tInfo, sizeof(INFO), 1, fLoadfile);
		fclose(fLoadfile);
		cout << "불러오기 성공" << endl;
		sleep(1);
	}
	else
	{
		cout << "불러오기에 실패했습니다." << endl;
		sleep(1);
	}
		
}

void	Save_Game(INFO *tInfo)
{
	FILE*	fSavefile = nullptr;
	fSavefile = fopen("./Data/Save.sav", "wb");
	if (fSavefile)
	{
		fwrite(tInfo, sizeof(INFO), 1, fSavefile);
		fclose(fSavefile);
		cout << "저장 성공" << endl;
		sleep(1);
	}
	else
	{
		cout << "저장에 실패했습니다." << endl;
		sleep(1);
	}
}
