#pragma once

class Manager	
{
public:
	Manager();
	~Manager();

	int Get_iIndex();
	int Get_iMax();
	Student* Get_Student(int _iIndex);

	void Set_iIndex(int _iIndex);
	void Set_iMax(int _iMax);
	void Set_iAddNum(int _iAddNum);
	
	void Init_StudentList();
	void Add_StudentList(int _iIndex);
	void Delete_StudentList();

private:
	Student* StudentList = nullptr;
	int	m_iMax = 0;
	int m_iIndex = 0;
	int m_iAddNum = 0;

};


