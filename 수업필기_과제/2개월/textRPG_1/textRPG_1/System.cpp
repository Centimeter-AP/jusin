#include "pch.h"
#include "System.h"

void	CSystem::CinFailException(bool i)
{
	// system("pause"); system("cls");
	cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	//sleep(1);
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}