#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// �޸� �Լ� : c��� �������� �޸� ������ ������ �����ϴ� �Լ��� ����

	// �޸� �ʱ�ȭ �Լ� : Ư�� �޸𸮸� ����Ʈ ������ �ʱ�ȭ�ϴ� �Լ�

	// memset(�ʱ�ȭ �� �޸� ������ �ּ�, ����Ʈ ������ �ʱ�ȭ �� ��, �ʱ�ȭ �� �޸� ������ ũ��)
	// void* memset( void* _Dst, int _Val, size_t _Size);

	// int		iArray[5] = { 1, 2, 3 ,4 ,5 };
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iArray[i] << endl;
	// 
	// memset(iArray, 0, sizeof(iArray));
	// // ZeroMemory(iArray, sizeof(iArray);
	// 
	// cout << "-----------------------------" << endl;
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iArray[i] << endl;

	// memcpy : �޸� ����Ʈ ������ ���� �����ϴ� �Լ�
	
	// memcpy(���� ���� ������ ù ��° �ּ�, ������ ����� ù ��° �ּ�, ���� ���� �޸� ������ ũ��)
	// void* memcpy(void* _Dst, void const* _Src, size_t  _Size)

	// int		iArray[5] = { 1, 2, 3, 4, 5 };
	// int		iTemp[5] = {};
	
	// memcpy(iTemp, iArray, sizeof(iTemp));

	// memmove(iTemp, iArray, sizeof(iTemp));
	// 
	// for (int i = 0; i < 5; ++i)
	// 	cout << iTemp[i] << endl;


	return 0;

}