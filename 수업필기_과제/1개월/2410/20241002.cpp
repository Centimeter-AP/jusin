#include <iostream>

using namespace std;

// 함수.. 와 메모리 (아마 힙)(안함ㅠㅠ할당을아직안배워서그른가)

int main()
{
	//함수
	// 반환타입 이름 (매개변수 파라미터와 인자값)
	//  int  main  (void(생략됨))
	// 혹은..
	//  int  main  (int argc, char **argv)
	//              함수 정의 시에 쓰는게 parameter 매개변수
	//  void func(int a)
	//  func(iA) <- 함수 호출 시에 넣는게 argument 전달인자(값)

	// func(?) <- 소괄호가 바로 함수호출..뭐라고? 연산자?
	// 함수호출연산자 가 맞다...

	// call by value < 값 복사에 의한 호출
	// = 인자를 넣을 때 매개변수에 대입하는게 아니라 복사를 해주는 것(음?)

	// return 키워드에 더 알아보기 ***************************************************
	// 더 알아본 것에 비해 그다시 생산적인 추가 정보는 없었다(내가 검색을 잘못했나요?)

	// return 지역변수; < 로 값이 반환될 때 지역변수가 들고있던 값이 임시메모리에 저장되고 지역변수놈은 죽여버림(ㅠㅠ)

	return 0;
}

// 오버라이딩은 포인터의 일환이다?

/*
1. 자판기 게임 코드를 함수를 이용해 재구성
	함수는 하나의 기능만 담당함 !!!
	??이런거도함수로만드나요?? <- 네(함수를배우는숙제니깐.)
	ex)돈을 받기. 메뉴 출력하기. 계산하기. 어쩌구저쩌구
	42의 장점 있는 함수도 내가 처 만들게 함 썅 덕분에 모든걸 함수로 만들어 살려는 버릇이

1.5. libft를 다시 볼 때가 왔을지도?
*/