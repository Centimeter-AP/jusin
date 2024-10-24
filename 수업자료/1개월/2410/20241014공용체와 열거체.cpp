#include <iostream>
#include <windows.h>

using namespace std;

#pragma region 공용체

// struct tagInfo
// {
// 	int		iDst;
// 	float	fSrc;
// };
// 
// union uniInfo
// {
// 	short	iDst;
// 	float	fSrc;
// 
// };
// 
// int main()
// {
// 	// 공용체 : 멤버 중 가장 큰 자료형의 메모리 블럭을 할당하고 그 메모리 블럭을 공유하여 사용하는 사용자 정의 자료형
// 
// 	uniInfo		tInfo = { 3.14f };
// 
// 	//cout << &tInfo << endl;
// 	//cout << &(tInfo.iDst) << endl;
// 	//cout << &(tInfo.fSrc) << endl;
// 
// 	cout << "======================" << endl;
// 	
// 	cout << (tInfo.fSrc) << endl;
// 	cout << (tInfo.iDst) << endl;
// 
// 	return 0;
// }

#pragma endregion

#pragma region 열거체

enum NUMBER
{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	END
};

//enum TEST
//{
//	ONE = 100,
//	TWO,
//	THREE,
//	FOUR,
//	FIVE,
//	END
//};


int main()
{
	// 열거체 : 상수를 기호(문자)의 형태로 여러 개 선언하여 사용하기 위한 문법

	// NUMBER	eNumber(THREE);
	// 
	// cout << eNumber << endl;
	// cout << NUMBER::FIVE << endl;
	// cout << sizeof(NUMBER) << endl;
	// 
	// int		iResult = ONE + FIVE;
	// cout << iResult << endl;

	// . 연산자는 열거체에서는 제공하지 않음
	//cout << eNumber.ONE << endl;

	return 0;
}

#pragma endregion