// #include <iostream>
// 
// using namespace std;

#include <stdio.h>

typedef struct tagInfo
{
	char	cKor;			// 구조체 멤버 변수
	int		iEng;
	double	fAver;

	void	Render()		// 구조체 멤버 함수
	{
		printf("helloworld\n");
	}

} INFO, *PINFO, *LPINFO, MONSTER;

//struct tagTemp
//{
//	int		iTemp;
//	tagInfo	tInfo;
//};


int main()
{
	// 사용자 정의 자료형 : 프로그래머의 필요에 따라 직접 만들어서 사용하는 자료형, 각 타입에 맞는 키워드를 삽입하여 자료형을 생성
	
	// c언어 시절의 사용자 정의 자료형 : 구조체(struct), 공용체(union), 열거체(enum)
	// c++ 사용자 정의 자료형 : 구조체, 공용체, 열거체 + 클래스(class)

	// 구조체 : 여러 개의 자료형을 한데 모아 하나의 자료형으로 관리하도록 만드는 문법

	 tagInfo		tInfo;	// 구조체 변수를 선언하다.
	 tInfo.Render();
	
	// struct tagInfo		tInfo = { 10, 20, 3.14 }; // 멤버 변수의 선언 순서대로 초기화 값을 지정해야 한다.
	

	// 
	// cout << tInfo.iKor << endl;		// . : 멤버 접근 연산자
	// cout << tInfo.fAver << endl;
	// 
	// 
////////////////////////////////////////////////////////////////////////////// 
	// 
	// c 구조체와 c++ 구조체의 차이점
	// 
	// 1. c언어 시절에는 구조체 변수를 선언하기 위해서도 키워드를 반드시 삽입해야 했다.
	// 
	// // INFO		tInfo = { 1, 2, 3.14 };
	// PINFO		pInfo = &tInfo;
	// 
	// 2. c언어 시절의 구조체는 멤버 함수를 소유할 수 없었으나 c++부터 가능해졌다.
	// 
//////////////////////////////////////////////////////////////////////////////
	//
	// 구조체의 크기 : 멤버 변수 중 가장 큰 자료형의 크기를 고려하여 메모리 블럭이 형성
	// 기본 자료형의 크기들을 기준으로 비교함
	//
	// cout << sizeof(tagInfo) << endl;
	// cout << sizeof(tagTemp) << endl;
	//
//////////////////////////////////////////////////////////////////////////////	
	//
	// 구조체와 포인터
	// 
	// tagInfo*	pInfo = nullptr;
	// pInfo = &tInfo;

	// (*pInfo).iKor = 500;
	// pInfo->iKor = 500;		// -> : 참조하는 주소를 이용하여 멤버에 접근을 허용

	//(&tInfo)->iKor = 600;
	// cout << tInfo.iKor << endl;


	return 0;
}

// 1. 성적표 만들기(구조체 활용)

// - 3명의 학생의 성적 입출력 프로그램 만// 들기
// - 이름 검색을 통한 원하는 학생 찾아서 출력하기
// 
// 이름, 국어, 영어, 수학 입력
// 총점 평균 구해서 출력하기 

