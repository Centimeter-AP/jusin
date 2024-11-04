#include <iostream>

#define PURE = 0
// 순수가상함수를 하도 쳐 만들어서 api에는 이 전처리기도 포함이 되어있다(근데좋은거같다눈에잘들어오고)
// virtual void Render() PURE; 
// virtual void Render() = 0;

using namespace std;

class CBase	// 순수가상함수를 하나라도 포함하면 추상클래스로 설정됨
{			// 객체 생성(인스턴스화)가 불가능하게 됨, 인터페이스화 된다 하는데 순수추상함수여야하는거아니었나?
	public:
		virtual void Render() = 0;
	// 순수 가상 함수
	// 상속받는 자식들은 무조건 저 함수를 쓸 것임을 계획하고 쓰는 문법(안 쓸건데 순수가상으로 만들면 자식이 손해를 보니까 의의가 없음)
};

class CDerived : public CBase
{
	public:
		void		Render() { cout << "Derived" << endl; }
};

class CTemp : public CBase
{
	public:
		void	Draw() { cout << "hello" << endl; }
		// 가상함수를 가진 부모를 상속받는 자식은 그게 순수가상이든 그냥가상이든 무조건 가상테이블과 함수를 같이 내려받음
		// = 순수가상함수를 가진 부모를 상속받았다면 그 함수의 몸체를 무조건 구현해줘야 인스턴스화가 가능하다
};


// 부모 클래스의 소멸자는 무조건 소멸자를 붙여줘야함
// 그냥.. 붙여
// 이유: 부모자료형으로 쓸건데 생성은 부모로하니까 당연히 소멸도 부모자료형 기준으로 하기 때문에.. 소멸자도 오버라이딩 해야함



int main()
{
	
	return 0;
}
