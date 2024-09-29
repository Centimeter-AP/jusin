#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// int		iData(10);
	// 
	// cout << bitset<8>(iData) << endl;
	// cout << bitset<8>(~iData) << endl;
	// cout << (~iData) << endl;

// 	iData - iData
// 
// 	iData + (~iData) + 1 == 0
// 
// 
//		00001010
// 		11110101
// --------------
// 		11111111
// +		   1
// --------------
//    100000000	 

////////////////////////////////////////////

	// 시프트 연산자(쉬프트 연산자) : 정수만큼 모든 비트를 이동시키는 연산자
	// <<(왼쪽 시프트 연산자), >>(오른쪽 시프트 연산자)

	// char	iNumber(10);
	// 
	// cout << bitset<8>(iNumber) << endl;
	// cout << (iNumber >> 1) << endl;
	// 
	// cout << bitset<8>(iNumber >> 2) << endl;
	// cout << (iNumber >> 2) << endl;		// iNumber / (2^2)
	// 
	// cout << bitset<8>(iNumber << 2) << endl;
	// cout << (iNumber << 2) << endl;		// iNumber * (2^2)

	// 단항 연산자 : 어떤 값을 하나 증가시키거나 또는 하나 감소시키는 역할
	// ++, --

	// int		iTmp(100);

	// ++iTmp;	 // 전위 연산 : 선 연산 후 대입
	// iTmp++;	 // 후위 연산 : 선 대입 후 연산

	// ++(++iTmp);
	// cout << (iTmp) << endl;

	// 축약 연산자(연산자 축약형) : 값이 자기 자신의 값을 증가 또는 감소시킬 경우 연산자의 표기 형태를 줄여서 쓰는 방법
	// +=, -=, *=, /=, %=, <<=, >>=
	
	// int	iTest(5);
	// // iTest = iTest + 10;
	// iTest += 10;
	// cout << iTest << endl;

	return 0;
}