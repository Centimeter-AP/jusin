#include <iostream>

using namespace std;

#pragma region 2���� �迭�� �̸��� �����ϴ� ������

//void	Render(int(*pArray)[3]);
//
//int main()
//{
//	int	iArray[2][3] = {
//
//		{ 1, 2, 3},
//		{ 4, 5, 6},
//	};
//
//	// 2���� �迭�� �̸��� �����ϴ� ������ ���� ���
//	// �ڷ��� (*������ �����̸�)[��]
//
//	// int(*pArray)[3] = iArray;
//	// cout << sizeof(pArray) << endl;
//	//cout << pArray[1][1] << endl;
//	
//	Render(iArray);
//
//	return 0;
//}
//
//void Render(int(*pArray)[3])
//{
//	cout << pArray[1][1] << endl;
//}

#pragma endregion

#pragma region �Լ� ������

void	Render();
void	Draw();

int		Add(int iDst, int iSrc);
int		Min(int iDst, int iSrc);
int		Mul(int iDst, int iSrc);
int		Div(int iDst, int iSrc);


int main()
{
	// �Լ� ������ : �Լ��� �̸�(�ּ�)�� �����Ͽ� �Լ��� ȣ���� ��� �����ϵ��� ����� ������
	// ��ȯ Ÿ�� (*������ ���� �̸�)(�Ű� ���� ����)

	// void (*pFunc)() = Render;
	// //cout << sizeof(pFunc) << endl;
	// 
	// pFunc();
	// pFunc = Draw;
	// pFunc();

	// int	(*pCalc)(int, int) = Add;
	// cout << pCalc(10, 20) << endl;

	// ��� ��///////////////////////////////////////

	int iDst(0), iSrc(0);
	int iInput(0), iResult(0);

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iDst >> iSrc;

	cout << "1. ���� 2. ���� 3. ���� 4. ������ : ";
	cin >> iInput;

	int(*pCalc[4])(int, int) = { Add, Min, Mul, Div };
	cout << "���� ��� : " << pCalc[iInput - 1](iDst, iSrc) << endl;

	//int (*pCalc)(int, int) = NULL;
	//
	//switch (iInput)
	//{
	//case 1:
	//	//iResult = Add(iDst, iSrc);
	//	pCalc = Add;
	//	break;
	//
	//case 2:
	//	//iResult = Min(iDst, iSrc);
	//	pCalc = Min;
	//	break;
	//
	//case 3:
	//	//iResult = Mul(iDst, iSrc);
	//	pCalc = Mul;
	//	break;
	//
	//case 4:
	//	//iResult = Div(iDst, iSrc);
	//	pCalc = Div;
	//	break;
	//}
	//
	////cout << "���� ��� : " << iResult << endl;
	//cout << "���� ��� : " << pCalc(iDst, iSrc) << endl;
	

	return 0;
}

void	Render()
{
	cout << "hello world" << endl;
}

void Draw()
{
	cout << "hello jusin" << endl;
}
int		Add(int iDst, int iSrc)
{
	return iDst + iSrc;
}

int Min(int iDst, int iSrc)
{
	return iDst - iSrc;
}

int Mul(int iDst, int iSrc)
{
	return iDst * iSrc;
}

int Div(int iDst, int iSrc)
{
	return iDst / iSrc;
}

#pragma endregion

// 1. 2���� �迭�� �̿��Ͽ� ������ ���·� ���� ����� �ؿͶ�
/*
* 
1	2	3				7	4	1				9	8	7				3	6	9				1	2	3
4	5	6	-90�� ȸ��>	8	5	2 - 90�� ȸ�� >	6	5	4 - 90�� ȸ�� >	2	5	8 - 90�� ȸ�� >	4	5	6
7	8	9				9	6	3				3	2	1				1	4	7				7	8	9

*/

// 2. ���� ���� �����

// - 5 * 5¥�� �迭�� �̿��� ���� 1~25 ����ϱ�
// - �Է��� ���ڿ� ��ġ�ϴ� ���� ���� �迭�� * �� ����Ѵ�.
// - * �� �̷��� ���� �ټ���, ���� �ټ���, �밢�� �ټ����� ���� ��� ���� �ϳ� ����
// - 5 ���� �̻��̸� �¸��� ������ ����
// - ������ ������ �� �������� ���

// 1  2	 3			1	*	3		*	*	*
// 4  5	 6	-2�Է�>	 4	 5   6	->	 4	 5	 6
// 7  8	 9			7	8	9		7	8	9

// 3. ���� �̵� ��Ű��

// - 5 * 5¥�� �迭�� �̿��� ���� 0 ~ 24 ����ϱ�
// - 2(�Ʒ���) 4(����) 6(������) 8(����)�� �޴��� ����ϰ� ������ ��ȣ�� ���� ���� 0�� �̵����� ����Ѵ�.
// - �� ���ٿ����� �̵����� ���ϵ��� ����ó�� �� ��

// 0	1	2			3	1	2			3	1	2
// 3	4	5	-2�Է�>  0	 4   5 -6�Է�>	  4	  0	  5
// 6	7	8			6	7	8			6	7	8


