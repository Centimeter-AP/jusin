#include <iostream>

using namespace std;

int main()
{
	
	// 문자 : 1byte 단위의 글자 한 글자(아스키 코드)
	// 문자열 : 2byte이상의 글자 상태(아스키 코드 두 글자 이상 또는 유니 코드 한 글자이상)

	// 문자열 무조건 배열(연속적인 메모리 공간)에 저장하여 사용해야 한다.


	// 문자 배열
	// char	szName[] = "hello world";	// 상수 문자열
	// char	szTemp[6] = {'j', 'u', 's', 'i', 'n'};
	// char szTemp[6] = "jusin";	// 상수 문자열에 끝에는 자동으로 NULL문자가 삽입되어 있다.

	// '\0' : NULL문자(문자열의 끝을 의미하는 1바이트 문자)
	// NULL 문자의 크기를 고려하여 배열의 크기를 넉넉하게 잡아야 한다.

	// cout << szTemp << endl;

	// for (int i = 0; i < 5; ++i)
	// 	cout << szTemp[i];
	// 
	// cout << endl;

	// 컴파일 타임에 할당한 배열로는 문자열의 유동적인 상황에 대처 할 수 없다.
	// 
	// char	szName[5] = "";
	// cin >> szName;
	// cout << szName << endl;

	// 문자열 포인터
	// const char*	pName = "hello world";	
	// 상수 문자열 상태는 저장된 임시 공간의 첫 번째 주소가 리턴된 상황

	// cin >> pName;		// 읽기 전용이어서 입력이 불가
	// cout << pName << endl;
	
	return 0;
}

// 1. 문자열을 입력 받고 null문자를 제외한 순수한 문자열의 길이를 구하는 함수 만들기
// -> "jusin" : 5
// 
// 2. 입력 받은 문자열을 뒤집어 출력하라.
// -> "jusin" : nisuj