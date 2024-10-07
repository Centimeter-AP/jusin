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
				cout << "�ݶ� ���� �Ϸ�" << endl;
				iMoney -= iCoke;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
			}
			break;

		case 2:
			if (iMoney >= iCider)
			{
				cout << "���̴� ���� �Ϸ�" << endl;
				iMoney -= iCider;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
			}
			break;

		case 3:
			if (iMoney >= iFanta)
			{
				cout << "ȯŸ ���� �Ϸ�" << endl;
				iMoney -= iFanta;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
			}
			break;

		case 4:
			cout << "�Ž��� ���� " << iMoney << " �� �Դϴ�" << endl;
			bSelect = false;
			break;

		default:
			cout << "�߸� �����̽��ϴ�" << endl;
			break;
		}		

		system("pause");
	}
}
int	Input_Cash()
{
	int		iMoney(0);

	cout << "���� �־��ּ��� : ";
	cin >> iMoney;

	return iMoney;
}
int Show_Menu(int _iMoney)
{
	int iInput(0);

	cout << "�ܾ� : " << _iMoney << endl;
	cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ : ";
	cin >> iInput;

	return iInput;
}