#include <iostream>

using namespace std;

int main()
{
	// �б⹮ : ������ �Ͱ� �׷��� ���� ���� �����ϱ� ���� ����
	// if, switch, goto

#pragma region goto

// goto Home;
// 
// 	cout << 1 << endl;
// 
// Home :
// 
// 	cout << 2 << endl;

#pragma endregion

#pragma region if

	// if�� : �б⹮, ���ǹ��̶�� �Ҹ���. 

	// if ( ���ǽ�)
	// {
	// 	// �ڵ� ��
	// }


	// int		iDst(10), iSrc(20);
	// 
	// if (iDst > 5)
	// {
	// 	cout << 'A' << endl;
	// }
	// 
	// // if�� else ���̿��� �ٸ� �ڵ尡 ��ġ �� �� ����.
	// // else if�� else �ռ��� if���� �־�� ����� �����ϴ�.
	// 
	// else if (iDst > 5)
	// {
	// 	cout << 'B' << endl;
	// }
	// 
	// else	// if�� ������ ���̸� else�� �ڵ������� ����
	// {
	// 	cout << 'C' << endl;
	// }

	// ���� �ڵ� : �ڵ� �� �ȿ� �ڵ尡 �� ���� ���, �߰�ȣ�� �����Ͽ� ǥ�Ⱑ ����
	// if (1)
	// {
	// 		cout << "hello world" << endl;
	// }
	
	// if (1)
	// {
	// 		int		iTemp = 100;		// ���� ���� : �߰�ȣ �ȿ����� ��ȿ���� ���� ����
	// }
	// 
	// else
	// {
	// 		cout << iTemp << endl;
	// }

	////////////////////////////////////////

	// int			iA(20), iB(5);
	// 
	// if ((iA < iB) && (iA = 999))
	// 	cout << iA << endl;

	//if (10 > 3)
	//{
	//	if (20 > 5)
	//	{

	//	}
	//}
#pragma endregion

#pragma region switch

// switch : ��� ���� �б⹮, ���, ������ ����ϸ� �Ǽ� ������ �бⰡ �Ұ���

// switch (���ǿ� �ش��ϴ� �����(���� Ÿ��))
// {
// case 1:
// case 2:
// case 3:
// }

	int		iInput(0);

	const int		iNumber(1);	// �ɺ��� ���

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iInput;

	switch (iInput)
	{
	case iNumber:
		cout << "�ݶ�" << endl;
		break;		// ���� �ڵ��� �帧�� ���߰� �߰�ȣ�� ������� ����� Ű����

	case 2:
		cout << "���̴�" << endl;
		break;

	case 3:
		cout << "ȯŸ" << endl;
		break;

	default:
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		break;
	}




#pragma endregion

	return 0;
}

// ��� ���� �������� ���� ����� �ű���

// 90�� �̻� 100�� ���� A����
// 80�� �̻� 90�� �̸� B����
// 70�� �̻� 80�� �̸� C����
// 60�� �̻� 70�� �̸� D����
// ������ F����