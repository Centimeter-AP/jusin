#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// 메모리 함수 : c언어 시절부터 메모리 단위로 동작을 수행하는 함수를 제공

	// 메모리 초기화 함수 : 특정 메모리를 바이트 단위로 초기화하는 함수

	// memset(초기화 할 메모리 공간의 주소, 바이트 단위로 초기화 할 값, 초기화 할 메모리 공간의 크기)
	// void* memset( void* _Dst, int _Val, size_t _Size);

	// int		iArray[5] = { 1, 2, 3 ,4 ,5 };
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iArray[i] << endl;
	// 
	// memset(iArray, 0, sizeof(iArray));
	// // ZeroMemory(iArray, sizeof(iArray);
	// 
	// cout << "-----------------------------" << endl;
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iArray[i] << endl;

	// memcpy : 메모리 바이트 단위로 값을 복사하는 함수
	
	// memcpy(복사 받을 공간의 첫 번째 주소, 복사할 대상의 첫 번째 주소, 복사 받을 메모리 공간의 크기)
	// void* memcpy(void* _Dst, void const* _Src, size_t  _Size)

	// int		iArray[5] = { 1, 2, 3, 4, 5 };
	// int		iTemp[5] = {};
	
	// memcpy(iTemp, iArray, sizeof(iTemp));

	// memmove(iTemp, iArray, sizeof(iTemp));
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iTemp[i] << endl;


	return 0;

}