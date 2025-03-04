#include <iostream>

using namespace std;

// 디폴트 복사 생성자는 일반 명시적 생성자가 있어도 디폴트로 생성되지만
// 일반 생성자는 명시된 복사 생성자가 있으면 디폴트로 만들어지지 않음
// 상위의 개념인 느낌?

// 복사 생성자가 일반생성 n번하는거보다 변수가 많을 수록 속도 차이가 있다?
// 멤버변수를 복사하는 방법은 메모리블럭째로 와르르 붙이도록 컴퍼일러가 처리한다고 함
// 일반생성으로 초기화 하는 건 한 변수에 하나씩 넣어서 속도차이가 생긴다는 듯

// 복사 생성자가 불리는 경우
// 1. 원본 객체를 사본의 매개변수로 복사받아 생성하는 경우
// 2. 함수의 매개변수가 객체 타입인 경우(콜바이밸류이기때문에 스택메모리에서 복사생성해서 사용함)
// 3. 함수의 반환 타입이 객체 타입일 때 (반환하는 값이 임시 메모리에 저장(복사)된 상태로 오기 때문에)
//    2022버전은 컴파일러가 좋아져서 *this포인터를 이용한 반환일 때만 복사 생성자가 불러와짐


// 얕은복사, 깊은복사(싫다)
// 디폴트 복사 생성자는 기본적으로 얕은 복사만 수행함
// 복사를 하고싶은데 멤버변수에 동적할당되는 녀석이 있다면 깊은 복사를 수행할 수 있도록 복사생성자를 명시적으로 만들어줘야함
// 그럼 복사를 할 때 그냥 생성된 초기 상태(nullptr를 가리키는 상태)에선 얕은복사해도 상관이 없지


// this포인터
// 기본적으로 멤버함수라 하더라도 지역 내에서는 지역변수가 이름의 우선권을 갖는다
// this는 생성된 객체(인스턴스) 필드 내에서 본인 스스로의 주소를 가지는 키워드


// clone()멤버함수는 포로토타입 어쩌구를 하는 어쩌구 뭐시기저시기 암묵적인 약속이니까
// 결론: 걍 이름 함부로 쓰지 마라

// 10월 30일 this포인터 수업파일을 참고할것..
// 요약: 생성소멸자도 private로 가둬버리고
// static 클래스함수들로 Create(){return 객체포인터}, Delete(클래스){delete this}로 우회해 사용하는 방법도 생긴다
// 이렇게 귀찮은 방법이 생겨난 이유: 그런 이유가 있으니까 만들어졌겠죠?
// create하면서 함수 내부에서 initialize()함수를 호출해도 된다 당연함 생성됐으니까?

int main()
{
	
	
	return 0;
}
