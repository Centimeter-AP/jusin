#include "pch.h"

class CTest
{
	private:
		int *m_pI;		// 클래스 내 멤버변수 선언과 동시에 초기화(int i = 0)는 c++11부터 가능한 문법(생성자가 많아지면 문제 생길 수도?)
	public:
		CTest();							// 생성자
		~CTest();							// 소멸자(비트연산자 ~(NOT)임 헐! 몰랐당)
		CTest(const CTest& obj);
		CTest& operator=(const CTest& obj);

		void	Initialize();		// 동적할당 할 놈들 전부 만들어버리는 곳
		void	Update();			// while로 무한루프 거는 곳
		void	Release();			// 동적할당 된 놈들 다 죽여버리는 곳
									// 얘네 셋은 자주 쓰는 기본적인 함수로 생각하자 
};

CTest::CTest()			// 생성자
{						// 매개변수의 종류에 따라 오버로딩이 가능함
	m_pI = nullptr;		// 클래스는 1.메모리할당 2.생성자호출 이 전부 끝나야 생성되는 것이기 때문에
}						// 변수 자체의 사용 가능 시점이 할당 이후라 하더라도 생성자 호출 내에서 값을 넣어주는것을
						// 초기화라고 할 수 있음.

CTest::~CTest()			// 소멸자
{						// 소멸자는 매개변수를 받지 않기 때문에 한 종류만 존재함 (void)
	Release();
}	

CTest::CTest(const CTest& obj) {}
CTest& CTest::operator=(const CTest& obj) {}

void CTest::Initialize()
{
	//솰라솰라
}


// 대입연산자가 값을 받아오면 그 값을 받아와서 생성자로 전달해주는 방식..?