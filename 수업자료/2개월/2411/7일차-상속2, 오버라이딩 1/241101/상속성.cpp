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
	// 정적 바인딩(static binding) : 컴파일 타임 때, 이미 어떤 함수를 호출 할 지 결정 되어있음.

	CDerived*		pDerived = new CDerived;	// 생성된 객체
	
	// pDerived->Render_Base();
	// pDerived->Render_Derived();
	// pDerived->Render_Temp();

	return 0;
}