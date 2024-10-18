#include <iostream>

// 2. 셔플알고리즘을 함수에 적용해 구현 (포인터쓰세요)

using namespace std;

void	Shuffle(int *_iDst, int *_iSrc);

int main()
{
	int		iDst(10), iSrc(20);
	int		iTmp(0);

	cout << iDst << "\t" << iSrc << endl;

	Shuffle(&iDst, &iSrc);

	cout << iDst << "\t" << iSrc << endl;

	return 0;
}

void	Shuffle(int *_iDst, int *_iSrc)
{
	int	iTmp(0);

	iTmp = *_iDst;
	*_iDst = *_iSrc;
	*_iSrc = iTmp;
}

//이게끝?