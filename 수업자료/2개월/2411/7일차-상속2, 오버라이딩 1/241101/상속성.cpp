#include "pch.h"

class CBase
{
public:
	void		Render_Base() { cout << "CBase" << endl; }
};

class CDerived : public CBase
{
public:
	void		Render_Derived() { cout << "CDerived" << endl; }
};

class CTemp : public CDerived
{
public:
	void		Render_Temp() { cout << "CTemp" << endl; }
};

int main()
{
	// ���� ���ε�(static binding) : ������ Ÿ�� ��, �̹� � �Լ��� ȣ�� �� �� ���� �Ǿ�����.

	CDerived*		pDerived = new CDerived;	// ������ ��ü
	
	// pDerived->Render_Base();
	// pDerived->Render_Derived();
	// pDerived->Render_Temp();

	return 0;
}