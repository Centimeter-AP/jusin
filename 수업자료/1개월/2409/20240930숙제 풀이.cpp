#include <iostream>
#include <ctime>

using namespace std;

#pragma region 구구단

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

#pragma endregion 구구단

#pragma region 자판기 게임

//int main()
//{
//	int		iMoney(0), iInput(0), iCoke(100), iCider(200), iFanta(300);
//	bool	bSelect(true);
//
//	cout << "돈을 넣어주세요 : ";
//	cin >> iMoney;
//
//	while (bSelect)
//	{
//		system("cls");
//
//		cout << "잔액 : " << iMoney << endl;
//		cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
//		cin >> iInput;
//
//		if (1 == iInput)
//		{
//			if (iMoney >= iCoke)
//			{
//				cout << "콜라 구매 완료" << endl;
//				iMoney -= iCoke;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//
//		else if (2 == iInput)
//		{
//			if (iMoney >= iCider)
//			{
//				cout << "사이다 구매 완료" << endl;
//				iMoney -= iCider;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//
//		else if (3 == iInput)
//		{
//			if (iMoney >= iFanta)
//			{
//				cout << "환타 구매 완료" << endl;
//				iMoney -= iFanta;
//			}
//			else
//			{
//				cout << "잔액이 부족합니다" << endl;
//			}
//		}
//		else if (4 == iInput)
//		{
//			cout << "거스름 돈은 " << iMoney << " 원 입니다" << endl;
//			bSelect = false;
//		}
//		else
//		{
//			cout << "잘못 누르셨습니다" << endl;
//		}
//
//		system("pause");
//	}
//
//	return 0;
//}

#pragma endregion

#pragma region 홀짝

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
// 		cout << "정답 : " << iAnswer << endl;
// 		cout << iRound << "회 남았습니다" << endl;
// 		cout << "1. 홀 2. 짝 3. 종료" << endl;
// 		cin >> iInput;
// 
// 		iRound--;
// 
// 		if (1 == iInput)
// 		{
// 			if (0 == iAnswer % 2)
// 			{
// 				cout << " 컴퓨터 : 짝" << endl;
// 				cout << " 사용자 : 홀" << endl;
// 				cout << "오답입니다" << endl;
// 				iLose++;
// 			}
// 
// 			else if (0 != iAnswer % 2)
// 			{
// 				cout << " 컴퓨터 : 홀" << endl;
// 				cout << " 사용자 : 홀" << endl;
// 				cout << "정답입니다" << endl;
// 				iWin++;
// 			}
// 		}
// 
// 		else if (2 == iInput)
// 		{
// 			if (0 == iAnswer % 2)
// 			{
// 				cout << " 컴퓨터 : 짝" << endl;
// 				cout << " 사용자 : 짝" << endl;
// 				cout << "정답입니다" << endl;
// 				iWin++;
// 			}
// 
// 			else if (0 != iAnswer % 2)
// 			{
// 				cout << " 컴퓨터 : 홀" << endl;
// 				cout << " 사용자 : 짝" << endl;
// 				cout << "오답입니다" << endl;
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
// 			cout << "잘못 입력하셨습니다" << endl;
// 			iRound++;
// 		}
// 
// 		system("pause");
// 	}
// 
// 	system("cls");
// 	cout << "승 : " << iWin << "\t패 : " << iLose << endl;
// 	system("pause");
// 
// 	return 0;
// }

#pragma endregion