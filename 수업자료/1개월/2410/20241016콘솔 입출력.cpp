#include <iostream>

using namespace std;

int main()
{
	// 콘솔 입출력

	// 텍스트 모드 : 문자열의 형태로 사용자가 알아 볼 수 있는 모드
	// 바이너리 모드 : 2진수 형태로 사용자가 알아보기 어려운 형태의 모드

	// 문자열 입출력 함수

	// 표준 콘솔 입출력 스트림의 종류

	// - stdin  : 표준 입력 스트림(기본 키보드 대상)
	// - stdout : 표준 출력 스트림(기본 모니터 대상)
	// - stderr : 표준 에러 스트림(기본 모니터 대상)

	/////////////////////////////////////////////////////
	// 1. 단일 문자 출력 함수 : 아스키 코드 한 글자를 출력하는 함수

	// putchar(65);				// 콘솔 출력에만 사용 가능(stdout으로 고정)
	// putchar('S');

	// fputc('A', stdout);		// 매개 변수에 스트림 종류를 설정, 범용적으로 각종 입출력에서 사용

	// 2. 단일 문자 입력 함수 : 아스키 코드 한 글자만 입력 받는 함수

	// char	cName = getchar();	// 콘솔 입력에만 사용 가능(stdin으로 고정)
	// putchar(cName);

	// char cTemp = fgetc(stdin);
	// fputc(cTemp, stdout);

	// EOF(end of file) : 파일의 끝에 도달했음을 알려주는 -1에 해당하는 함수

	// while (true)
	// {
	// 	char	ch = getchar();
	// 
	// 	if (EOF == ch)			// ctrl + z을 누를 경우 콘솔 입출력 시, EOF가 발생
	// 		break;
	// 
	// 	if ('a' <= ch && 'z' >= ch)
	// 		ch -= 32;
	// 
	// 	else if ('A' <= ch && 'Z' >= ch)
	// 		ch += 32;
	// 
	// 	putchar(ch);
	// }

	// 3. 문자열 출력 함수 : 문자열을 출력하는 함수

	// puts("hello");			// 콘솔 출력에만 사용 가능(자동 개행 지원)
	// fputs("world", stdout); // 범용적으로 사용 가능(자동 개행 지원하지 않음)
	
	// \r : carriage return : 줄의 맨 앞으로 당기는 명령어

	// 4. 문자열 입력 함수 : 문자열을 입력하는 함수

	// char	szName[10] = "";

	// gets_s(szName);		// 공백(space)에 입출력이 가능, enter는 문자열로 읽을 수 없음
	// puts(szName);

	// fgets(szName, sizeof(szName), stdin); // enter를 읽어 들여 설정한 사이즈만큼만 읽어들일 수 있음
	// fputs(szName, stdout);

	// cin >> szName;
	// cout << szName << endl;

	// 5. 출력 버퍼 비우기 함수 : fflush
	
	// - 입력 버퍼는 강제로 비우기가 불가능
	// - 출력 버퍼를 비우는 작업 또한 자주 하지 않는다.

	// char	szID[9] = "";
	// char	szName[16] = "";
	// 
	// fgets(szID, sizeof(szID), stdin);
	// 
	// while ('\n' != getchar());
	// 
	// fgets(szName, sizeof(szName), stdin);
	// 
	// fputs(szID, stdout);
	// fputs(szName, stdout);
	

	return 0;
}