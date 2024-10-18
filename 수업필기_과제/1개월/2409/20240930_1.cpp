/*	1. 2중 for 문을 이용하여 구구단 2~9단 출력	*/
/*	슬픈 소식: 이미 while로 했다	*/

#include <iostream>

using namespace std;

int main()
{
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	//와정말편하다 !!
	return 0;
}
