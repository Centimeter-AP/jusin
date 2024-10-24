#include <iostream>

using namespace std;

void Render(void);		// 함수 선언부(이런 함수가 있음을 컴파일러에게 알려주는 행위)

void Print(int _iData);

int	 Get_Number(void);	// 반환 타입이 있는 유형의 함수에는 반드시 return 키워드가 삽입되어야 한다.

int	Add(int _iDst, int _iSrc);

// return 
// 
// 1. 함수를 강제적으로 종료시킴
// 2. 실제 값을 운영체제에 반환

int main()
{
	// 함수 : 코드의 재사용성을 위해 만들어 사용하는 기능 상태

	// 함수의 구성 요소
	// 
	// 1. 반환 타입 : 함수 종료 시, 해당 자료형으로 값을 반환해야 함을 알리는 문법
	// 2. 함수 이름 : 함수 코드를 호출하기 위한 일종의 키
	// 3. 매개변수(파라미터, 인자값)


	// for(int i = 0; i < 5; ++i)
	// 	Render();

	// Render();	// 함수 호출
	
	// int		iSrc(100);
	// 
	// Print(iSrc);			// call by value : 값 복사에 의한 호출
	// 
	// cout << iSrc << endl;

	// cout << Get_Number() << endl;
	
	// Print(Get_Number());
	// cout << Add(10, 20) << endl;


	return 0;
}

// 함수 정의부
void		Render(void)
{
	cout << "hello world" << endl;
}

void Print(int _iData)
{
	_iData += 10;

	cout << _iData << endl;
}

int	 Get_Number(void)
{
	//return 200;

	int		iTest(200);		// 지역 변수

	return iTest;
}

int	Add(int _iDst, int _iSrc)
{
	return _iDst + _iSrc;
}

// 1. 자판기 게임 코드를 함수를 이용하여 재구성하라
// - 함수는 하나의 기능만 담당한다


// 1. 자유의 날개 : 포인터
// 2. 군단의 심장 : 동적할당
// 3. 공허의 유산 : 오버라이딩