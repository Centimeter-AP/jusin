#include "pch.h"

// 템플릿의 장점 자료형에 구애받지 않을 수 있게 짤 수 있다
// 단점.. 내가 새 자료형을 계속 넣어 쓸 때 마다 컴파일러가 도장처럼 쾅쾅 찍어주는 것이기 때문에
// 기본적으로 코드의 비대화가 일어나는 것은 아니지만 사용자 자료형은 끝도 없이 있기 때문에 넣으면 넣을 수록 비대해지는게 맞음 


// 클래스 템플릿의 상속.. 당연히 자식도 클래스 템플릿이다
template <typename T>
class CDerived : public CBase<T>
{};
//.. 당연히 템플릿임을 표기하기 위해 똑같이 바리바리 써줘야한다

template <typename T>
class CTest
{
public:
	CTest() {};
	CTest(T i, T j) :m_X(i), m_Y(j) {};
	~CTest() {};

public:
	Render() { cout << m_X << '\t' << m_Y << endl; }

private:
	T	m_X;
	T	m_Y;
};
// 클래스 템플릿..................................

// 클래스 밖에서 함수의 몸체를 만드려면
template <typename T>
CTest<T>::CTest()
{}
// 클래스템플릿임을 알 수 있도록 저리 다 바리바리 써줘야한다....
// 아 ㅅㅂ... 예시가 너무 많아서 그냥 수업자료 보는게 맞는 것 같다
// 클래스 템플릿 내의 static 변수의 초기화 등
// 같은 자료 형태의 클래스 템플릿은 인스턴스가 달라도 메모리를 공유함

// 클래스 템플릿의 부분 특수화
//	이항 템플릿 이상일 경우 생성이 가능함

template <typename T1, typename T2>
class CBase
{};

template <>
class CBase<int, char*>
{};





int main()
{
	return 0;
}