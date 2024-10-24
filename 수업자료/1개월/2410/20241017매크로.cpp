#include <iostream>

using namespace std;

// 상수 매크로 : 단순 치환이란 동작으로 속도가 빠르고 직관적임, 그러나 컴파일 타임에 매크로의 문제를 파악 할 수 없다.

#define		PI			3.14f
#define		MIN_STR		32
#define		MAX_STR		256

// 함수 매크로 : 함수의 모양의 띈 매크로, 단순한 코드 수준을 매크로화 시킴
// 
// 사용하고자 하는 자료형에 제한이 없음
// 연산자 우선 순위를 고려하지 않고 단순 치환만 수행
// 될 수 있으면 한 줄짜리 단일 코드로 매크로로 만들 것을 권장

#define		SQUARE(X)		((X) \
* (X))	

// 함수 매크로의 다양한 문법

// 특정 항목을 문자열로 치환시키큰 문법
#define		STRING(A, B)	#A "의 직업은 "   #B "입니다"

// 매크로 인자의 결합
#define		COMBINE(A, B)		A##B

// 함수 매크로 사용 예

#define		SAFE_DELETE(p)		if(p) {	delete p; 	p = nullptr; }


int main()
{
	// cout << PI << endl;
	// 
	// int* p = NULL;
	// 
	// char	szMin[MIN_STR] = "";
	// char	szMax[MAX_STR] = "";

	// cout << SQUARE(10) << endl;
	// cout << SQUARE(20l) << endl;
	// cout << SQUARE(1.1f) << endl;
	// cout << SQUARE(1.245) << endl;

	//cout << SQUARE(2 + 2) << endl;
	// cout << 2 + 2 * 2 + 2 << endl;

	//cout << STRING(홍길동, 의적) << endl;
	// cout << COMBINE(10, 20) << endl;

	int* p = new int;

	SAFE_DELETE(p);

	return 0;
}