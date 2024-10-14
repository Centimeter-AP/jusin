#include <iostream>

// 문 자 열 
// 배열 & 포인터..


using namespace std;

int main()
{
	char sTmp[32] = "hello world";
	const char *pCon;
	char *pNo;
	const char *pTest = "hi Hello";

	pCon = sTmp;
	pNo = sTmp;

	cout << pCon << endl;
	cout << pTest << endl;

	sTmp[0] = 'A';
	cout << pCon << endl;
	cout << pNo << endl;

	cout << *("hi"+1);
	return 0;
}

// 1. 문자열을 입력 받고 null문자를 제외한 순수한 문자열의 길이... 이거 strlen이잖아....
// 2. 입력받은 문자열을 뒤집어 출력하기
