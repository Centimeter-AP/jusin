/*****************/
/*	 20240927_2	 */
/* 	  자판기 게임	*/
/*****************/

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

int main()
{
	int iMoney(0), iInput(0);
	char cGetchar(0);

	while (1)
	{
		cout << "현재 소지하신 금액을 입력해주세요 : ";
		cin >> iMoney;
		cout << "\n입력받은 금액: " << iMoney << endl;
		if (iMoney < 0)
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
		system("clear");
		cout << "\t\t|| 잔액: " << iMoney << "원 ||" << endl << endl;
		cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환" << endl;
		cout << "메뉴를 골라주세요.   ";
		cin >> iInput;
		if (iMoney < iInput * 100 && iInput < 4 && iInput > 0)
		{
			cout << "잔액이 부족합니다." << endl;
			cout << "계속하려면 아무 문자나 입력하세요 ..";
			cin >> cGetchar;
			continue;
		}
		switch (iInput)
		{
		case 1:
			iMoney -= 100;
			cout << "콜라 구매 완료" << endl;
			cout << "계속하려면 아무 문자나 입력하세요 ..";
			cin >> cGetchar;
			break;
		
		case 2:
			iMoney -= 200;
			cout << "사이다 구매 완료" << endl;
			cout << "계속하려면 아무 문자나 입력하세요 ..";
			cin >> cGetchar;
			break;

		case 3:
			iMoney -= 300;
			cout << "환타 구매 완료" << endl;
			cout << "계속하려면 아무 문자나 입력하세요 ..";
			cin >> cGetchar;
			break;

		case 4:
			cout << "거스름돈은 " << iMoney << "원 입니다." << endl;
			break;
		
		default:
			cout << "정확한 값을 입력해주세요." << endl;
			cout << "계속하려면 아무 문자나 입력하세요 ..";
			cin >> cGetchar;
			break;
		}
		if (iInput == 4)
			break;
		// system("pause"); 윈도우용 pause
		// getchar(); // 안타까운리눅스용
		// char cGetchar;
		// cin >> cGetchar; 이렇게도 될까?

	}

	return 0;
}
