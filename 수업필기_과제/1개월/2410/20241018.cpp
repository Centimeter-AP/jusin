#include <iostream>

// 2개월 들어가기 앞서 이것저것 맛보기?

using namespace std;

typedef struct test
{
	int i;
	int j;
}TEST;

int main()
{
	// 레퍼런스 : c++에서 등장한 자료 타입으로 주소를 "직접적으로 참조" 가능한 자료형
	// 포인터는 주소를 포인터변수에 담아놓고 그걸 이용해 참조하는 것이기 때문에 간접 참조임
	// 1. 레퍼런스는 선언과 동시에 참조 대상으로 초기화해야함
	// 2. 참조된 레퍼런스는 다른 변수를 재참조할 수 없고 초기에 참조한 것을 뒤질 때 까지 바꿀 수 없다
	// 3. 레퍼런스는 l-value만 참조가 가능하다 (모던c++에서 r-value도 참조할 수 있게 하는게 있지만 나중에)
	// 3-1. r-value(상수..)를 굳이굳이 참조해야겠다면 const를 앞에 붙여 읽기전용으로 참조하면 되긴 하는데 왜굳이..

	TEST *tTest = new TEST;

	TEST*& rTest = tTest;

	rTest->i = 10;

	cout << rTest->i << endl;

	delete rTest;		// 이딴걸 저희가 써야하나요???그냥포인터를해제하세요...

	return 0;
}
