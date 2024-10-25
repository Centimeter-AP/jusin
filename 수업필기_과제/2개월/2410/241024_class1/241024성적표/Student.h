#pragma once

class Student
{
public:
	Student();
	Student& operator=(const Student& obj);
	~Student();

	int		Get_iKor();
	int		Get_iEng();
	int		Get_iMath();
	int		Get_iTotal();
	float	Get_fAvg();
	const char* Get_szName();

	void Set_szName(const char* _szName);
	void Set_iKor(int _iKor);
	void Set_iEng(int _iEng);
	void Set_iMath(int _iMath);

private:
	char m_szName[32] = {};
	int m_iKor = 0;
	int m_iEng = 0;
	int m_iMath = 0;
	int m_iTotal = 0;
	float m_fAvg = 0.0f;
};