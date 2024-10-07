#include <iostream>

using namespace std;

int main()
{
	// 포인터 : 주소값을 저장하는 용도의 변수
	
	// 포인터는 주소값만 소유하면 메모리 공간의 접근하여 값을 읽거나 쓰기가 가능하다.

	// int*	p = NULL;		// int형 포인터 p를 선언하다.
	// cout << sizeof(p) << endl;

	// int* p = nullptr;		// c++에서 포인터 초기화 도구로 등장
	// 
	// int	iData(10);
	// 
	// // iData = 20;
	// 
	// p = &iData;		// address 연산자 : 변수의 첫 번째 주소를 추출하여 반환
	// 
	// *p = 20;		// 주소를 통한 메모리 공간에 값 쓰기
	// 
	// // cout << *(&iData) << endl;		// 직접 참조
	// // cout << (*p) << endl;			// 간접 참조 : 포인터 변수를 통해 대신하여 메모리 공간에 접근
	// 									// 주소를 통한 메모리 공간에 값 읽기
	// // cout << p << endl;
	// cout << iData << endl;

	int		iDst(10), iSrc(20);

	cout << iDst << "\t" << iSrc << endl;

	int	iTmp(0);

	iTmp = iDst;
	iDst = iSrc;
	iSrc = iTmp;

	cout << iDst << "\t" << iSrc << endl;

	return 0;
}

// 1. 5 팩토리얼의 결과를 재귀 함수를 통해 구현하라
// (힌트) 0! 은 값이 1이다.
// 
// 5 * 4 * 3 * 2 * 1 = 120

// 2. 셔플 알고리즘의 개념을 함수에 적용하여 구현하라(포인터를 이용해 볼 것)