#include <iostream>

// 함수 오버로딩 + default매개변수 + 재귀 함수
//      포        인         터

using namespace std;

#pragma region 오버로딩


// 함수 오버로딩 !!! 오버라이딩(X)
// 함수의 이름이 같을 경우 매개 변수의 상황에 따라 어떤 함수를 호출할 지 컴파일단계에서 결정함
// 1. 매개 변수의 개수
// 2. 매개 변수의 자료형
// 3. 반환 타입은 관여하지 않음 !!!!

void foo();
void foo(int bar);
void foo(float bar);
void foo(int bar, int blah);

// 호출 시 매개변수 상황에 맞춰 실행되는 기능이 다름


int main()
{
	
	return 0;
}

void foo()
{
	cout << "Hello world" << endl;
}
void foo(int bar)
{
	cout << "Hello world" << bar << endl;
}
void foo(float bar)
{
	cout << "Hello world" << bar << endl;
}
void foo(int bar, int blah)
{
	cout << "Hello world" << bar << blah << endl;
}

#pragma endregion 

#pragma region default매개변수

// default 매개변수 : 함수 생성시 기본값을 초기화해줌
// 1. 초기화식이기 때문에 선언 시점에(맨위에) 단 한번만 기본값을 설정해준다
// 2. default 매개변수가 지정되지 않은 매개변수는 호출 시점에 삽입되는 것으로 정해지고, default 매개변수가 있는 매개변수의 경우 뭐라고
// 3. 매개변수가 여러개인 경우 맨 오른쪽부터 default를 지정해줄 수 있음(매개변수는 필연적으로 왼쪽부터 입력하게 되니까)
// 4. 함수 오버로딩을 할 경우 모호한 호출이 되지 않도록 니가! 알아서 써라

void _foo(int bar = 100); // 이런식으로 값을 초기화해줌 매개변수를 안넣을 때 알아서 이거 넣으라고

int main()
{
	_foo();
	_foo(200);
	// 둘 다 가능
}
void _foo(int bar)
{
	void;
}

#pragma endregion 

#pragma region 재귀함수

// 스택프레임, 함수 테이블, 활성화 레코드 (알아서찾아보라는뜻)
// 스택프레임 = 함수가 호출된다면 용량을 얼마나 처먹을것인지에 대한 정보를 담은 메모리 주소
// 재귀함수는 이 스택프레임을 '탈출 조건이 없을 시' 무한정 생성하게 된다 = 메모리죽어요!!!!
// = 재귀함수는 무조건 탈출 조건을 마련해야만 한다 !!

// 재귀함수의 등장 역사를 보면 이진탐색 = 큰 문제를 쪼개쪼개 탐색하는 것에서 시작했음
// 무슨 뜻이냐 하면 이 탈출 조건은 값을 증가시키며 조건에 맞을 때 탈출하게 하는 것은 원칙에 맞지 않음
// (그러나 그게 문법상으로 문제된다는건 아님. 작동은 하겠으나...)

// 장점: 반복이 편하당ㅋㅋ
// 단점: 메모리 낭비 지린다.(재귀될 때 마다 스택프레임을 소모하므로..) 그러므로 동작도 좀 느리다.
// 그러나 이진트리라던지 나중에 자료구조를 관리할 때 쓸 수 밖에 없을 수도 있다.

void Recursive(int _iNumber)
{
	if (0 >= _iNumber)
		return ; // 탈출조건이무조건있어야함!!!!!!!!!

	cout << "재귀호출"<< endl;

	Recursive(--_iNumber); // 함수 내에서 함수 호출 = 재귀!
}

int main()
{
	Recursive(3); // <- 3번반복할게요
}


#pragma endregion

#pragma region 포인터

// 포인터는 주소값만 소유하면 메모리 공간에 접근하여 값을 읽거나 쓰기가 가능하다. 


int main()
{
	int* p;
	int iData(10);

	int* p1 = NULL; // C style
	int* p2 = nullptr; // C++ style
	int* p3 = &iData; // address 연산자 = 변수의 첫번째 주소를 반환

	*(&iData);	// 직접참조
	*p; 		// 간접참조 : 포인터 변수를 대신해 메모리 공간에 접근

	cout << p << endl;
	cout << sizeof(p) << endl;
}

#pragma endregion

// 1. 5팩토리얼 재귀함수로 구현
// 2. 셔플알고리즘을 함수에 적용해 구현 (포인터쓰세요)



