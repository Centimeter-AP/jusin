#include <iostream>

using namespace std;

void Main_Game();
int	Input_Cash();
int Show_Menu(int _iMoney);

int main()
{
	Main_Game();	

	return 0;
}

void Main_Game()
{
	int		iMoney(0), iInput(0), iCoke(100), iCider(200), iFanta(300);
	bool	bSelect(true);

	iMoney = Input_Cash();	

	while (bSelect)
	{
		system("cls");

		switch (Show_Menu(iMoney))
		{
		case 1:
			if (iMoney >= iCoke)
			{
				cout << "콜라 구매 완료" << endl;
				iMoney -= iCoke;
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			break;

		case 2:
			if (iMoney >= iCider)
			{
				cout << "사이다 구매 완료" << endl;
				iMoney -= iCider;
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			break;

		case 3:
			if (iMoney >= iFanta)
			{
				cout << "환타 구매 완료" << endl;
				iMoney -= iFanta;
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			break;

		case 4:
			cout << "거스름 돈은 " << iMoney << " 원 입니다" << endl;
			bSelect = false;
			break;

		default:
			cout << "잘못 누르셨습니다" << endl;
			break;
		}		

		system("pause");
	}
}
int	Input_Cash()
{
	int		iMoney(0);

	cout << "돈을 넣어주세요 : ";
	cin >> iMoney;

	return iMoney;
}
int Show_Menu(int _iMoney)
{
	int iInput(0);

	cout << "잔액 : " << _iMoney << endl;
	cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
	cin >> iInput;

	return iInput;
}