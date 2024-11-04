#include <iostream>

using namespace std;

class CBase
{

};

class CDerived : public CBase
{
	void	Render() { cout << "Derived" << endl;}
};

class CTemp
{
	void	Draw() { cout << "Temp" << endl; }
};



int main()
{
	
	// c언어 시절의 강제 형 변환(int)는 진짜 강제라서 거의 모든 상황에서 걍~ 다 허용이 됨

	// c++에 오며 생긴 캐스팅 연산자
	// static_cast<>, dynamic_cast<>, const_cast<>, reinterpret_cast<>

	// static_cast : 정적 캐스팅, 컴파일 단에서 수행, c언어 시절과 거의 흡사함
	// 		논리적인(상속 관계인 경우) 형 변환이라 생각될 때만 허용
	//		(논리적이라 했으나 사람 기준에서 비논리적이어도 기계 입장에선 상속관계이기만 해도 걍 ok때림)
	//		런 타임 시에 타입 체크를 하지 않기 때문에 변환의 위험성을 잘 몰루 일단바꿔
	// dynamic_cast : 동적 캐스팅, 런 타임 시에 수행, 다운캐스팅을 수행하기 위한 연산자
	//		상속관계에 있는 클래스나 c++구조체에서만 사용이 가능함
	//		부모 클래스에 virtual 키워드가 있어야(가상함수가 있어야) 수행 가능 (다형 형식)
	//		RTTI (Run Time Type Information?) 런 타임 형식 정보 문법?
	//			프로그램 실행 중에 개체의 형식이 결정될 수 있도록 하는 메커니즘
	//			dynamic_cast<>, typeid(), type_info
	//		다운 캐스팅의 조건 (상속 관계, 부모클래스의 virtual)을 갖추면 컴파일 에러자체는 안 나긴 함
	//		대신 안전하지 않은 다운 캐스팅을 처리하려 할 경우 NULL 값을 반환해 보호해줌 (안전장치)
	//		(부모로 인스턴스화 한 것을 자식 포인터에 넣으려 하는 경우)
	//		if (다이나믹 다운캐스팅 한 놈 == nullptr) ....이런 식으로 가능 여부를 확인 가능
	//		그래서 nullptr가 나오지 않는다(안전을 확보했다)면 static_cast로 내려도 됨(학원에서는)(속도면에서압도적)

	// 면접질문단골손님이여~

	return 0;
}

// 상점 구현
// 상점의 등급
// 등급에 따른 판매 아이템의 등급
// 구매우선, 판매는 맘대로

// 