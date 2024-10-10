#include <iostream>
// 2. 로또 만들기
// - 1~45 사이 중 6개의 숫자를 5회 출력하기
// - 같은 회차(한 줄)에서 중복된 숫자는 존재할 수 없음
// - 출력된 숫자는 오름차순으로 정렬(버블 소트)(하-드모드)
/*
1	2	3	4	5	6
2	4	6	7	9	10
1	2	3	4	5	6
1	2	3	4	5	6
2	4	6	7	9	10
1	2	3	4	5	6
귀찮아서복붙함
*/

// 난수를 뽑고 중복인지 확인하기(내방법)
// 1~45 숫자를 넣은 배열 만들어서 뒤섞기 - 중복확인 할 필요없음(선생님)
// 인덱스에난수넣고 swap()
// 조건이 명확한 숫자면 .. 

using namespace std;

bool	IsDup(int *_iArr, int _iIndex);
void	MakeLottoNum(int *_iArr);
void	BubbleSort(int *_iArr);
void	PrintLotto(int *_iArr);
void	LottoMaker(int *_iArr, int _iNum);

int main()
{
	int iArr[6] = {};

	srand(time(NULL)); // 시드 지정

	LottoMaker(iArr, 5); // 넣은 숫자 만큼의 회차 반복

	return 0;
}

bool	IsDup(int *_iArr, int _iIndex) 
{
	for (int i = 0; _iArr[i] != 0 && i < _iIndex; ++i)
	{
		if (_iArr[i] == _iArr[_iIndex])
			return true;
	}
	return false;
}

void	MakeLottoNum(int *_iArr)
{
	int i = 0;

	while (i < 6)
	{
		_iArr[i] = rand() % 45 + 1; // 난수 생성

		// 조건: i가 0이 아니어서 비교대상이 있는 경우가 참이며 (AND)
		// 		IsDup(중복인지?) 함수가 true(중복이다)를 반환했을 경우
		if (i != 0 && IsDup(_iArr, i))
			continue ; // 이번 번호의 생성을 무효로 하고 i를 증가시키지 않고 번호 재생성
		i++; // 인덱스 증가
	}	
}

void	BubbleSort(int *_iArr)
{
	int iTmp(0);	// swap();함수로 생략가능
	for (int i = 6; i > 0; --i)
	{
		for (int j = 0; j < i - 1; ++j)  // 조건식에서 i에 -1을 해주지 않으면
		{								
			if (_iArr[j] > _iArr[j + 1]) // 여기 비교식에서 배열 범위 밖의 값과 비교하게 됨 !! 주의 !!
			{
				iTmp = _iArr[j];
				_iArr[j] = _iArr[j + 1];
				_iArr[j + 1] = iTmp;
			}
		}
	}
}

void	PrintLotto(int *_iArr)
{
	for (int i = 0; i < 6; ++i)
		cout << _iArr[i] << '\t';
	cout << endl;
}

void	LottoMaker(int *_iArr, int _iNum)
{
	// _iNum회차 반복
	for (int i = 0; i < _iNum; ++i)
	{
		// 한 회차의 배열에 랜덤 값 추가
		MakeLottoNum(_iArr);
		// 버블소트
		BubbleSort(_iArr);
		// 로또 1회차 출력
		PrintLotto(_iArr);
	}
}

