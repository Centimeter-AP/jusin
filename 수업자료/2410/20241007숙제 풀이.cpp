// 241007.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#pragma region 재귀 함수

// int Factorial(int _iNumber);
// 
// int main()
// {
// 	 cout << Factorial(100) << endl;
// 
// 	return 0;
// }
// 
// int	Factorial(int _iNumber)
// {
//  	if (0 == _iNumber)
// 		  return 1;
// 
// 	return _iNumber * Factorial(_iNumber - 1);
// }

#pragma endregion

#pragma region 셔플 

void		Swap(int* _pDst, int* _pSrc);		// call by reference : 참조에 의한 호출

int main()
{
	int		iDst(10), iSrc(20);

	cout << iDst << '\t' << iSrc << endl;

	Swap(&iDst, &iSrc);

	cout << iDst << '\t' << iSrc << endl;

	return 0;
}

void		Swap(int* _pDst, int* _pSrc)
{
	int		 iTmp(0);

	 iTmp   = *_pDst;
	 *_pDst = *_pSrc;
	 *_pSrc = iTmp;
}

#pragma endregion