#pragma once
#include "pch.h"

class CReport
{
public:
	CReport() : sName("Default"), iKor(0), iEng(0), iMat(0), iTotal(0), fAvg(0.f) {}
	CReport(string _sName, int _iKor, int _iEng, int _iMat) : sName(_sName), iKor(_iKor), iEng(_iEng), iMat(_iMat)
	{
		iTotal = iKor + iEng + iMat;
		fAvg = (float)iTotal / 3.f;
	}
	~CReport() {}
	CReport(const CReport& rhs) { *this = rhs; }
	CReport& operator =(const CReport& rhs)
	{
		this->sName = rhs.sName;
		this->iKor = rhs.iKor;
		this->iEng = rhs.iEng;
		this->iMat = rhs.iMat;
		this->iTotal = rhs.iTotal;
		this->fAvg = rhs.fAvg;

		return *this;
	};

public:
	void	Render() const
	{
		cout << "�̸� : " << sName << endl;
		cout << "���� : " << iKor << "\t���� : " << iEng << "\t���� : " << iMat << endl;
		cout << "���� : " << iTotal << "\t��� : " << fAvg << endl;
	}
	string& Get_Name() { return sName; }

private:
	string	sName;
	int		iKor;
	int		iEng;
	int		iMat;
	int		iTotal;
	float	fAvg;
};

