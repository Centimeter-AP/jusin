// 2. 빙고 게임 만들기
// 5*5배열 1~25 출력
// 입력한 숫자와 일치하는 값을 가진 배열은 *로 출력
// *로 이루어진 가로세로대각선다섯개 있을 시 빙고 1증가
// 5빙고 이상일 시 승리 후 게임 종료
// 빙고의 개수는 매 루프마다 출력
// 예시는... 파일 보세요
// 가능하면 컴퓨터와 배틀모드로(빙고두개로) 만들어볼것

// 1  2	 3			1	*	3		*	*	*
// 4  5	 6	-2입력>	 4	 5   6	->	 4	 5	 6
// 7  8	 9			7	8	9		7	8	9

#include <iostream>

using namespace std;

void	PrintArr(int (*_pArr)[5], int _pInput[]);
void	InitArr(int (*_pArr)[5]);
int 	CheckInput(int _iRow, int _iCol, int _pInput[]);
void	InputNumber(int _pInput[], int _iIndex);
int		IsBingo(int _pInput[]); // 빙고 판을 섞으면 사용불가....


int main()
{
	int iArr[5][5];
	int iInput[25] = {}; // 입력받은 숫자 수용소

	InitArr(iArr); // 배열 초기화
	PrintArr(iArr, iInput);

	for (int i = 0; i < 25; ++i)
	{
		InputNumber(iInput, i);
		PrintArr(iArr, iInput);
		if (IsBingo(iInput) == 5)
		{
			cout << "\n승리!" << endl;
			break;
		}
	}
	cout << "게임 종료!" << endl;
	return 0;
}

void	InputNumber(int _pInput[], int _iIndex)
{
	int i(0);

	while(1)
	{
		cout << "1 ~ 25의 남아있는 숫자를 입력해주세요 : ";
		cin >> _pInput[_iIndex];
		if (_pInput[_iIndex] >= 1 && _pInput[_iIndex] <= 25)	// 범위 내인지
		{
			for (i = 0; i < _iIndex; ++i)					// 이미 입력받은 숫자인지
			{
				if (_pInput[i] == _pInput[_iIndex])//중복이다!
					break;
			}
			if (i == _iIndex) // 중복 검사 통과
				break;
		}
		cout << "잘못 입력하셨습니다." << endl;
		if (cin.fail())								// cin이 정수를 받지 않은 경우 입력 버퍼 초기화
		{											// 그냥 넣음 (예외처리병)
			cin.clear();
			while (cin.get() == '\n') continue;
		}
	}
}

void	PrintArr(int (*_pArr)[5], int _pInput[])
{
	system("clear");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 ; ++j)
		{
			if (CheckInput(i, j, _pInput)) // 받아온 값을 계속 확인해야해서 비효율적인 것 같음..
			{
				cout << " *  ";
				continue ;
			}
			if (_pArr[i][j] < 10)		// 정렬
				cout << ' ';
			cout << _pArr[i][j] << "  ";
		}
		cout << endl;
	}
}

void InitArr(int (*_pArr)[5])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			_pArr[i][j] = i * 5 + j + 1;
	}
}

int CheckInput(int _iRow, int _iCol, int _pInput[]) // 5 * 5 배열만 고려됨 (수정가능)
{
	for (int i = 0; i < 25; ++i)
	{
		if (_pInput[i] == 0)
			return 0;
		if ((_pInput[i] - 1) / 5 == _iRow && (_pInput[i] - 1) % 5 == _iCol)
			return 1;
	}
	return 0;
}

int		IsBingo(int _pInput[])
{
	int iBingo(0);
	int iRow(0), iCol(0), iRDiag(0), iLDiag(0);

	for (int i = 0; i < 5; ++i)
	{
		iCol = 0;
		iRow = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (CheckInput(i, j, _pInput))
			{
				if (i == j)
					iLDiag++;
				if (i + j == 4)
					iRDiag++;
				iCol++;
			}
			if (CheckInput(j, i, _pInput))
				iRow++;
		}
		if (iCol == 5)		iBingo++;		// 가로 줄 빙고
		if (iLDiag == 5)	iBingo++;		// 좌상향 대각 빙고
		if (iRDiag == 5)	iBingo++;		// 우상향 대각 빙고
		if (iRow == 5)		iBingo++;		// 세로 줄 빙고
		// 대각선 빙고 어차피 2가지 경우의 수 밖에 없는데 하드코딩해도 괜찮지 않나...
	}
	cout << iBingo << " 빙고" << endl;
	return iBingo;
}