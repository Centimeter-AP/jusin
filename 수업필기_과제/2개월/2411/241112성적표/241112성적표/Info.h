#pragma once
#include "pch.h"

#define CINEXCEPTION(P) if (cin.fail() || iInput > P || iInput < 1) {CinFailException(cin.fail()); continue;}

enum Select
{
	ADD = 1,
	PRINT,
	SEARCH,
	DELETE,
	END
};

template <typename T>
void	Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

template <typename T>
void	Safe_Delete_Array(T& pArr)
{
	if (pArr)
	{
		delete[] pArr;
		pArr = nullptr;
	}
}


void	CinFailException(bool i)
{
	// system("pause"); system("cls");
	cout << "잘못 입력하셨습니다." << endl;

	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}