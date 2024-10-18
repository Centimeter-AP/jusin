#include <iostream>

#include <string>	//c++
#include <cstring> 	//c++
#include <string.h>	//c

using namespace std;

// C 시절 문자열 함수들
// 구조체....

int main()
{
	char *dst, *src;
	strcpy(dst, src);
	//strcpy_s() linux는 없나? 대신 strlcpy
	//복사붙여넣기 (대입아님)
	strcat(dst, src);
	//똑같이 _s가 없어서 strlcat
	//문자열이어붙이기
	strlen(dst);
	//문자열길이구하기
	strcmp(dst, src);
	//문자열비교하기

	// wchar_t : 유니코드기반(2바이트 문자) 문자 자료형
	wchar_t szName[32] = L""; //유니코드임을 알려주는 L을 상수문자열 앞에 붙여줘야함
	//위의 문자열 함수들 앞에 l만 붙여주면 또 쓸 수 있음 (lstrcpy...)

	//string 컨테이너(namespace std를 꼭 쓰라는데 또 아무것도 못쓰게해주는 42의 로렐라이 행동)
	//wstring(유니코드....으아악)
	string strName = "";
	wstring wstrName = L"";
	strName.c_str(); // 원시 타입 문자 자료형으로 변환해줌 

	///////////////////////////////////////

	// 사용자 정의 자료형
	// c언어 시절의 사용자 정의 자료형: 필요에 따라 직접 만들어 쓰는 것이나 각 타입에 맞는 키워드 사용
	// 구조체 struct, 공용체 union, 열거체 enum
	// c++에 추가된 자료형 : 클래스 class

	// 구조체: 여러 개의 자료형을 하나로~ 
	struct tagInfo{			//tag를 붙이는게 관습?
		int i;
		int j;
		char c;
	};

	tagInfo tInfo;					// 선언
	tagInfo tTemp = {0, 1, 'A'};	// 선언 및 초기화 (멤버 변수의 선언 순서대로 값 지정)

	tInfo.i;		// '.' 멤버 접근 연산자.

	tagInfo* pInfo = nullptr;
	pInfo = &tTemp;

	pInfo->i = 100;	// '->' 참조하는 주소를 이용해 멤버 접근 허용 (포인터용 '.')

	// 구조체의 메모리 크기
	// 멤버 변수 중 원시타입인 것의 가장 큰 자료형을 기준으로 블록단위 메모리 부여
	// 그래서 순서도 중요하다~ 

	// c구조체와 c++구조체의 차이 *******
	
	// 아 뭔가 이상하다 했더니 원래는
	typedef struct t_struct{
		int i;
		int j;
	} s_info, *p_info; // 별칭 여러개로 생성 가능
	struct t_struct tFoo;
	s_info tBar;
	p_info pFoo = nullptr; //포인터변수
	// 이런식으로 사용했는데
	// c++은 typedef를 안해도 되나보네요 (위에 쓴 방식처럼)

	// c언어 시절 구조체는 멤버 함수를 소유할 수 없었다(그러게요)
	struct tCpp{
		int i;
		int j;
		void Render(){
			cout << "hello world" << endl;	// 와 함수다
		};
	};

	//그러면 c++에서 struct가 class와 무엇이다르냐!
	//글쎄요... 솔직히 크게 차이는 없지만서도...

#pragma region 공용체,열거체

struct t_info{
	int		iDst;
	float	fSrc;
};

union u_info{
	int		iDst;
	float	fSrc;	//보통 정수랑 실수로 다르게 넣는 짓은 안하긴 함
};
// 공용체: 멤버 중 가장 큰 자료형의 메모리 블럭을 할당하고 그 메모리 블럭을 공유하여 사용하는 사용자지정어쩌고
// 약간 하이브마인드처럼 한 값을 넣고 ? 좀 찾아볼 것
// 옛날에 롱롱 타입이 없을 시절 공용체를 이용해 새 타입을 만들고 그랬음 (LARGE_INTEGER)

enum NUMBER{	//열거체의 메모리 용량은 4바이트 무슨일이잇어도
	A = 1,
	B,
	C = 10,
	D,
	END
};

NUMBER eNum(A);		//이거 다 가능
eNum == 1;
B == 2;
NUMBER::C == 10;	//cpp라서 가능?
D == 11;
// 열거체: 상수를 기호(문자)의 형태로 여러 개 선언하여 사용하기 위한 문법

#pragma endregion


	return 0;
}


// 숙제
// 1. 성적표 만들기 구조체써서
// 3명의 학생의 성적 입출력 프로그램 만들기
// 이름, 국어, 영어, 수학 입력받기
// 총점 평균 구해서 출력하기

// 이름 검색해서 원하는 학생 찾는 기능 함수
// 입력받기 출력하기 함수는 당연