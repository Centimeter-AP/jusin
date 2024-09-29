/******************/
/*	 20240927_3	  */
/* 	  홀짝 게임		*/
/******************/

// 3. 홀짝 게임
//	- 난수를 이용해서 숫자를 매 회차마다 발생시킴
//	- 난수를 이용하여 홀과 짝을 맞추면 됨
// 	- 총 5회 실시하여 마지막 라운드가 종료되고 난 뒤, 승 패 출력
//	- '1. 홀 2. 짝 3. 종료'
//	- ' 정답 / 오답 '
//	- 5회 반복 후 n승 m패 출력 후 종료
//	- 윈도우 환경이면 system("cls"); , system("pause");가 되는데 맥북은어떡하쥬?ㅎㅎ

#include <iostream>

using namespace std;

int main()
{
	time_t	tSeed;
	int i(0), iRand(0), iInput(0), iCorrect(0), iIncorrect(0);
	char cGetchar(0);
	time(&tSeed);
	srand(tSeed);

	cout << "홀짝 게임을 시작합니다." << endl;
	cout << "총 5회 실시하며, 중간에 종료를 입력해 게임을 종료할 수 있습니다.\n" << endl;

	while (i++ < 5)
	{
		cout << i << "번째 게임입니다." << endl;
		while (1)
		{
			time(&tSeed);
			srand(tSeed);
			iRand = rand();
			cout << "1. 홀  2. 짝  3. 종료" << endl;
			cin >> iInput;
			if (iInput == 3)
			{
				cout << "게임을 종료합니다." << endl;
				break;
				// exit(0);		exit사용시 외부 while의 input==3 조건 break 안써도 됨
			}
			else if (iInput > 3 || iInput < 1)
			{
				system("clear");
				cout << "1에서 3 사이의 정수만을 입력 할 수 있습니다." << endl;
				continue;
			}
			if (iRand % 2 == iInput % 2)
			{
				cout << "정답입니다." << endl;
				iCorrect++;
				cout << "계속하려면 아무 문자나 입력하세요 ..";
				cin >> cGetchar;
				system("clear");
				break;
			}
			else
			{
				cout << "오답입니다." << endl;
				iIncorrect++;
				cout << "계속하려면 아무 문자나 입력하세요 ..";
				cin >> cGetchar;
				system("clear");
				break;
			}
		}
		if (iInput == 3)
			break;
	}
	if (iInput == 3)
		return 0;
	cout << iCorrect << "승 " << iIncorrect << "패 하셨습니다." << endl;
	
	return 0;
}
