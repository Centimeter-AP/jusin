#include "pch.h"

class CBase
{
public:
	virtual void	Render() { cout << "CBase" << endl; }

	virtual void	Print() { cout << "base Print" << endl; }
}
class CDerived : public CBase
{
public:
	virtual void	Render() { cout << "CDerived" << endl; }
};

int main()
{
	// 다형성 : 부모 자료형을 다른 자료형의 형태로 변환하여 사용 할 수 있도록 만드는 문법
	// 자식 자료형의 기능을 사용하기 위해 사용하는 문법

	// 1. 오버라이딩 : 상속 받는 자식들이 공통적으로 사용할 만한 함수 호출
	// 2. 다운 캐스팅 : 상속 받는 자식들이 개별적인 기능을 사용할 때 

	////////////////////////////////////////////////////////////

	// 오버라이딩의 조건 
	// 
	// 1. 클래스가 상속 관계
	// 2. 부모와 자식 클래스에 형태가 완벽히 일치하는 함수가 둘 다 만들어져 있어야 함
	// 3. 부모 클래스의 함수 앞에 virtual 키워드 붙어 있어야 함

	// CBase* pBase = new CDerived;
	//  
	// pBase->Render();

	//cout << sizeof(CBase) << endl;
	//cout << sizeof(CDerived) << endl;

	// CBase* pBase	= new CBase;
	// __vfptr = 0x00007ff707f5cc18 {241101.exe!void(*CBase::`vftable'[3])()} { 0x00007ff707f515dc {241101.exe!CBase::Render(void)}, ... }
	// [0] = 0x00007ff707f515dc {241101.exe!CBase::Render(void)}
	// [1] = 0x00007ff707f515e6 {241101.exe!CBase::Print(void)}
	
	// CBase* pDerived = new CDerived;
	//__vfptr = 0x00007ff707f5ce08 {241101.exe!void(*CDerived::`vftable'[3])()} { 0x00007ff707f515eb {241101.exe!CDerived::Render(void)}, ... }
	// [0] = 0x00007ff707f515eb {241101.exe!CDerived::Render(void)}
	// [1] = 0x00007ff707f515e6 {241101.exe!CBase::Print(void)}

	cout << sizeof(CDerived) << endl;


	return 0;
}