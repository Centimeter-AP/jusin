#include <iostream>

using namespace std;

int main()
{
	// fwrite(������ �޸��� �ּ�, ������ �޸��� ũ��, ������ �޸��� ����, ������ ��Ʈ��)
	// size_t fwrite(void const* _Buffer,size_t _ElementSize, size_t _ElementCount, FILE * _Stream)

	// fread(�ҷ����� �� �޸��� �ּ�, �ҷ������� �޸��� ũ��, �ҷ����� �� �޸��� ����, ������ ��Ʈ��)
	// size_t fread(void const* _Buffer, size_t _ElementSize, size_t _ElementCount, FILE * _Stream)


	//FILE* pSaveFile = NULL;
	//
	//int	iArray[5] = { 1, 2, 3, 4, 5 };
	//
	//errno_t err = fopen_s(&pSaveFile, "../Data/Number.txt", "wb");
	//
	//if (0 == err)
	//{
	//	fwrite(iArray, sizeof(iArray), 1, pSaveFile);
	//	// fwrite(iArray, sizeof(int), 5, pSaveFile);
	//
	//	fclose(pSaveFile);
	//}
	//else
	//	cout << "���� ���� ����" << endl;


	FILE* pLoadFile = NULL;

	int	iTemp[5] = { };

	errno_t err = fopen_s(&pLoadFile, "../Data/Number.txt", "rb");

	if (0 == err)
	{
		fread(iTemp, sizeof(iTemp), 1, pLoadFile);
		// fread(iTemp, sizeof(int), 5, pLoadFile);

		fclose(pLoadFile);
	}
	else
		cout << "���� ���� ����" << endl;

	for (int i = 0; i < 5; ++i)
		cout << iTemp[i] << "\t";

	cout << endl;


	return 0;
}

// 1. �ؽ�ƮRPG�� �����ϱ�, �ҷ����� ����
// 
// - �ҷ�����, SelectJob���� ������ ��
// - �����ϱ�� ������ ���� ������ ������ ��

// 2. �̹��� ������ ���� ����� �Լ����� �̿��Ͽ� �����϶�