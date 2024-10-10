#include <iostream>

using namespace std;

#pragma region 배열의 규칙

// int main()
//{
//	// 배열의 규칙
//
//	int iDst(0);
//	int iSrc(1);
//	const int	iTmp(3);
//
//	// 블록 단위 데이터 ( { } : 블록단위 데이터 초기화 방식)
//	int	iArray[3] = { };
//
//	for (int i = 0; i < sizeof(iArray) / sizeof(int); ++i)
//	{
//		cout << iArray[i] << endl;
//	}
//
//	// cout << iArray[0] + iArray[1] << endl;
//	//cout << iArray[1 + 1] << endl;
//
//	// cout << sizeof(iArray) << endl;	// 배열 전체의 크기를 구함
//	// 
//	// cout << sizeof(iArray) / sizeof(int) << endl;	// 배열 원소의 개수를 구함
//	// cout << size(iArray) << endl;	// 모던 c++이후에 배열의 개수를 구해주는 함수가 추가됨
//
//	//cout << iArray[0] << endl;
//	//cout << iArray[1] << endl;
//	//cout << iArray[2] << endl;
//
//	// 1. 배열의 이름은 배열 전체의 첫 번째 주소이다.
//	// 2. 배열은 연속된 메모리 공간에 할당된다.
//
//	// 3. 배열을 선언(생성)할 때 []연산자 안에는 반드시 상수가 기입되어야 한다.
//	// - 개수를 정해놓고 사용하는 문법
//
//	// 4. [] 안에 개수를 넣지 않고 배열을 생성할 경우, 초기화 값의 개수만큼 배열이 자동 생성된다.
//	// 5. sizeof연산자에 배열의 이름을 기입할 경우 배열 전체의 메모리 크기를 계산 할 수 있다.
//	// 6. 생성된 배열의 []연산자 안에서는 변수를 사용 할 수 있다.
//	// 7. 배열의 원소끼리 연산이 가능하다.
//	// 8. 배열의 []연산자 안에서 연산식 삽입이 가능하다.
//	// 9. 배열은 초기화 값이 없을 경우 원소의 값을 0으로 자동 초기화 한다.
//
//	return 0;
//}

#pragma endregion

#pragma region 포인터와 배열

// void	Render(int pArray[], int _iCount);		// int 형 배열의 주소를 전달하고 있음 
// // void	Render(int* pArray, int _iCount);
// 
// int main()
// {
// 	int		iArray[3] = { 10, 20, 30 };
// 
// 	Render(iArray, sizeof(iArray) / sizeof(int));	
// 
// 	// cout << *(iArray + 1) << endl;
// 	// 
// 	// int* p = iArray;
// 	// 
// 	// cout << iArray << endl;
// 	// cout << p << endl;
// 	// 
// 	// cout << p[0] << endl;
// 	// 
// 	// ++p;
// 	// 
// 	// cout << *p << endl;
// 
// 	return 0;
// }
// 
// void	Render(int pArray[], int _iCount)
// {
// 	for (int i = 0; i < _iCount; ++i)
// 	{
// 		cout << pArray[i] << endl;
// 	}
// }

// void	Render(int* pArray, int _iCount)
// {
// 	for (int i = 0; i < _iCount; ++i)
// 	{
// 		cout << pArray[i] << endl;
// 	}
// }

#pragma endregion

#pragma region 2차원 배열

int main()
{					
//				   행 열
	// int		iArray[2][3] = 
	// { 
	// 	{ 1, 2, 3 },	// 0행
	// 	{ 4, 5, 6 }		// 1행
	// };// 0열 1열 2열

	// cout << iArray[1][1] << endl;

	// cout << &iArray[0][0] << endl;
	// cout << iArray[0] << endl;
	// cout << iArray << endl;

	// cout << iArray[0][0] << endl;
	// 
	// cout << (iArray[0]) << endl;
	// cout << (iArray[1]) << endl;

	// int  == iArray[0][0];
	// 
	// int* == iArray[0];
	// int* == iArray[1];
	// 
	// int** != iArray;		// 2차원 배열의 이름은 2중 포인터로 저장할 수 없다!
	
	return 0;
}

#pragma endregion

// 1. 2중 for문과 배열을 이용하여 다음처럼 숫자를 출력해와라

/*
1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25
*/

// 2. 로또 만들기

// - 1 ~ 45사이의 숫자 중 6개의 숫자를 5회 출력하기
// - 같은 회차에서 중복된 숫자는 존재 할 수 없음
// - 출력된 숫자는 오름차순으로 정렬(버블 정렬)(난이도 업)
// 
// (ex)
// 
// 1	2	3	4	5	6
// 1	2	3	4	5	6
// 1	2	3	4	5	6
// 1	2	3	4	5	6
// 1	2	3	4	5	6

// 3. 야구 게임 만들기

// - 1 ~ 9까지 무작위 수 3개 추출(단, 한 번만)하고 출력(매 회마다)
// - 정렬은 하지 않음
// - 숫자 세 개를 입력하여 입력한 수와, 무작위 수의 값과 자리가 일치하면 스트라이크, 값만 일치하면 볼이 증가
// - 매 회 몇 스트라이크 몇 볼인지 출력
// - 3 스트라이크일 경우 '승리' 출력 후 종료
// - 9라운드까지 진행할 때, 3 스트라이크를 만들지 못하면 '패배' 출력 후 종료

// 정답: 4  1  9
// 
// 1회 : 1  2  3			 0 스트라이크 1 볼
// 2회 : 4  3  2			 1 스트라이크 0 볼
// 3회 : 4  9  1         1 스트라이크 2 볼
// 4회 : 4  1  9         3 스트라이크 0 볼
