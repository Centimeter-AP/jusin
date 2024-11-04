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
	// ������ : �θ� �ڷ����� �ٸ� �ڷ����� ���·� ��ȯ�Ͽ� ��� �� �� �ֵ��� ����� ����
	// �ڽ� �ڷ����� ����� ����ϱ� ���� ����ϴ� ����

	// 1. �������̵� : ��� �޴� �ڽĵ��� ���������� ����� ���� �Լ� ȣ��
	// 2. �ٿ� ĳ���� : ��� �޴� �ڽĵ��� �������� ����� ����� �� 

	////////////////////////////////////////////////////////////

	// �������̵��� ���� 
	// 
	// 1. Ŭ������ ��� ����
	// 2. �θ�� �ڽ� Ŭ������ ���°� �Ϻ��� ��ġ�ϴ� �Լ��� �� �� ������� �־�� ��
	// 3. �θ� Ŭ������ �Լ� �տ� virtual Ű���� �پ� �־�� ��

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