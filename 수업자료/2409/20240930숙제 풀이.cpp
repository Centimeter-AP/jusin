#include <iostream>
#include <ctime>

using namespace std;

#pragma region ������

// int main()
// {
// 	int i = 2;
// 	int j = 1;
// 
// 	while (10 > i)
// 	{
// 		cout << i << " * " << j << " = " << i * j << endl;
// 		j++;
// 
// 		if (9 < j)
// 		{
// 			i++;
// 			j = 1;
// 			cout << "---------------------------------" << endl;
// 		}
// 	}	
// 
// 	return 0;
// }

#pragma endregion ������

#pragma region ���Ǳ� ����

//int main()
//{
//	int		iMoney(0), iInput(0), iCoke(100), iCider(200), iFanta(300);
//	bool	bSelect(true);
//
//	cout << "���� �־��ּ��� : ";
//	cin >> iMoney;
//
//	while (bSelect)
//	{
//		system("cls");
//
//		cout << "�ܾ� : " << iMoney << endl;
//		cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ : ";
//		cin >> iInput;
//
//		if (1 == iInput)
//		{
//			if (iMoney >= iCoke)
//			{
//				cout << "�ݶ� ���� �Ϸ�" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (iMoney >= iCider)
//			{
//				cout << "���̴� ���� �Ϸ�" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			if (iMoney >= iFanta)
//			{
//				cout << "ȯŸ ���� �Ϸ�" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "�ܾ��� �����մϴ�" << endl;
//			}
//		}
//		else if (4 == iInput)
//		{
//			cout << "�Ž��� ���� " << iMoney << " �� �Դϴ�" << endl;
//			bSelect = false;
//		}
//		else
//		{
//			cout << "�߸� �����̽��ϴ�" << endl;
//		}
//
//		system("pause");
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region Ȧ¦

// int main()
// {
// 	srand(unsigned(time(NULL)));
// 
// 	int	 iInput(0), iRound(5), iWin(0), iLose(0), iAnswer(0);
// 	bool bSelect(true);
// 
// 	while ((bSelect) && (0 < iRound))
// 	{
// 		system("cls");
// 
// 		iAnswer = rand() % 10 + 1;
// 
// 		cout << "���� : " << iAnswer << endl;
// 		cout << iRound << "ȸ ���ҽ��ϴ�" << endl;
// 		cout << "1. Ȧ 2. ¦ 3. ����" << endl;
// 		cin >> iInput;
// 
// 		iRound--;
// 
// 		if (1 == iInput)
// 		{
// 			if (0 == iAnswer % 2)
// 			{
// 				cout << " ��ǻ�� : ¦" << endl;
// 				cout << " ����� : Ȧ" << endl;
// 				cout << "�����Դϴ�" << endl;
// 				iLose++;
// 			}
// 
// 			else if (0 != iAnswer % 2)
// 			{
// 				cout << " ��ǻ�� : Ȧ" << endl;
// 				cout << " ����� : Ȧ" << endl;
// 				cout << "�����Դϴ�" << endl;
// 				iWin++;
// 			}
// 		}
// 
// 		else if (2 == iInput)
// 		{
// 			if (0 == iAnswer % 2)
// 			{
// 				cout << " ��ǻ�� : ¦" << endl;
// 				cout << " ����� : ¦" << endl;
// 				cout << "�����Դϴ�" << endl;
// 				iWin++;
// 			}
// 
// 			else if (0 != iAnswer % 2)
// 			{
// 				cout << " ��ǻ�� : Ȧ" << endl;
// 				cout << " ����� : ¦" << endl;
// 				cout << "�����Դϴ�" << endl;
// 				iLose++;
// 			}
// 		}
// 
// 		else if (3 == iInput)
// 		{
// 			bSelect = false;
// 		}
// 
// 		else
// 		{
// 			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
// 			iRound++;
// 		}
// 
// 		system("pause");
// 	}
// 
// 	system("cls");
// 	cout << "�� : " << iWin << "\t�� : " << iLose << endl;
// 	system("pause");
// 
// 	return 0;
// }

#pragma endregion