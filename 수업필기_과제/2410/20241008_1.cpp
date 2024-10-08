#include <iostream>
// 1. 2중 for문과 배열을 이용하여 다음처럼 숫자를 출력하라
/*
1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25
*/
using namespace std;

int main()
{
	const int iCol(5); // 5개씩, 값 조절 가능
	int iArr[25];
	//int iArr[25] = {1,2,3,4,5,6,7,8,9,...} 어유귀찮아
	for (int i = 0; i < sizeof(iArr) / sizeof(int); ++i)
		iArr[i] = i + 1;

	for (int i = 0; i < sizeof(iArr) / sizeof(int); i += iCol)
	{
		for (int j = 0; j < iCol && i + j < sizeof(iArr) / sizeof(int); ++j)
		{					    // 'i + j < sizeof(iArr) / sizeof(int)' 이부분은 괜히 iCol변수로 열 조절 가능하게 만드려고 추가된 부분이므로 그냥 상수 5로 고정할 경우 필요 없음(25 % 5 == 0이니까)
			cout << iArr[i + j] << '\t';
		}
		cout << endl;
	}

	return 0;
}
