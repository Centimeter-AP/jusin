// 1. 2차원 배열을 이용하여 다음의 상태로 숫자 출력하기
// 1 2 3			 7 4 1
// 4 5 6 -90도 회전>  8 5 2   또 회 전 
// 7 8 9			 9 6 3

/*
* 
1	2	3				7	4	1				9	8	7				3	6	9				1	2	3
4	5	6	-90도 회전>	  8	  5   2 - 90도 회전 >  6   5   4 - 90도 회전 >	 2	 5	 8 - 90도 회전 >   4   5   6
7	8	9				9	6	3				3	2	1				1	4	7				7	8	9

*/

#include <iostream>

using namespace std;

void	PrintArr(int (*_pArr)[3]);

int main()
{
	int iArr[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	PrintArr(iArr);

	return 0;
}

void PrintArr(int (*_pArr)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3 ; ++j)
			cout << _pArr[i][j] << ' ';
		cout << endl;
	}
}
/*

1 2 3		7 4 1
4 5 6		8 5 2
7 8 9		9 6 3


*/