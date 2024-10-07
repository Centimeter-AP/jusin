#include <iostream>

using namespace std;

int main()
{
#pragma region 포인터 연산

	// 포인터 연산 : 포인터가 현재 참조하는 주소 공간에서 연산자에 의해 다른 공간을 가리키도록 하는 연산
	// 참조하는 자료형의 크기만큼 메모리 이동을 한다

	// int		iDst(0);
	// 
	// int*	p = &iDst;
	// 
	// cout << p << endl;
	// cout << *p << endl;
	// 
	// p++;		// 포인터 연산의 예
	// //p += 2;
	// 
	// cout << p << endl;		// 댕글링 포인터 : 접근을 허용받지 않은 주소를 참조하고 있는 포인터
	// cout << *p << endl;
	// 
	// *p = 100;		// 잘못된 접근 임에도 불구하고 작동은 우선 수행되었음
	// cout << *p << endl;

#pragma endregion
	
#pragma region 포인터 종류
	
	// int	iNumber(10);

	// 주소 또한 형 변환이 가능함
	// float* pNumber = (float*)&iNumber;

	// const int* p = &iNumber;				// 읽기 전용 포인터 : 참조 대상의 값 변경이 불가능
	
	// int* const  p = &iNumber;			// 상수 포인터 : 오로지 하나의 대상만 참조 가능한 포인터
	// const int* const  p = &iNumber;		// 읽기 전용 상수 포인터

	// *p = 20;		// 읽기 전용 포인터 : 값 쓰기 불가능해짐
	// 				// 상수 포인터 : 값 쓰기 가능해짐
	// 
	// int	iDst(500);
	// p = &iDst;		// 읽기 전용 포인터 : 주소값 변경은 가능
	// 					// 상수 포인터 : 주소값 변경이 불가능
	// 
	// *p = 600;		// 읽기 전용 포인터 : 값 쓰기 불가능해짐
	// 				// 상수 포인터 : 값 쓰기 가능해짐
	// 
	// cout << iNumber << endl;
	// cout << iDst << endl;

#pragma endregion

#pragma region 2차원 포인터

	// int		iNumber(0);
	// 
	// int*	p = &iNumber;
	//  
	// int**	pp = &p;
	// 
	// cout << p << endl;
	// cout << pp << endl;
	// 
	// cout << *p << endl;	 // 10
	// cout << *pp << endl;

#pragma endregion

	return 0;
}
