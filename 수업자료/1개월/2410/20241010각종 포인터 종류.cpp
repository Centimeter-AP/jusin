#include <iostream>

using namespace std;

#pragma region 2차원 배열의 이름을 저장하는 포인터

//void	Render(int(*pArray)[3]);
//
//int main()
//{
//	int	iArray[2][3] = {
//
//		{ 1, 2, 3},
//		{ 4, 5, 6},
//	};
//
//	// 2차원 배열의 이름을 저장하는 포인터 선언 방식
//	// 자료형 (*포인터 변수이름)[열]
//
//	// int(*pArray)[3] = iArray;
//	// cout << sizeof(pArray) << endl;
//	//cout << pArray[1][1] << endl;
//	
//	Render(iArray);
//
//	return 0;
//}
//
//void Render(int(*pArray)[3])
//{
//	cout << pArray[1][1] << endl;
//}

#pragma endregion

#pragma region 함수 포인터

void	Render();
void	Draw();

int		Add(int iDst, int iSrc);
int		Min(int iDst, int iSrc);
int		Mul(int iDst, int iSrc);
int		Div(int iDst, int iSrc);


int main()
{
	// 함수 포인터 : 함수의 이름(주소)을 저장하여 함수의 호출을 대신 가능하도록 만드는 포인터
	// 반환 타입 (*포인터 변수 이름)(매개 변수 형식)

	// void (*pFunc)() = Render;
	// //cout << sizeof(pFunc) << endl;
	// 
	// pFunc();
	// pFunc = Draw;
	// pFunc();

	// int	(*pCalc)(int, int) = Add;
	// cout << pCalc(10, 20) << endl;

	// 사용 예///////////////////////////////////////

	int iDst(0), iSrc(0);
	int iInput(0), iResult(0);

	cout << "숫자를 입력하세요 : ";
	cin >> iDst >> iSrc;

	cout << "1. 덧셈 2. 뺄셈 3. 곱셈 4. 나눗셈 : ";
	cin >> iInput;

	int(*pCalc[4])(int, int) = { Add, Min, Mul, Div };
	cout << "최종 결과 : " << pCalc[iInput - 1](iDst, iSrc) << endl;

	//int (*pCalc)(int, int) = NULL;
	//
	//switch (iInput)
	//{
	//case 1:
	//	//iResult = Add(iDst, iSrc);
	//	pCalc = Add;
	//	break;
	//
	//case 2:
	//	//iResult = Min(iDst, iSrc);
	//	pCalc = Min;
	//	break;
	//
	//case 3:
	//	//iResult = Mul(iDst, iSrc);
	//	pCalc = Mul;
	//	break;
	//
	//case 4:
	//	//iResult = Div(iDst, iSrc);
	//	pCalc = Div;
	//	break;
	//}
	//
	////cout << "최종 결과 : " << iResult << endl;
	//cout << "최종 결과 : " << pCalc(iDst, iSrc) << endl;
	

	return 0;
}

void	Render()
{
	cout << "hello world" << endl;
}

void Draw()
{
	cout << "hello jusin" << endl;
}
int		Add(int iDst, int iSrc)
{
	return iDst + iSrc;
}

int Min(int iDst, int iSrc)
{
	return iDst - iSrc;
}

int Mul(int iDst, int iSrc)
{
	return iDst * iSrc;
}

int Div(int iDst, int iSrc)
{
	return iDst / iSrc;
}

#pragma endregion

// 1. 2차원 배열을 이용하여 다음의 상태로 숫자 출력을 해와라
/*
* 
1	2	3				7	4	1				9	8	7				3	6	9				1	2	3
4	5	6	-90도 회전>	8	5	2 - 90도 회전 >	6	5	4 - 90도 회전 >	2	5	8 - 90도 회전 >	4	5	6
7	8	9				9	6	3				3	2	1				1	4	7				7	8	9

*/

// 2. 빙고 게임 만들기

// - 5 * 5짜리 배열을 이용한 숫자 1~25 출력하기
// - 입력한 숫자와 일치하는 값을 가진 배열은 * 로 출력한다.
// - * 로 이뤄진 가로 다섯개, 세로 다섯개, 대각선 다섯개가 있을 경우 빙고가 하나 증가
// - 5 빙고 이상이면 승리로 게임이 종료
// - 빙고의 개수는 매 루프마다 출력

// 1  2	 3			1	*	3		*	*	*
// 4  5	 6	-2입력>	 4	 5   6	->	 4	 5	 6
// 7  8	 9			7	8	9		7	8	9

// 3. 숫자 이동 시키기

// - 5 * 5짜리 배열을 이용한 숫자 0 ~ 24 출력하기
// - 2(아래쪽) 4(왼쪽) 6(오른쪽) 8(위쪽)의 메뉴를 출력하고 선택한 번호에 따라 숫자 0을 이동시켜 출력한다.
// - 맨 끝줄에서는 이동하지 못하도록 예외처리 할 것

// 0	1	2			3	1	2			3	1	2
// 3	4	5	-2입력>  0	 4   5 -6입력>	  4	  0	  5
// 6	7	8			6	7	8			6	7	8


