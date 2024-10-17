#include <iostream>

using namespace std;

int main()
{
	// c언어 파일 개방 함수

	// fopen_s(개방한 스트림을 저장할 포인터의 주소, 파일 이름을 포함한 파일의 경로, 모드)
	// errno_t fopen_s(FILE **_Stream, char const* _FileName, char const* _Mode)

	// c언어 파일 소멸 함수
	// int fclose(FILE* _Stream)

// 파일 출력(저장)

	// FILE* pFile = NULL;		// 파일 스트림
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");
	// 
	// if (0 == err)		// 파일 개방 성공
	// {
	// 	// fputs("hello", stdout);	// 콘솔 출력
	// 	fputs("hello", pFile);		// 파일 출력
	// 
	// 	cout << "저장 성공" << endl;
	// 
	// 	fclose(pFile);
	// }
	// 
	// else
	// {
	// 	cout << "파일 개방 실패" << endl;
	// }

// 파일 입력(불러오기)

	// FILE* pReadFile = NULL;		// 파일 스트림
	// 
	// errno_t err = fopen_s(&pReadFile, "../Data/Test.txt", "rt");
	// 
	// char	szName[32] = "";
	// 
	// if (0 == err)		// 파일 개방 성공
	// {
	// 	// fgets(szName, sizeof(szName), stdin); // 콘솔 입력
	// 	fgets(szName, sizeof(szName), pReadFile);
	// 
	// 	cout << "불러오기 성공" << endl;
	// 
	// 	fputs(szName, stdout);	// 콘솔 출력
	// 
	// 	fclose(pReadFile);
	// }
	// 
	// else
	// {
	// 	cout << "파일 개방 실패" << endl;
	// }

// 파일 함수 : 파일 입출력 시, 지원되는 c언어 시절의 함수

	// fseek : 파일의 커서를 원하는 위치로 이동시키는 함수
	
	// _Offset : 이동할 바이트 수
	// _Origin : 커서의 시작 지점
	// int fseek(FILE * _Stream, long  _Offset, int   _Origin);
	
	// ftell : 커서의 위치를 알려주는 함수

	// FILE* pFile = NULL;
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");
	// 
	// if (0 == err)
	// {
	// 	fseek(pFile, 3, SEEK_SET);
	// 
	// 	char cTest = fgetc(pFile);
	// 
	// 	cout << "현재 커서의 위치 : " << ftell(pFile) << endl;
	// 	cout << "현재 글자 : " << cTest;
	// 
	// 	fclose(pFile);
	// }

	// feof : 파일 커서가 eof에 도달했는지 알려주는 함수, EOF에 도달했다면 0이 아닌 값을 리턴

	// FILE* pFile = NULL;
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");
	// 
	// if (0 == err)
	// {
	// 	while (0 == feof(pFile))
	// 	{
	// 		fputc(fgetc(pFile), stdout);
	// 	}
	// 
	// 	fclose(pFile);
	// }

	return 0;
}