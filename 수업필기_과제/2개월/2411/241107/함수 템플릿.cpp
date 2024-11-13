#include "pch.h"
using namespace std;
// 템플릿 : 기능은 결정되어있지만 자료형은 결정 되어 있지 않은 상태
// 템플릿의 모양이 어떤 형태인지에 따라 함수 템플릿과 클래스 템플릿으로 나뉨

//       typename 대신 class를 쓸 수도 있음. 여기서 class는 객체가 아니라 등급의 의미(클라쓰)
template<typename T>    //  함수 템플릿(단항) (한개니까)
T   Plus(T Dst, T Src)  //  함수 윗 줄에 template를 명시
{
    return Dst + Src;
}

// 템플릿 특수화 : 특정 자료형에 해당하는 템플릿 요소를 따로 구현하는 문법
//      원본 템플릿이 있어야함 !!
//      const 유무로 오버로딩이 가능함

// 다항 템플릿(이항, 삼항..)
template<typename T1, typename T2, typename T3>
T3 Plus(T1 Dst, T2 Src)
{
    return Dst + Src;
}

// 함수 템플릿과 static

template <typename T>
T   Func(T num)
{
    static T res = 0;       // 같은 자료형의 탬플릿 내 static 메모리 공간을 공유함
    res += num;

    return res;
}



int main()
{
    int iRes(0);
    float fRes(0.f);

    iRes = Plus(1, 3);         // 템플릿 함수 : 템플릿에 의해 컴파일러가 자동 생성한 함수
    fRes = Plus(1.2f, 3.4f);   // 이런식으로 컴파일러가 자동 생성할 때 인스턴스화 되었다고 동일하게 표현함
    // 컴파일러가 알아서 매개변수의 자료형을 파악하게 만들어도 되고
    iRes = Plus<int>(3, 5);
    // 꺽쇠 괄호를 이용해 그 템플릿 함수의 자료형을 명시할 수 있음
    // 사실 이쪽이 더 보편적이고 권장됨(당연함)

    cout << Plus<string>("hello ", "world");

    double dRes = Plus<int, float, double>(10, 10.f);
    //으


}
