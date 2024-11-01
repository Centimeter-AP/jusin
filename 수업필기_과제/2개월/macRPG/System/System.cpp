#include "./System.h"

void	CSystem::CinFailException(bool i)
{
	// system("clear");
	cout << "잘못 입력하셨습니다." << endl;
	sleep(1);
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}