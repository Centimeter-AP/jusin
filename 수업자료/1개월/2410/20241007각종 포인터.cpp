#include <iostream>

using namespace std;

int main()
{
#pragma region ������ ����

	// ������ ���� : �����Ͱ� ���� �����ϴ� �ּ� �������� �����ڿ� ���� �ٸ� ������ ����Ű���� �ϴ� ����
	// �����ϴ� �ڷ����� ũ�⸸ŭ �޸� �̵��� �Ѵ�

	// int		iDst(0);
	// 
	// int*	p = &iDst;
	// 
	// cout << p << endl;
	// cout << *p << endl;
	// 
	// p++;		// ������ ������ ��
	// //p += 2;
	// 
	// cout << p << endl;		// ��۸� ������ : ������ ������ ���� �ּҸ� �����ϰ� �ִ� ������
	// cout << *p << endl;
	// 
	// *p = 100;		// �߸��� ���� �ӿ��� �ұ��ϰ� �۵��� �켱 ����Ǿ���
	// cout << *p << endl;

#pragma endregion
	
#pragma region ������ ����
	
	// int	iNumber(10);

	// �ּ� ���� �� ��ȯ�� ������
	// float* pNumber = (float*)&iNumber;

	// const int* p = &iNumber;				// �б� ���� ������ : ���� ����� �� ������ �Ұ���
	
	// int* const  p = &iNumber;			// ��� ������ : ������ �ϳ��� ��� ���� ������ ������
	// const int* const  p = &iNumber;		// �б� ���� ��� ������

	// *p = 20;		// �б� ���� ������ : �� ���� �Ұ�������
	// 				// ��� ������ : �� ���� ��������
	// 
	// int	iDst(500);
	// p = &iDst;		// �б� ���� ������ : �ּҰ� ������ ����
	// 					// ��� ������ : �ּҰ� ������ �Ұ���
	// 
	// *p = 600;		// �б� ���� ������ : �� ���� �Ұ�������
	// 				// ��� ������ : �� ���� ��������
	// 
	// cout << iNumber << endl;
	// cout << iDst << endl;

#pragma endregion

#pragma region 2���� ������

	// int		iNumber(0);
	// 
	// int*	p = &iNumber;
	//  
	// int**	pp = &p;
	// 
	// cout << p << endl;
	// cout << pp << endl;
	// 
	// cout << *p << endl;	 // 10
	// cout << *pp << endl;

#pragma endregion

	return 0;
}
