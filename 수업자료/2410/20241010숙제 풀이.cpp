// 241010.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime>

using namespace std;

#pragma region 숫자 출력

// int main()
// {
// 	int		iArray[25] = { };
// 
// 	for (int i = 0; i < 25; ++i)
// 	{
// 		iArray[i] = i + 1;
// 	}
// 	
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		for (int j = 0; j < 5; ++j)
// 		{
// 			int	iIndex = i * 5 + j;
// 
// 			cout << iArray[iIndex] << "\t";
// 		}
// 
// 		cout << endl;
// 	}
// 
// }

#pragma endregion

#pragma region 로또

// void	Bubble_Sort(int pArray[], int iCount);
// 
// int main()
// {
// 	srand(unsigned(time(NULL)));
// 
// 	int		iArray[45] = {};
// 	int		iLotto[6] = { };
// 
// 	for (int i = 0; i < 45; ++i)
// 	{
// 		iArray[i] = i + 1;
// 	}
// 
// 	int		iDst(0), iSrc(0);
// 
// 	for (int k = 0; k < 5; ++k)
// 	{
// 		for (int j = 0; j < 500; ++j)
// 		{
// 			iDst = rand() % 45;	// 13
// 			iSrc = rand() % 45;	// 27
// 
// 			swap(iArray[iDst], iArray[iSrc]);
// 		}
// 
// 		for (int i = 0; i < 6; ++i)
// 			iLotto[i] = iArray[i];
// 
// 		Bubble_Sort(iLotto, sizeof(iLotto) / sizeof(int));
// 
// 		for (int i = 0; i < 6; ++i)
// 		{
// 			cout << iLotto[i] << "\t";
// 		}
// 
// 		cout << endl;
// 	}
// 
// }
// 
// void	Bubble_Sort(int pArray[], int iCount)
// {
// 	for (int i = 0; i < iCount; ++i)
// 	{
// 		for (int j = 0; j < iCount - 1; ++j)
// 		{
// 			if (pArray[j] > pArray[j + 1])
// 			{
// 				swap(pArray[j], pArray[j + 1]);
// 			}
// 		}
// 	}
// }

// 자료 구조: 컴퓨터 프로그램을 구현하기 위해 연구된 것
// 자료를 처리하기 위한 명령의 집합을 구성 -> 컴퓨터에 자료를 효율적으로 저장하고 탐색

// 1. 메모리를 절약하기 위해 필요
// 2. 프로그램 수행 시간을 최소화

// 알고리즘 : 컴퓨터 명령 자체의 효율성을 증가시키기 위한 절차(방법)

// 1. 자연어
// 2. 순서도
// 3. 의사코드
// 4. 프로그래밍 언어

// 알고리즘 성능 분석 : 시간 복잡도를 더 중요한 평가 기준으로 삼음.

// 1. 공간 복잡도
// 2. 시간 복잡도
	// 2-1. 오메가 표기법 : 알고리즘 수행 시간 중 가장 좋은 것을 기준으로 성능 평가
	// 2-2. 빅오 표기법   : 알고리즘 수행 시간 중 가장 나쁜 것을 기준으로 성능 평가
	// 2-3. 세타 표기법   : 알고리즘 수행 시간 중 가장 좋은 것과 가장 나쁜 것의 평균 값으로 성능 평가

#pragma endregion

#pragma region 야구 게임

void		Init_BaseBall(int _pArray[], int _iCount);
int			Check_Strike(int _pAnswer[], int _pInput[], int _iCount);
int			Check_Ball(int _pAnswer[], int _pInput[], int _iCount);

int main()
{
	srand(unsigned(time(NULL)));

	int		iArray[9] = {};
	int		iAnswer[3] = {};
	int		iInput[3] = {};

	int		iStrike(0), iBall(0);
	int		iCount(0);

	Init_BaseBall(iArray, sizeof(iArray) / sizeof(int));

	for (int i = 0; i < 3; ++i)
		iAnswer[i] = iArray[i];

	while (true)
	{
		system("cls");

		if (9 <= iCount)
		{
			cout << "인간이냐? 패배" << endl;
			break;
		}

		cout << "정답 : " << iAnswer[0] << '\t' << iAnswer[1] << '\t' << iAnswer[2] << endl;
		cout << iCount + 1 << " 회차 입력 : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		++iCount;

		iStrike = Check_Strike(iAnswer, iInput, sizeof(iAnswer)/ sizeof(int));
		iBall = Check_Ball(iAnswer, iInput, sizeof(iAnswer) / sizeof(int));

		cout << iStrike << " 스트라이크\t" << iBall << " 볼" << endl;

		if (3 == iStrike)
		{
			cout << iCount << " 회차 승리!" << endl;
			break;
		}

		system("pause");
	}

	return 0;
}

#pragma endregion

void Init_BaseBall(int _pArray[], int _iCount)
{
	for (int i = 0; i < _iCount; ++i)
	{
		_pArray[i] = i + 1;
	}

	int iDst(0), iSrc(0);

	for (int i = 0; i < 500; ++i)
	{
		iDst = rand() % 9;
		iSrc = rand() % 9;

		swap(_pArray[iDst], _pArray[iSrc]);
	}

}

int Check_Strike(int _pAnswer[], int _pInput[], int _iCount)
{
	int		iStrike(0);

	for (int i = 0; i < _iCount; ++i)
	{
		if (_pAnswer[i] == _pInput[i])
			++iStrike;
	}


	return iStrike;
}

int Check_Ball(int _pAnswer[], int _pInput[], int _iCount)
{
	int		iBall(0);

	for (int i = 0; i < _iCount; ++i)
	{
		for (int j = 0; j < _iCount; ++j)
		{
			if (i == j)
				continue;

			if (_pAnswer[i] == _pInput[j])
				++iBall;
		}
	}


	return iBall;
}
