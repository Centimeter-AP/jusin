#include <iostream>

using namespace std;

// #if : if문과 동일한 형태로 조건이 참인 경우에 컴파일을 수행시키는 문법

// #define		TEST 10
// 
// int main()
// {
// #if		5 > TEST
// 	cout << "5보다 작다" << endl;
// 
// #elif  5 < TEST
// 	cout << "5보다 크다" << endl;
// 
// #else
// 	cout << "5와 같다" << endl;
// 
// #endif		// 조건부 컴파일 구문의 끝을 알리는 문법
// 
// 	return 0;
// }

// #ifdef : 전처리기 정의 여부에 따라 컴파일 수행을 결정하는 문법

//int main()
//{
//#ifdef _DEBUG
//
//	cout << "디버그 모드" << endl;
//
//#elif NDEBUG
//
//	cout << "릴리즈 모드" << endl;
//
//#else
//	cout << "문제 있음" << endl;
//
//#endif // DEBUG
//
//	return 0;
//}

// #ifndef : 앞선 전처리기 매크로가 정의 되어 있지 않다면 수행하는 전처리기 문법

int main()
{
	return 0;
}