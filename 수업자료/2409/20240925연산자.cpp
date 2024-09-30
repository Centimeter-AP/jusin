#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// 기본 연산자
	// +, -, *, /, %(나머지 연산자)

	// int		iNumber(10);
	// int		iDiv(0);
	// 
	// // 0 나누기 -> NAN(nan : not a number) : 숫자가 아닌 결과가 도출된 상태
	// 
	// cout << (iNumber / iDiv) << endl;
	// cout << (iNumber % iDiv) << endl;

	// sizeof 연산자 : 자료형의 크기를 계산해주는 연산자

	// cout << sizeof(char) << endl;
	// cout << sizeof(short) << endl;
	// cout << sizeof(int) << endl;
	// cout << sizeof(double) << endl;
	// cout << sizeof(bool) << endl;

	// char	cTmp = 'A';
	// char	cSrc = 'B';
	// 
	// cout << sizeof(cTmp + cSrc) << endl;

	// 대입 연산자(=) : 할당 연산자라고도 불림, 오른쪽에서 왼쪽으로 대입이 일어남, 연산자를 기준으로 양쪽 항목의 자료형식이 같아야 한다.

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

	// R - Value 와 L - Value

	// R - Value : 연산자 기준으로 오른쪽에만 위치할 수 있음(리터럴 상수)
	// L - Value : 연산자 기준으로 왼쪽, 오른쪽 모두 위치 할 수 있음

	// int				iTest   = 500;
	// const int		iResult = 0;

	// &iTest;
	// &iResult;
	// &500;

	// iResult = iTest;
	// iTest = iResult;

	//iTest = 300;
	//500 = 400;

	// 관계 연산자 : 두 항목의 대소 관계를 비교하여 참 또는 거짓을 반환
	// >, <, >=, <=, ==(같다), != (같지 않다)

	// int		iDst(10), iSrc(20);
	// 
	// cout << (iDst < iSrc) << endl;
	// cout << (iDst > iSrc) << endl;
	// cout << (iDst <= iSrc) << endl;
	// cout << (iDst >= iSrc) << endl;
	// cout << (iDst == iSrc) << endl;
	// cout << (iDst != iSrc) << endl;

	// 논리 연산자 : 두 논리의 상태에 따라 참 또는 거짓을 반환
	// &&(and), ||(or), !(not)

	// && (and) : 두 논리 모두 참인 경우에만 참을 반환

	// cout << (true  && true) << endl;
	// cout << (false && true) << endl;
	// cout << (true  && false) << endl;
	// cout << (false && false) << endl;

	// || (or) : 두 논리 중 하나라도 참이면 참을 반환
	
	// cout << (true  || true) << endl;
	// cout << (false || true) << endl;
	// cout << (true  || false) << endl;
	// cout << (false || false) << endl;

	// !(not) : 참을 거짓으로 거짓을 참으로 반전시키는 연산자

	// bool	bSelect(true);
	// 
	// cout << bSelect << endl;
	// cout << (!bSelect) << endl;

	////////////////////////////////////////////////////////////
	// 비트 단위 연산자 : 2진수 형식의 코드를 가지고 연산하는 집단, 정수 형식의 데이터만 비트 단위 연산이 가능
	
	// &(and), |(or), ~(not), ^(xor)
	
	// bitset<비트의 수>(2진수로 치환할 값)

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

// 20 ~ 30 까지 2진수로 다시 10진수로 치환하는 과정을 작성해와라.