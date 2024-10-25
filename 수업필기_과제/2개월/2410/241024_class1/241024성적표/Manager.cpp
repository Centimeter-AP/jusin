#include "pch.h"
#include "Manager.h"

Manager::Manager()
{
	cout << "Manager Default constructor called" << endl;
}

Manager::~Manager()
{
	cout << "Manager Default destructor called" << endl;
}

int Manager::Get_iIndex()
{
	return m_iIndex;
}

int Manager::Get_iMax()
{
	return m_iMax;
}

Student* Manager::Get_Student(int _iIndex)
{
	return &(StudentList[_iIndex]);
}

void Manager::Set_iIndex(int _iIndex)
{
	m_iIndex = _iIndex;
}

void Manager::Set_iMax(int _iMax)
{
	m_iMax = _iMax;
}

void Manager::Set_iAddNum(int _iAddNum)
{
	m_iAddNum = _iAddNum;
}

void Manager::Init_StudentList()
{
	if (StudentList)
	{
		Student* NewList = new Student[m_iMax + m_iAddNum];

		for (int i = 0; i < m_iMax; ++i)
		{
			NewList[i] = StudentList[i];
			Set_iIndex(i + 1);
		}

		delete[] StudentList;
		StudentList = NewList;
	}
	else
		StudentList = new Student[m_iMax + m_iAddNum];

	Set_iMax(m_iMax + m_iAddNum);
}

void Manager::Add_StudentList(int _iIndex)
{
	//for (int i = m_iIndex; i < m_iMax; ++i)
	//{

	//}
	//StudentList->Set_iEng
}

void Manager::Delete_StudentList()
{
	if (StudentList)
		delete[] StudentList;
	StudentList = nullptr;
}
