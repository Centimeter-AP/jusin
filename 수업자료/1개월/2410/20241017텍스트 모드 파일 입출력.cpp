#include <iostream>

using namespace std;

int main()
{
	// c��� ���� ���� �Լ�

	// fopen_s(������ ��Ʈ���� ������ �������� �ּ�, ���� �̸��� ������ ������ ���, ���)
	// errno_t fopen_s(FILE **_Stream, char const* _FileName, char const* _Mode)

	// c��� ���� �Ҹ� �Լ�
	// int fclose(FILE* _Stream)

// ���� ���(����)

	// FILE* pFile = NULL;		// ���� ��Ʈ��
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");
	// 
	// if (0 == err)		// ���� ���� ����
	// {
	// 	// fputs("hello", stdout);	// �ܼ� ���
	// 	fputs("hello", pFile);		// ���� ���
	// 
	// 	cout << "���� ����" << endl;
	// 
	// 	fclose(pFile);
	// }
	// 
	// else
	// {
	// 	cout << "���� ���� ����" << endl;
	// }

// ���� �Է�(�ҷ�����)

	// FILE* pReadFile = NULL;		// ���� ��Ʈ��
	// 
	// errno_t err = fopen_s(&pReadFile, "../Data/Test.txt", "rt");
	// 
	// char	szName[32] = "";
	// 
	// if (0 == err)		// ���� ���� ����
	// {
	// 	// fgets(szName, sizeof(szName), stdin); // �ܼ� �Է�
	// 	fgets(szName, sizeof(szName), pReadFile);
	// 
	// 	cout << "�ҷ����� ����" << endl;
	// 
	// 	fputs(szName, stdout);	// �ܼ� ���
	// 
	// 	fclose(pReadFile);
	// }
	// 
	// else
	// {
	// 	cout << "���� ���� ����" << endl;
	// }

// ���� �Լ� : ���� ����� ��, �����Ǵ� c��� ������ �Լ�

	// fseek : ������ Ŀ���� ���ϴ� ��ġ�� �̵���Ű�� �Լ�
	
	// _Offset : �̵��� ����Ʈ ��
	// _Origin : Ŀ���� ���� ����
	// int fseek(FILE * _Stream, long  _Offset, int   _Origin);
	
	// ftell : Ŀ���� ��ġ�� �˷��ִ� �Լ�

	// FILE* pFile = NULL;
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");
	// 
	// if (0 == err)
	// {
	// 	fseek(pFile, 3, SEEK_SET);
	// 
	// 	char cTest = fgetc(pFile);
	// 
	// 	cout << "���� Ŀ���� ��ġ : " << ftell(pFile) << endl;
	// 	cout << "���� ���� : " << cTest;
	// 
	// 	fclose(pFile);
	// }

	// feof : ���� Ŀ���� eof�� �����ߴ��� �˷��ִ� �Լ�, EOF�� �����ߴٸ� 0�� �ƴ� ���� ����

	// FILE* pFile = NULL;
	// 
	// errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");
	// 
	// if (0 == err)
	// {
	// 	while (0 == feof(pFile))
	// 	{
	// 		fputc(fgetc(pFile), stdout);
	// 	}
	// 
	// 	fclose(pFile);
	// }

	return 0;
}