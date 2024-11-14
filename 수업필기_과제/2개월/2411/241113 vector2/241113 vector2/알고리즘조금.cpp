#include "pch.h"

#include <algorithm>

int main()
{

	// 알고리즘의 매개변수는 보통
	// (begin, end, 조건자)로 구성됨
	// 앞 두개를 합쳐 range로 취급
	// 조건자는 없어도 됨

	// 조건자는 함수가 들어간다..

	// <functional> 을 포함하면 제공되는 함수템플릿들을 받을 수 있었는데 지금은 포함 안해도 되는듯?

	// sort, count_if, for_each, find_if
	// count_if : 싹~ 훑어보면서 조건자에 맞는 원소의 갯수 반환
	// for_each : 훑어보면서 for 문과 비슷하게 작동함. 조건자에 있는 함수를 실행
	// find_if : 탐색알고리즘.. 매개변수로 전달하는 요소를 탐색하는 기능의 알고리즘
	//			찾은 대상의 반복자를 반환함. 못찾았을 시 end()위치를 반환함 (end()는 마지막 원소의 다음 부분임)


	return 0;
}