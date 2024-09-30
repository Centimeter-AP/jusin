/*****************/
/*	 20240927_1	 */
/* 	  구구단 과제	*/
/*****************/

// 1. 구구단 2~9단 while문 이용해서 출력하기

#include <iostream>

using namespace std;

int main()
{
	int	i(1), j(0);

	/* 세로 */

	// while(++i < 10)
	// {
	// 	while (++j < 10)
	// 	{
	// 		cout << i << " * " << j << " = " << (i * j) << endl;
	// 	}
	// 	j = 0;
	// 	cout << endl;
	// }

	// i = 1;
	// j = 0;


	/* 가로 */

	while (++j < 10)
	{
		while (++i < 10)
		{
			cout << i << " * " << j << " = " << (i*j);
			cout << '\t';
		}
		i = 1;
		cout << endl;
	}

	//숙제풀이는 while 안에 if조건문으로(while두번안하고)


	return 0;
}
