#include <iostream>

using namespace std;

int main()
{
	// 2차원 배열을 저장하는 포인터 변수 형식
	int iArr[2][3] = {{},{}};

	int (*pArr)[3] = iArr; // 괄호필요(대괄호가별표보다우선으로붙기때문)



	// 함수 포인터(으)
	// 반환 타입 (*포인터 변수 이름)(매개 변수 형식)
	// void Render();함수가 있었을 시
	void (*pFunc)() = NULL;
	// pFunc = Render;
	// pFunc();

	// int Add(int i, int j); 함수가 있었을 시
	int (*pAdd)(int, int) = NULL; //NULL안넣어도 되는데 함수만들기귀찮아서 주석처리하려고(ㅋㅋ)
	// pAdd = Add;
	// pAdd(10, 20);

	// 함수포인터는 함수포인터배열. 로 쓰는 경우가 많고 효율적이다..
	int (*pFuncArr[3])(int, int) = {NULL};
	// 인덱스마다 함수 넣어서 쓸 수 있으니까 압축돼서 좋았쓰
	// 그러나 C++은 별로좋아하지 않습니다.



	return 0;
}

// 1. 2차원 배열을 이용하여 다음의 상태로 숫자 출력하기
// 1 2 3			 7 4 1
// 4 5 6 -90도 회전>  8 5 2   또 회 전 
// 7 8 9			 9 6 3

// 2. 빙고 게임 만들기
// 5*5배열 1~25 출력
// 입력한 숫자와 일치하는 값을 가진 배열은 *로 출력
// *로 이루어진 가로세로대각선다섯개 있을 시 빙고 1증가
// 5빙고 이상일 시 승리 후 게임 종료
// 빙고의 개수는 매 루프마다 출력
// 예시는... 파일 보세요
// 가능하면 컴퓨터와 배틀모드로(빙고두개로) 만들어볼것

// 3. 숫자 이동 시키기 
// 5*5 0~24 출력하기
// 2(하) 4(왼) 6(우) 8(상)의 메뉴 출력 
// 선택한 번호에 따라 숫자 0을 이동시켜 출력
// 맨 끝줄에서는 이동하지 못하도록 예외처리 하기
// ex)
// 0 1 2			3 1 2
// 3 4 5	하 입력	  0 4 5
// 6 7 8			6 7 8