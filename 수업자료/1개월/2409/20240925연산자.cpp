#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// �⺻ ������
	// +, -, *, /, %(������ ������)

	// int		iNumber(10);
	// int		iDiv(0);
	// 
	// // 0 ������ -> NAN(nan : not a number) : ���ڰ� �ƴ� ����� ����� ����
	// 
	// cout << (iNumber / iDiv) << endl;
	// cout << (iNumber % iDiv) << endl;

	// sizeof ������ : �ڷ����� ũ�⸦ ������ִ� ������

	// cout << sizeof(char) << endl;
	// cout << sizeof(short) << endl;
	// cout << sizeof(int) << endl;
	// cout << sizeof(double) << endl;
	// cout << sizeof(bool) << endl;

	// char	cTmp = 'A';
	// char	cSrc = 'B';
	// 
	// cout << sizeof(cTmp + cSrc) << endl;

	// ���� ������(=) : �Ҵ� �����ڶ�� �Ҹ�, �����ʿ��� �������� ������ �Ͼ, �����ڸ� �������� ���� �׸��� �ڷ������� ���ƾ� �Ѵ�.

	// int		iData = 100;
	// iData = 3.14f;
	// cout << iData << endl;
	
	// int		iA(10), iB(20), iC(30);
	// 
	// iA = iB;
	// iB = iC;
	// iA = iB = iC = 200;
	// 
	// cout << iA << '\t' << iB << '\t' << iC << endl;

	// R - Value �� L - Value

	// R - Value : ������ �������� �����ʿ��� ��ġ�� �� ����(���ͷ� ���)
	// L - Value : ������ �������� ����, ������ ��� ��ġ �� �� ����

	// int				iTest   = 500;
	// const int		iResult = 0;

	// &iTest;
	// &iResult;
	// &500;

	// iResult = iTest;
	// iTest = iResult;

	//iTest = 300;
	//500 = 400;

	// ���� ������ : �� �׸��� ��� ���踦 ���Ͽ� �� �Ǵ� ������ ��ȯ
	// >, <, >=, <=, ==(����), != (���� �ʴ�)

	// int		iDst(10), iSrc(20);
	// 
	// cout << (iDst < iSrc) << endl;
	// cout << (iDst > iSrc) << endl;
	// cout << (iDst <= iSrc) << endl;
	// cout << (iDst >= iSrc) << endl;
	// cout << (iDst == iSrc) << endl;
	// cout << (iDst != iSrc) << endl;

	// �� ������ : �� ���� ���¿� ���� �� �Ǵ� ������ ��ȯ
	// &&(and), ||(or), !(not)

	// && (and) : �� �� ��� ���� ��쿡�� ���� ��ȯ

	// cout << (true  && true) << endl;
	// cout << (false && true) << endl;
	// cout << (true  && false) << endl;
	// cout << (false && false) << endl;

	// || (or) : �� �� �� �ϳ��� ���̸� ���� ��ȯ
	
	// cout << (true  || true) << endl;
	// cout << (false || true) << endl;
	// cout << (true  || false) << endl;
	// cout << (false || false) << endl;

	// !(not) : ���� �������� ������ ������ ������Ű�� ������

	// bool	bSelect(true);
	// 
	// cout << bSelect << endl;
	// cout << (!bSelect) << endl;

	////////////////////////////////////////////////////////////
	// ��Ʈ ���� ������ : 2���� ������ �ڵ带 ������ �����ϴ� ����, ���� ������ �����͸� ��Ʈ ���� ������ ����
	
	// &(and), |(or), ~(not), ^(xor)
	
	// bitset<��Ʈ�� ��>(2������ ġȯ�� ��)

	int		iDst(10), iSrc(13);


	cout << bitset<8>(iDst) << endl;
	//cout << bitset<8>(iSrc) << endl;

	//cout << "-------------------&----------------------" << endl;
	//cout << bitset<8>(iDst & iSrc) << endl;
	//cout << (iDst & iSrc) << endl;
	
	// cout << "-------------------|----------------------" << endl;
	// cout << bitset<8>(iDst | iSrc) << endl;
	// cout << (iDst | iSrc) << endl;

	// cout << "-------------------^----------------------" << endl;
	// cout << bitset<8>(iDst ^ iSrc) << endl;
	// cout << (iDst ^ iSrc) << endl;
	
	// cout << "-------------------~----------------------" << endl;
	// cout << bitset<8>(~iDst) << endl;
	// cout << (~iDst) << endl;

	return 0;
}

// 20 ~ 30 ���� 2������ �ٽ� 10������ ġȯ�ϴ� ������ �ۼ��ؿͶ�.