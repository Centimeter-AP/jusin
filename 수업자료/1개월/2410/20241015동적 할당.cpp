#include <iostream>

using namespace std;



const char* Func()
{
	// char	szName[32] = "";
	// cin >> szName;
	// return szName;

	char*	pHeapName = (char*)calloc(32, sizeof(char));

	cin >> pHeapName;

	return pHeapName;
}

int main()
{

	 //char* pName = Func();
	 //cout << pName << endl;
	 //
	 //free(pName);
	 //pName = NULL;


	// 동적 할당 : 메인 메모리 중 heap 영역을 사용하며, 런 타임에 메모리를 할당하고 해제하는 문법을 일컫는다.

	// 1. 포인터 없이 heap 영역에 접근 할 수 없다.
	// 2. 메모리 반환을 반드시 해줘야만 메모리 누수가 발생하지 않는다. 
	// 3. 프로그램 논리에 따라 언제 할당하고 언제 반환할 지 프로그래머가 결정해야 한다.
	// 4. heap 영역에는 변수의 이름을 붙일 수 없다.

	/////////////////////////////////////////////////////////////////////////

#pragma region c언어 동적할당

	// c언어 동적할당 방식 : 함수를 사용한 방식
	// 
	// void* malloc(size_t size)
	// void* calloc(size_t count, size_t size)

	// void	free(void* pointer);

	// void* (void 포인터) : 어떤 자료형의 주소인지 알 수 없을 때 대체하여 사용하는 포인터,
	// 주소를 이용하여 실제 메모리 공간에 접근하고자 할 때(포인터를 사용하고자 할 때)는 반드시 명시적인 형 변환을 해줘야 한다.

	// 동적 배열 : 런 타임 시에 할당하는 배열

	// int* p = NULL;
	// 
	// p = (int*)malloc(sizeof(int));
	// 
	// *p = 10;
	// 	
	// cout << p << endl;
	// cout << *p << endl;
	// 
	// free(p);	// 사용했던 heap 메모리 반환
	// p = NULL;	// 댕글링 포인터가 발생하지 않도록 반드시 포인터를 null로 채워줘야 한다.
	// 
	// cout << "------------------------" << endl;
	// 
	// cout << p << endl;		// 댕글링 포인터 
	// 
	// *p = 20;
	// 
	// cout << *p << endl;


	//p = (int*)malloc(sizeof(int) * 4);
	//p = (int*)calloc(4, 4);		// 할당한 heap 영역을 자동 0 초기화 해줌

	// cout << p << endl;
	// 
	// p[0] = 10;
	// p[1] = 20;
	// p[2] = 30;
	// p[3] = 40;

	// for (int i = 0; i < 4; ++i)
	// 	cout << p[i] << endl;

	// *p = 10;
	// cout << *p << endl;

#pragma endregion

#pragma region c++ 동적할당

	 // int* p = new int(100);
	 // 
	 // cout << p << endl;
	 // cout << *p << endl;
	 // 
	 // cout << "-------------------" << endl;
	 // 
	 // *p = 10;
	 // 
	 // cout << *p << endl;
	 // 
	 // delete p;
	 // p = nullptr;

	// int		iInput(0);
	// cin >> iInput;
	// 
	// int* p = new int[iInput]{10, 20, 30};
	// 
	// for (int i = 0; i < iInput; ++i)
	// 	cout << p[i] << endl;
	// 
	// delete[] p;		// 동적 배열을 메모리 반환하는 문법
	// p = nullptr;

#pragma endregion

	return 0;
}