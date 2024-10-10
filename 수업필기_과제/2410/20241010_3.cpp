// 3. 숫자 이동 시키기 
// 5*5 0~24 출력하기
// 2(하) 4(왼) 6(우) 8(상)의 메뉴 출력 
// 선택한 번호에 따라 숫자 0을 이동시켜 출력
// 맨 끝줄에서는 이동하지 못하도록 예외처리 하기
// ex)
// 0 1 2			3 1 2
// 3 4 5	하 입력	  0 4 5
// 6 7 8			6 7 8

#include <iostream>

using namespace std;

void	InitArr(int (*_pArr)[5]);
void	PrintArr(int (*_pArr)[5]);
int		InputNumber();
void	FindZero(int *i, int *j, int (*_pArr)[5]);
void	MoveDown(int (*_pArr)[5]);
void	MoveLeft(int (*_pArr)[5]);
void	MoveRight(int (*_pArr)[5]);
void	MoveUp(int (*_pArr)[5]);

int main()
{
	int iArr[5][5];
	void (*pMove[4])(int(*)[5]) = { MoveDown, MoveLeft, MoveRight, MoveUp }; // 내가이런거써야되냐진짜그치만배운건한번정도써야겠죠
	InitArr(iArr);
	while(1)
	{
		PrintArr(iArr);
		pMove[(InputNumber() - 1)](iArr);
	}
	return 0;
}

void InitArr(int (*_pArr)[5])
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			_pArr[i][j] = i * 5 + j;
	}
}

void	PrintArr(int (*_pArr)[5])
{
	system("clear");
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5 ; ++j)
		{
			cout << _pArr[i][j] << '\t';
		}
		cout << endl;
	}
}

int	InputNumber()
{
	int iInput(0);
	cout << "\n\t\t\t8(상)\n\t\t4(왼)\t2(하)\t6(우)" << endl;
	while(1)
	{
		cout << "방향 입력(숫자) : ";
		cin >> iInput;
		if (iInput == 2 || iInput == 4 || iInput == 6 || iInput == 8)
			return (iInput / 2);
		else
			cout << "2 4 6 8 중에 하나를 입력해주세요." << endl;
		if (cin.fail())								// cin이 정수를 받지 않은 경우 입력 버퍼 초기화
		{											// 그냥 넣음 (예외처리병)
			cin.clear();
			while (cin.get() == '\n') continue;
		}
	}
	return -1;
}

void FindZero(int *i, int *j, int (*_pArr)[5])
{
	for(*i = 0; *i < 5; ++(*i))
	{
		for (*j = 0; *j < 5; ++(*j))
		{
			if (_pArr[*i][*j] == 0)
				return ;
		}
	}
}

void MoveDown(int (*_pArr)[5])
{
	int i(0), j(0);
	FindZero(&i, &j, _pArr);
	if (i + 1 <= 4)
		swap(_pArr[i][j],_pArr[i + 1][j]);
}

void MoveLeft(int (*_pArr)[5])
{
	int i(0), j(0);
	FindZero(&i, &j, _pArr);
	if (j - 1 >= 0)
		swap(_pArr[i][j],_pArr[i][j - 1]);
}

void MoveRight(int (*_pArr)[5])
{
	int i(0), j(0);
	FindZero(&i, &j, _pArr);
	if (j + 1 <= 4)
		swap(_pArr[i][j],_pArr[i][j + 1]);
}

void MoveUp(int (*_pArr)[5])
{
	int i(0), j(0);
	FindZero(&i, &j, _pArr);
	if (i - 1 >= 0)
		swap(_pArr[i][j],_pArr[i - 1][j]);
}
