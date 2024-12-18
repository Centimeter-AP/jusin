#include "pch.h"


int main()
{
	map<int, int>	mapInt;
	// 다항템플릿이고 key값과 value값의 자료형 외에도 뭐 있지만 일단 저거만
	// key값 자료형, value값 자료형, 조건자, 알로케이터
	// map은 자동정렬이기때문에 조건자를 받고 따로작성하지 않을 시 default로 less(오름차순)이 되어있음)

	// pushback.. 같은거 안됨 back이 어디고 front가 어디죠 트리에선?



	
	////////////////// MAP 컨테이너의 추가 방식 //////////////////

	// pair : 데이터 한 쌍. 

	// 1. 페어를 이용해 값을 넣어서 원소를 추가할 수 있음.
	pair<int, int>	MyPair;
	MyPair.first = 1;
	MyPair.second = 100;
	mapInt.insert(MyPair);
	/////////////////////////////////////////////////

	// 2. 임시 객체를 써서 압축해버리기
	mapInt.insert(pair<int, int>(2, 200));
	/////////////////////////////////////////////////

	// 3. make_pair함수 써서 넣기
	mapInt.insert(make_pair(3, 300)); // 자료형을 추론해야함...
	mapInt.insert(make_pair<int, int>(3, 300)); // 이럴바엔 2번이 낫지...
	/////////////////////////////////////////////////

	// 4. value_type을 이용하기
	map<int, int>::value_type  MyValue(4, 400);	// key값(first 값)은 절대 중복되면 안되는 태생적 운명이 있기 때문에 const라서 생성과동시에초기화해야함
	// 5. 그거압축
	mapInt.insert(map<int, int>::value_type(5, 500));
	// 가장 권장하는 방법은 이거....
	/////////////////////////////////////////////////

	// 6. []를 이용해 추가하기
	mapInt[6] = 600;	// 근데 매우 느리다곤 함.. 또한 insert는 순수 삽입 목적으로만 사용되는 함수인데 얘는 값 덮어쓰기일 수도 있고.. 
	/////////////////////////////////////////////////


	////////////////// 모 던 C + + //////////////////

	// 7. 유니폼 초기화를 이용한 원소 추가
	mapInt.insert({ 7, 700 });	// 점점 가벼워진다
	/////////////////////////////////////////////////

	// 8. emplace 함수를 이용한 추가
	mapInt.emplace(8, 800);		// 와!!!
	/////////////////////////////////////////////////

	// 이 중에선 7번이 나을 것 같다


	// map 컨테이너의 접근
	map<int, int>::iterator iter = mapInt.begin();
	// iter + 3은 안된다
	// map컨테이너에서 대괄호 연산자로 키 값에 임의접근은 가능하지만 iter에 오버로딩 되어있는건 아니다 !!!
	// 트리 기반임을 항상 인지

	iter++;
	iter++;
	iter++;
	iter++;

	mapInt.insert(iter, { 9, 900 });
	// 중간 삽입이 되기는 하지만???
	// map컨테이너는 자동정렬하는 RB트리기반이기 때문에 사실상 의미가 없다...


	mapInt.erase(iter);
	mapInt.erase(2);
	// iterator와 key값 모두 받을 수 있음

	mapInt.find(5);
	// key값 기준으로 탐색할 수 있고 찾는게 없을 시 .end()반환




}