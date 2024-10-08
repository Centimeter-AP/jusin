#include <iostream>
// 3. 야구 게임 만들기
// - 1~9까지 무작위 수 3개 추출(단, 한번만) 하고 출력(매 회 마다)
// - 정렬은 X
// - 숫자 세 개를 입력하여 입력한 수와, 무작위 수의 값과 자리가 일치하면 스트라이크
// - 값만 일치하면 볼이 증가
// - 매 회 몇 스트라이크 몇 볼인지 출력
// - 3스트라이크일 경우 '승리' 출력 후 종료
// - 9라운드까지 진행할 때, 3 스트라이크를 만들지 못하면 '패배' 출력 후 종료

// 지역변수랑 전역변수 명칭을 헷갈렸다....

using namespace std;


void	BaseballGame(int *_iArr, int *_iAns, int _iIndex);
void	MakeGameNum(int *_iArr, int _iIndex);
void	PrintArray(int *_iArr, int _iIndex);

int main()
{
	const int iNum = 3;  // 야구 게임을 몇자리로 할 지 결정
	int iArr[iNum] = {}; // 정답 저장 배열
	int iAns[iNum] = {}; // 입력받은 값 저장 배열
	srand(time(NULL));

	BaseballGame(iArr, iAns, iNum);
	
	return 0;
}

void	MakeGameNum(int *_iArr, int _iIndex)
{
	for (int i = 0; i < _iIndex; ++i)
		_iArr[i] = rand() % 9 + 1;
}

void	PrintArray(int *_iArr, int _iIndex)
{
	for (int i = 0; i < _iIndex; ++i)
	{
		cout << _iArr[i] << " ";
	}
	cout << endl;
}

void	BaseballGame(int *_iArr, int *_iAns, int _iIndex)
{
	int iStrike, iBall; // 어차피 반복 돌면서 무조건 계속 0으로 대입할 예정이므로 초기화 안했음

	MakeGameNum(_iArr, _iIndex); // 이번 게임 난수값 생성 (중복 가능)

	for (int iRound = 0; iRound < 9; ++iRound)
	{
		system("clear"); 	// windows는 cls가 맞음

		cout << iRound + 1 << "라운드";
		if (iRound > 0)		// 첫 라운드에는 n스트라이크 m볼 출력 방지
			cout << "\t\t" << iStrike << " 스트라이크 " << iBall << " 볼";
		cout << endl;
		PrintArray(_iArr, _iIndex); // 배열 출력 함수

		cout << "입력: ";
		for (int i = 0; i < _iIndex; ++i)
			cin >> _iAns[i];		// 숫자 입력 받을 시 스페이스바, 개행 전부 구분 문자로 인식(놀랍다)

		iStrike = iBall = 0;		// 0으로 초기화

		for (int i = 0; i < _iIndex; ++i)
		{
			if (_iArr[i] == _iAns[i]) // 같은 자리끼리 값 먼저 비교 (Strike)
			{
				iStrike++;
				_iAns[i] = -1;		  // 이후 중복값 비교를 방지하기 위해 쓰지 않는 값으로 채움
				continue ;			  // ball 확인 하지 않고 다음 인덱스로 넘어감 / else로 해도 되지 않을지?
			}
			for (int j = 0; j < _iIndex; ++j)
			{
				if (_iArr[i] == _iAns[j]) // Ball인지 확인
				{
					iBall++;
					break ;				// Ball일 시 다른 인덱스 값들은 더 비교하지 않고 Ball 1만 증가시키고 반복 탈출
				}
			}
		}
		if (iStrike == _iIndex)			// 전부 다 맞춘 경우
		{
			cout << "\n승리!" << endl;
			break;
		}
		else if(iRound + 1 == 9)		// 다음 조건 비교 시 iRound == 9라서 10라운드가 되는 경우(마지막라운드인경우)
			cout << "\n패배!" << endl;	 // 9라운드인데도 위의 iStrike == _iIndex가 되지 못함 => 못맞췄다
	}
	// 윗부분 함수로 빼고싶은데 for문을 전부 넣으면 BaseballGame()이 너무 텅텅비고
	// for문 안에서 기능을 뽑아 만들자니 매개변수로 넘길게 너무너무 많아짐..(배열 두개 + index, strike&ball, round...)
}