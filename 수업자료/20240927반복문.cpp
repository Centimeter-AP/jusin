#include <iostream>
#include <ctime>

using namespace std;

// 자료형의 재정의 문법
// typedef int			BOOL;

// 모던 c++ 재정의 문법
// using BOOL = int;

int main()
{
	// 반복문 : 중복되는 코드가 대량일 경우 효과적으로 해결하기 위한 수단의 문법
	// 루프 : 한 번의 프로그램 실행 흐름
	// while, do while, for

#pragma region while

	//int		iNumber(3);

	// while (iNumber--)
	// {
	// 	 cout << "hello world" << endl;
	// }

	// while (true)
	// {
	// 		cout << "hello world" << endl;
	// 		
	//		iNumber--;
	// 
	// 		if (0 == iNumber)
	// 		{
	// 			break;
	// 		}
	// }

	/*2 * 1 = 2
	2 * 2 = 4
	2 * 3 = 6
	2 * 4 = 8
	2 * 5 = 10
	2 * 6 = 12*/

	// int	 i(1);
	// 
	// while (10 > i)
	// {
	// 	cout << 2 << " * " << i << " = " << i * 2 << endl;
	// 	i++;
	// }

#pragma endregion

#pragma region do while

	// int	iInput(0), iSum(0);
	// 
	// do
	// {
	// 	cin >> iInput;
	// 
	// 	if (0 != iInput % 2)
	// 		continue;			// 반복문 안에서만 사용 가능, 코드의 흐름을 반복문의 맨 끝으로 이동
	// 
	// 	iSum += iInput;
	// 
	// 	/*if (0 == iInput % 2)
	// 	{
	// 		iSum += iInput;
	// 	}*/		
	// 
	// } while (-1 != iInput);
	// 
	// cout << iSum << endl;

#pragma endregion

#pragma region random

	// 난수 : 무작위의 숫자를 의미

	// rand() 함수 : 0 ~ 32767 범위 사이 값 중 하나를 무작위로 추출 
	// seed 난수표로부터 값을 가져와서 숫자를 발생

	// srand() 함수 : 난수표(난수 테이블)를 바꿔주는 함수

	// time() 함수 : 현재 시간을 초 단위로 변환하여 불러오는 함수

	// time_t Test = 0;
	// 
	// time(&Test);
	// 
	// cout << Test << endl;
	// 
	// srand(Test);

	//srand(unsigned(time(NULL)));
	//
	//int		iDst = rand();
	//int		iSrc = rand();
	//int		iTmp = rand();
	//
	//cout << iDst << endl;
	//cout << iSrc << endl;
	//cout << iTmp << endl;

	// int iInput(0);
	// 
	// while (true)
	// {
	// 	system("cls");
	// 
	// 	cout << "숫자를 입력하세요 : ";
	// 	cin >> iInput;
	// 
	// 	cout << iInput << endl;
	// 	system("pause");
	// }

#pragma endregion

	return 0;
}

// 1. 구구단 2~9단까지 while문을 이용하여 출력하기

// 2. 자판기 게임 구현하기

// - 소지금을 입력받고, 현재 소지금의 잔액 상태를 화면에 출력
// - 메뉴 : 1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환
// - 해당 목록 선택, 구매 시, 보유잔액이 바뀌고, 'xx구매 완료'라고 출력
// - 단, 잔액이 부족할 경우, '잔액이 부족합니다'라고 출력
// - 4번을 누를 경우, '거스름 돈은 xx원 입니다' 출력 후, 게임 종료

// 3. 홀짝 게임
// - 난수를 이용해서 숫자를 매 회차마자 발생시킴
// - 난수를 이용하여 홀과 짝을 맞추면 됨
// - 총 5회 실시하여 마지막 라운드가 종료되고 난 뒤, 승 패 출력

// ex)
// rand = 3
// 1. 홀 2. 짝 3. 종료
// 1
// 정답
// rand = 6
// 1. 홀 2. 짝 3. 종료
// 1
// 오답
// 
// 3승 2패

