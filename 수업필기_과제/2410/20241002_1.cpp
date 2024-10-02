//	자 판 기 게 임 ver.Func 
//	우 와 정 말 데 단 헤

// 2. 자판기 게임 구현하기
//	- 소지금을 입력받기
//	- 현재 소지금의 잔액 상태를 화면에 출력
//	- 메뉴: 1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환
//	- 해당 목록 선택, 구매 시, 보유 잔액 바뀌고, 'xx구매 완료' 라고 출력
//	- 단, 잔액이 부족할 경우 '잔액이 부족합니다' 라고 출력
//	- 4번을 누를 경우, '거스름 돈은 xx원 입니다' 출력 후 게임 종료

#include <iostream>
#include <stdio.h>

using namespace std;

int		GetMoney();
//		돈을 넣어달라는 안내문 출력 후 입력받아 그 값을 반환
bool	CheckValidMoney(int _iMoney);
//		입력받은 돈이 유효한지 판단 (조건: 양수) 무효할 시 참 반환
void	PrintMenu(int _iMoney);
//		메뉴판 및 잔액 출력
bool	CheckValidInput(int _iInput, int _iMoney);
//		잔액이 입력받은 메뉴 가격 이상 남아있는지 판단 없을 시 잔액부족 출력 후 참 반환	
void	SadLinuxPause();
//		슬픈 리눅스의 system("pause"); 따라하기,,
int		Purchase(int _iMoney, int _iInput, string _sMenu);
//		들어온 _iInput값에 따라 구매 후 인자로 받은 메뉴 메세지 출력 후 잔액을 차감하고 차감된 잔액을 반환


int main()
{
	int iMoney(0), iInput(0);

	while (1)
	{
		iMoney = GetMoney(); // GetMoney(&iMoney); ...
		if (CheckValidMoney(iMoney))
		{
			// system("cls"); 윈도우파워쉘용
			system("clear"); //안타까운리눅스용
			cout << "!!정확한 금액을 입력해주세요.!!\n0 이상의 양수만 입력 가능합니다." << endl;
		}
		else
			break ;
	}

	while (1)
	{
		PrintMenu(iMoney);
		cin >> iInput;
		if (CheckValidInput(iInput, iMoney))
			continue;
		switch (iInput)
		{
		case 1:
			iMoney = Purchase(iMoney, iInput, "콜라"); // 이거도 Purchase(&iMoney, iInput, "콜라"); 가..
			SadLinuxPause();
			break;
		
		case 2:
			iMoney = Purchase(iMoney, iInput, "사이다");
			SadLinuxPause();
			break;

		case 3:
			iMoney = Purchase(iMoney, iInput, "환타");
			SadLinuxPause();
			break;

		case 4:
			cout << "거스름돈은 " << iMoney << "원 입니다." << endl;
			break;
		
		default:
			cout << "정확한 값을 입력해주세요." << endl;
			SadLinuxPause();
			break;
		}
		if (iInput == 4)
			break;

		// system("pause"); 윈도우용 pause
		// getchar(); // 안타까운리눅스용
		// char cGetchar;
		// cin >> cGetchar; 이렇게도 될까? 이렇게밖에 안되네 왜 getchar가 \n을 못읽지?
	}

	return 0;
}

int		Purchase(int _iMoney, int _iInput, string _sMenu)
{
	_iMoney -= _iInput * 100;
	cout << _sMenu << " 구매 완료" << endl;
	return _iMoney;
}

void	SadLinuxPause()
{
	char cGetchar(0); //안타까운리눅스인생최후의system("pause")끌어치기
	cout << "계속하려면 아무 문자나 입력하세요 ..";
	cin >> cGetchar;
}

void	PrintMenu(int _iMoney)
{
	system("clear");
	cout << "\t\t|| 잔액: " << _iMoney << "원 ||" << endl << endl;
	cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환" << endl;
	cout << "메뉴를 골라주세요.   ";
}

bool	CheckValidInput(int _iInput, int _iMoney)
{
	if (_iMoney < _iInput * 100 && _iInput < 4 && _iInput > 0)
	{
		cout << "잔액이 부족합니다." << endl;
		SadLinuxPause();
		return 1;
	}
	else
		return 0;
}

bool	CheckValidMoney(int _iMoney)
{
	if (_iMoney < 0)
		return 1;
	else
		return 0;
}

int		GetMoney()
{
	int iMoney(0);

	cout << "현재 소지하신 금액을 입력해주세요 : ";
	cin >> iMoney;
	cout << "\n입력받은 금액: " << iMoney << endl;

	return iMoney;
}
