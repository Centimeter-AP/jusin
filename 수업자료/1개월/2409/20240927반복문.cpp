#include <iostream>
#include <ctime>

using namespace std;

// �ڷ����� ������ ����
// typedef int			BOOL;

// ��� c++ ������ ����
// using BOOL = int;

int main()
{
	// �ݺ��� : �ߺ��Ǵ� �ڵ尡 �뷮�� ��� ȿ�������� �ذ��ϱ� ���� ������ ����
	// ���� : �� ���� ���α׷� ���� �帧
	// while, do while, for

#pragma region while

	//int		iNumber(3);

	// while (iNumber--)
	// {
	// 	 cout << "hello world" << endl;
	// }

	// while (true)
	// {
	// 		cout << "hello world" << endl;
	// 		
	//		iNumber--;
	// 
	// 		if (0 == iNumber)
	// 		{
	// 			break;
	// 		}
	// }

	/*2 * 1 = 2
	2 * 2 = 4
	2 * 3 = 6
	2 * 4 = 8
	2 * 5 = 10
	2 * 6 = 12*/

	// int	 i(1);
	// 
	// while (10 > i)
	// {
	// 	cout << 2 << " * " << i << " = " << i * 2 << endl;
	// 	i++;
	// }

#pragma endregion

#pragma region do while

	// int	iInput(0), iSum(0);
	// 
	// do
	// {
	// 	cin >> iInput;
	// 
	// 	if (0 != iInput % 2)
	// 		continue;			// �ݺ��� �ȿ����� ��� ����, �ڵ��� �帧�� �ݺ����� �� ������ �̵�
	// 
	// 	iSum += iInput;
	// 
	// 	/*if (0 == iInput % 2)
	// 	{
	// 		iSum += iInput;
	// 	}*/		
	// 
	// } while (-1 != iInput);
	// 
	// cout << iSum << endl;

#pragma endregion

#pragma region random

	// ���� : �������� ���ڸ� �ǹ�

	// rand() �Լ� : 0 ~ 32767 ���� ���� �� �� �ϳ��� �������� ���� 
	// seed ����ǥ�κ��� ���� �����ͼ� ���ڸ� �߻�

	// srand() �Լ� : ����ǥ(���� ���̺�)�� �ٲ��ִ� �Լ�

	// time() �Լ� : ���� �ð��� �� ������ ��ȯ�Ͽ� �ҷ����� �Լ�

	// time_t Test = 0;
	// 
	// time(&Test);
	// 
	// cout << Test << endl;
	// 
	// srand(Test);

	//srand(unsigned(time(NULL)));
	//
	//int		iDst = rand();
	//int		iSrc = rand();
	//int		iTmp = rand();
	//
	//cout << iDst << endl;
	//cout << iSrc << endl;
	//cout << iTmp << endl;

	// int iInput(0);
	// 
	// while (true)
	// {
	// 	system("cls");
	// 
	// 	cout << "���ڸ� �Է��ϼ��� : ";
	// 	cin >> iInput;
	// 
	// 	cout << iInput << endl;
	// 	system("pause");
	// }

#pragma endregion

	return 0;
}

// 1. ������ 2~9�ܱ��� while���� �̿��Ͽ� ����ϱ�

// 2. ���Ǳ� ���� �����ϱ�

// - �������� �Է¹ް�, ���� �������� �ܾ� ���¸� ȭ�鿡 ���
// - �޴� : 1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ
// - �ش� ��� ����, ���� ��, �����ܾ��� �ٲ��, 'xx���� �Ϸ�'��� ���
// - ��, �ܾ��� ������ ���, '�ܾ��� �����մϴ�'��� ���
// - 4���� ���� ���, '�Ž��� ���� xx�� �Դϴ�' ��� ��, ���� ����

// 3. Ȧ¦ ����
// - ������ �̿��ؼ� ���ڸ� �� ȸ������ �߻���Ŵ
// - ������ �̿��Ͽ� Ȧ�� ¦�� ���߸� ��
// - �� 5ȸ �ǽ��Ͽ� ������ ���尡 ����ǰ� �� ��, �� �� ���

// ex)
// rand = 3
// 1. Ȧ 2. ¦ 3. ����
// 1
// ����
// rand = 6
// 1. Ȧ 2. ¦ 3. ����
// 1
// ����
// 
// 3�� 2��

