#include "pch.h"

// R-value 레퍼런스


int main()
{

	// 레퍼런스는 원래 L-value만 참조가 가능

	const int& r = 10; // const 로 rvalue를 넣을 순 있었으나 읽기전용

	int&& rr = 10; // 뭐여?
	
	// r-value 레퍼런스는 l-value를 받을 수 없음

	return;
}
