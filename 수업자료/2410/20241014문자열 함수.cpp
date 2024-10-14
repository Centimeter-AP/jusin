#include <iostream>

#include <string.h>		// c언어 기반의 문자열 함수를 지원
#include <cstring>		// mfc 프로젝트의 문자열 클래스를 지원

#include <string>		// stl 컨테이너로 c++ 기반에서 사용 가능한 operator 집합

using namespace std;

int main()
{
	// 문자열 복사 함수 : 문자열 간의 대입이 불가능하기 때문에 바이트 단위로 메모리 복사를 이용하여 문자열 대입을 대신한다.

	// (복사 받을 문자 배열의 주소, 복사 받을 문자 배열의 메모리 크기, 복사할 문자열의 주소)
	// errno_t strcpy_s(char* _Destination, rsize_t _SizeInBytes,char const* _Source)

	// char	szName[32] = "hello_world";
	// char	szTemp[32] = "after";

	// strcpy_s(szName, sizeof(szName), "helloworld");
	// strcpy_s(szName, sizeof(szName), szTemp);
	// cout << szName << endl;

	// 문자열 결합 함수 : 두 문자열을 하나의 문자열로 결합하여 최종적인 문자열로 만드는 함수

	// (결합한 최종 결과를 저장할 배열의 주소, 결합한 결과를 저장할 배열의 메모리 크기, 결합할 문자열의 주소)
	// errno_t strcat_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source)

	// char	szName[32] = "Hello";
	// char	szTemp[32] = "_World";
	// 
	// strcat_s(szName, sizeof(szName), szTemp);
	// 
	// cout << szName << endl;
	// cout << szTemp << endl;

	// 문자열 길이 구하기 함수 : null문자를 제외한 문자열의 길이를 구하는 기능

	// (문자열 길이를 구하고 싶은 문자 배열의 주소)
	// size_t strlen(char* pName);

	// char	szName[32] = "hello_world";
	// cout << strlen(szName) << endl;

	// 문자열 비교 함수 : 두 문자열의 일치 여부를 판정하는 함수
	// (비교할 문자열 1의 주소, 비교할 문자열 2의 주소)
	// int strcmp( char const* _Str1, char const* _Str2)

	// char	szName[32] = "hello";
	// 
	// if (!strcmp(szName, "hello"))
	// {
	// 	cout << "일치" << endl;
	// }
	// else
	// {
	// 	cout << "불일치" << endl;
	// }

	// 유니코드 기반의 문자열 선언과 함수들의 종류
	// 
	// wchar_t szName[32] = L"";
	// 
	// lstrcpy()
	// lstrcat
	// 
	// lstrcmp
	// lstrlen

	// string 컨테이너의 사용 예
	
	// string		strName = "";	(아스키 코드 기반)
	// wstring		wstrName = L""; (유니 코드 기반)
	// 
	// strName = "대입 가능";
	// cout << strName << endl;
	// 
	// strName += "_결합도 가능";
	// 
	// cout << strName << endl;
	// 
	// cout << strName.size() << endl;
	// cout << strName.length() << endl;
	// 
	// if (strName == "대입 가능_결합도 가능")
	// 	cout << "일치" << endl;


	// char	szName[32] = "hello";
	// string	strTemp = "world";

	// strTemp = szName;
	// szName = strTemp;

	// c_str : 원시 타입의 문자 자료형을 반환
	// strcpy_s(szName, sizeof(szName), strTemp.c_str());

	// cout << szName << endl;
	//cout << strTemp << endl;

	return 0;
}