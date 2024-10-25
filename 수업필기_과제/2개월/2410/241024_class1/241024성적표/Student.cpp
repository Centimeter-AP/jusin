#include "pch.h"
#include "Student.h"



Student::Student()
{
	cout << "Student Default constructor called" << endl;
}

Student& Student::operator=(const Student& obj)		// 대입연산자 말고 memcpy로 복사해줘도 될 것 같음
{
	cout << "Copy assignment constructor called" << endl;
	if (this != &obj)
	{
		this->m_iKor = obj.m_iKor;
		this->m_iEng = obj.m_iEng;
		this->m_iMath = obj.m_iMath;
		this->m_iTotal = obj.m_iTotal;
		this->m_fAvg = obj.m_fAvg;
		// strcpy_s(this->m_szName, sizeof(m_szName), obj.m_szName);
		strcpy(this->m_szName, obj.m_szName);
	}
	return (*this);
}

Student::~Student()
{
	cout << "Student Default destructor called" << endl;
}

int Student::Get_iKor()
{
	return m_iKor;
}

int Student::Get_iEng()
{
	return m_iEng;
}

int Student::Get_iMath()
{
	return m_iMath;
}

int Student::Get_iTotal()
{
	return m_iTotal;
}

float Student::Get_fAvg()
{
	return m_fAvg;
}

const char* Student::Get_szName()
{
	return m_szName;
}

void Student::Set_szName(const char* _szName)
{
	// strcpy_s(m_szName, sizeof(m_szName), _szName);
	strcpy(m_szName, _szName);
}

void Student::Set_iKor(int _iKor)
{
	m_iKor = _iKor;
}

void Student::Set_iEng(int _iEng)
{
	m_iEng = _iEng;
}

void Student::Set_iMath(int _iMath)
{
	m_iMath = _iMath;
}
