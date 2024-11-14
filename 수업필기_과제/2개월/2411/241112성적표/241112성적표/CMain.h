#pragma once
#include "pch.h"
#include "CReport.h"

class CMain
{
public:
	CMain() {}
	~CMain() { Release(); }

public:
	void	Initialize();
	void	Update();
	void	Release() {}

public:
	void	AddStudent();
	void	SearchStudent();
	void	DeleteStudent();
	void	PrintStudent();

private:
	vector<CReport> vecStudent;
	vector<CReport>::iterator iter;
};

