#pragma once
#ifndef CSYSTEM_H
# define CSYSTEM_H

# include "pch.h"

class CSystem
{
public:
	static void	CinFailException(bool i);
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
void	Safe_Delete_Arr(T& p)
{
	if (p)
	{
		delete[] p;
		p = nullptr;
	}
}
#endif

