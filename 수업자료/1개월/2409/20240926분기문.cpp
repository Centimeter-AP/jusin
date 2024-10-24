#include <iostream>

using namespace std;

int main()
{
	// 분기문 : 실행할 것과 그렇지 않을 것을 구분하기 위한 문법
	// if, switch, goto

#pragma region goto

// goto Home;
// 
// 	cout << 1 << endl;
// 
// Home :
// 
// 	cout << 2 << endl;

#pragma endregion

#pragma region if

	// if문 : 분기문, 조건문이라고도 불린다. 

	// if ( 조건식)
	// {
	// 	// 코드 블럭
	// }


	// int		iDst(10), iSrc(20);
	// 
	// if (iDst > 5)
	// {
	// 	cout << 'A' << endl;
	// }
	// 
	// // if와 else 사이에는 다른 코드가 위치 할 수 없다.
	// // else if와 else 앞서서 if문이 있어야 사용이 가능하다.
	// 
	// else if (iDst > 5)
	// {
	// 	cout << 'B' << endl;
	// }
	// 
	// else	// if의 조건이 참이면 else는 자동적으로 거짓
	// {
	// 	cout << 'C' << endl;
	// }

	// 단일 코드 : 코드 블럭 안에 코드가 한 줄인 경우, 중괄호를 생략하여 표기가 가능
	// if (1)
	// {
	// 		cout << "hello world" << endl;
	// }
	
	// if (1)
	// {
	// 		int		iTemp = 100;		// 지역 변수 : 중괄호 안에서만 유효성일 지닌 변수
	// }
	// 
	// else
	// {
	// 		cout << iTemp << endl;
	// }

	////////////////////////////////////////

	// int			iA(20), iB(5);
	// 
	// if ((iA < iB) && (iA = 999))
	// 	cout << iA << endl;

	//if (10 > 3)
	//{
	//	if (20 > 5)
	//	{

	//	}
	//}
#pragma endregion

#pragma region switch

// switch : 상수 조건 분기문, 상수, 정수만 취급하며 실수 값으로 분기가 불가능

// switch (조건에 해당하는 상수값(정수 타입))
// {
// case 1:
// case 2:
// case 3:
// }

	int		iInput(0);

	const int		iNumber(1);	// 심볼릭 상수

	cout << "숫자를 입력하세요 : ";
	cin >> iInput;

	switch (iInput)
	{
	case iNumber:
		cout << "콜라" << endl;
		break;		// 현재 코드의 흐름을 멈추고 중괄호를 벗어나도록 만드는 키워드

	case 2:
		cout << "사이다" << endl;
		break;

	case 3:
		cout << "환타" << endl;
		break;

	default:
		cout << "잘못 입력하셨습니다" << endl;
		break;
	}




#pragma endregion

	return 0;
}

// 평균 값을 기준으로 성적 등급을 매기자

// 90점 이상 100점 이하 A학점
// 80점 이상 90점 미만 B학점
// 70점 이상 80점 미만 C학점
// 60점 이상 70점 미만 D학점
// 나머지 F학점