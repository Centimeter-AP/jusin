#include <iostream>

using namespace std;

int main()
{
	// 주석 : 컴파일러가 코드로 인식하지 않도록 만드는 프로그래밍 도구
	// 단일 주석 : 한 줄만 주석 처리
	// /* */ 복수 주석 : 여러 줄을 주석 처리

#pragma region 변수와 상수 설명

	// 변수와 상수

	// 상수 : 메모리 공간에 값을 저장하되 그 값을 변경 할 수 없는 상태의 자료
	// 읽기는 가능하지만 쓰기가 불가능한 데이터

	// 리터럴 상수 : 이미 규약 또는 규범에 의해서 값이 결정 되어있는 상수
	// 심볼릭 상수 : 프로그래밍 문법에 의해 상수로 지정되는 값(const)

#pragma endregion 

	// 프로그래밍 저장 단위

	// 연산의 최소 단위 : bit
	// 저장의 최소 단위 : byte		

	// 변수 : 프로그래밍 코드 흐름에 따라 값의 형태가 변하는 자료
	
	// int		iNumber;	  // 변수를 '선언'하다
	// int		iNumber = 10; // 변수를 '선언과 동시에 초기화' 하다(c 언어 초기화)
	// int		iNumber(10);  // 변수를 '선언과 동시에 초기화' 하다(c++ 초기화)
	// 
	// cout << iNumber << endl;
	// 
	// iNumber = 20;
	// 
	// cout << iNumber << endl;

	// 정수 타입 자료형
	// short(2), int(4), long(4), long long(8)
	// __int16, __int32, __int64

	// unsigned short		sTemp = 0;		// -32768 ~ 32767
	// 										// 0 ~ 65535
	// sTemp = 32767;
	// sTemp = 32770;
	// sTemp = 65535;
	// 
	// cout << sTemp << endl;

	// 실수 타입 자료형
	// float(4), double(8), long double(8)

	// float		fTime = 0.f;
	// cout << fTime << endl;

	// 문자 타입 자료형
	// char(1), wchar_t(2), string(stl 컨테이너) / wstring

	// 아스키(ASCII)코드

	// SBCS -> MBCS -> WBCS

	// "ABCD"	-> 5BYTE 
	// "ㄱㄴㄷㄹ"-> 9BYTE

	// char	sName = 65;		// 아스키 코드 글자 하나만 저장 가능
	// 
	// sName = 98;
	// sName = 'q';			// 문자
	// 
	// // sName = "hello";		// 문자열
	// 
	// cout << sName << endl;

	// 논리 자료형 : 참 또는 거짓을 표현하기 위한 수단의 값
	// bool(1)

	// bool	bSelect = -1;

	// bool	bSelect = true;
	// bSelect = false;
	// cout << bSelect << endl;

	// int		iInput(0);
	// 
	// cout << "숫자를 입력하세요 : ";
	// cin >> iInput;
	// cout << endl;
	// 
	// cout << "숫자 : " << iInput << endl;

	// 국어, 영어, 수학 점수를 입력 받고, 총점과 평균을 구해서 모두 출력해라
	// 국어 영어 수학 총점 평균
	// ?	?	?	 ?	  ?	

	return 0;
}