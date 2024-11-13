#include "pch.h"

int main()
{
	vector<int> vecInt;
	
	vecInt.push_back(10);	// 뒤에서부터 하나씩 넣기

	vecInt.size();	// 배열의 사이즈 반환, size_t(unsigned long long)기반

	vecInt.pop_back();		// 뒤에서부터 하나씩 빼기

	vecInt.capacity();		// 배열의 전체 크기(할당된 최대 크기)반환

	vecInt.clear();			// 데이터 날려 (원소는 날리고 할당된 공간은 내비둠)
	vecInt.empty();			// 날아감?Y:N


	vector<int> vecTemp;

	vecInt.swap(vecTemp);	// 둘을 교환함 (메모리 크기도 교환함)

	vector<int>().swap(vecTemp); // 임시객체와 교환시켜 메모리와 카파시티 둘 다 0으로 초기화함
	vecTemp.shrink_to_fit();	// C++11이후 제공되는 메모리공간 0 초기화 함수


	vecInt.front();		// 맨 앞 원소
	vecInt.back();		// 맨 뒤 원소

}