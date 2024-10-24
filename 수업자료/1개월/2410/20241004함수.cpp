#include <iostream>

using namespace std;

#pragma region 함수 오버로딩

// 함수 오버로딩 : 함수의 이름이 같을 경우, 매개 변수의 상황에 따라 어떤 함수가 호출 될 지 컴파일 타임에 결정되는 문법

// 1. 매개 변수의 개수에 따라 함수의 호출이 결정
// 2. 매개 변수의 자료형에 따라 함수의 호출이 결정
// 3. 함수 반환타입이 다르다고 해서 오버로딩이 성립하지는 않음

// void	Render();
// 
// void	Render(int _iData);
// // int		Render(int _iData);
// 
// void	Render(float _fData);
// void	Render(int _iData, int _iSrc);
// 
// int main()
// {
// 	Render(100);
// 
// 	return 0;
// }
// 
// void Render()
// {
// 	cout << "hello world" << endl;
// }
// 
// void Render(int _iData)
// {
// 	cout << "hello" << _iData << endl;
// }
// 
// void Render(float _fData)
// {
// 	cout << "hello float" << _fData << endl;
// }
// 
// void Render(int _iData, int _iSrc)
// {
// 	cout << "hello " << _iData << '\t' << _iSrc << endl;
// }
//int		Render(int _iData)
//{
//	cout << "hello 반환 타입" << endl;
//
//	return _iData;
//}

#pragma endregion

#pragma region default 매개 변수

// default 매개 변수 : 함수 생성 시, 기본값을 설정하여 매개 변수 삽입 없이 값 적용이 가능하게 하는 문법

// 1. 초기화식이기 때문에 선언 시점에 단 한번만 기본값을 설정해준다(함수 정의부에 default 매개 변수 문법을 삽입하지 않음)
// 2. default 매개변수가 지정되지 않은 매개 변수는 호출 시점에 삽입되는 것으로 정해지고, default 매개 변수가 있는 매개 변수인 경우 설정한 값으로 삽입되어 동작
// 3. default 매개변수는 매개 변수가 여러 개인 경우 맨 오른쪽에 있는 매개 변수부터 기본 값을 정해줘야 함
// 4. 함수 오버로딩 시, 모호한 호출이 가능하기 때문에 제작 시 이 부분을 고려해야 함

// void	Draw();
// void	Draw(int _iSrc = 100, int _iData = 200); // 초기화식
// 
// int main()
// {
// 	Draw();
// 	
// 	//Draw(300, 400);
// 
// 	return 0;
// }
// 
// void Draw()
// {
// 	cout << "hello world" << endl;
// }
// 
// void	Draw(int _iSrc, int _iData)
// {
// 	cout << _iSrc << '\t' << _iData << endl;
// }

#pragma endregion

#pragma region 재귀 함수

void	Recursive(int _iNumber);

int main()
{
	// 재귀 : 되돌아옴, 자기 자신에게 다시 돌아오는 상황
	
	// 1. 탈출 조건을 반드시 마련해야 한다.
	// 2. 큰 문제를 잘게 쪼개서 해결한다는 원칙과 철학을 소유하고 있는 문법

	// 장점 : 단순한 코드로 반복적인 문제를 해결 할 수 있다.
	// 단점 : 메모리 낭비가 심하고 동작의 속도가 느림.

	Recursive(3);

	return 0;
}

void	Recursive(int _iNumber)
{
	if (0 >= _iNumber)
		return;

	cout << "재귀 호출" << endl;

	Recursive(--_iNumber);
}

#pragma endregion

