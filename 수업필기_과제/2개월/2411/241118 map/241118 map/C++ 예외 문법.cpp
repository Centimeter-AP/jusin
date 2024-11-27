#include "pch.h"

// mutable 키워드 : const로 읽기전용인 상황을 무시하고 쓸 수 있게 함

// try-catch 예외처리

int main()
{
	try
	{
		if (/*조건문*/)
			throw /*예외사항이나 변수*/;
	}
	catch (const std::exception&/*이외의 변수 입력 가능, 변수 자료형만으로도 가능*/)
	{
		/*예외 throw 발견 시 실행 구문*/
	}
	catch (/*catch문은 else if처럼 여러개 가능*/)
	{
		/*어쩌구저쩌구.*/
	}
}