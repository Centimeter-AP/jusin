/*	2. 2중 for 문을 이용하여 구구단 입력한 단과 곱만큼만 출력	*/

#include <iostream>

using namespace std;

int main()
{
	int iInputI(0), iInputJ(0);
	cout << "단을 입력해주세요.  ";
	cin >> iInputI;
	cout << "곱을 입력해주세요.  ";
	cin >> iInputJ;

	for (int i = 2; i <= iInputI; ++i)
	{
		for (int j = 1; j <= iInputJ; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	return 0;
}
