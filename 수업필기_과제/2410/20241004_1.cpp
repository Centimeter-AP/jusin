#include <iostream>

// 1. 5팩토리얼 재귀함수로 구현

using namespace std;

// int	Factorial(int _iNum, int _iResult = 1);
int Factorial(int _iNum);

int main()
{
	cout << "5팩토리얼 : " << Factorial(5) << endl;
	return 0;
}

// int	Factorial(int _iNum, int _iResult)
// {
// 	if (_iNum > 0)
// 	{
// 		_iResult *= _iNum;
// 		_iResult = Factorial(--_iNum, _iResult);
// 	}
// 	return _iResult;
// }

int	Factorial(int _iNum)
{
	if (_iNum < 0)
		return 0;
	else if (_iNum >= 1)
		return (_iNum * Factorial(_iNum - 1));
	else
		return 1;

}
