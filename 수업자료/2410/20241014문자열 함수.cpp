#include <iostream>

#include <string.h>		// c��� ����� ���ڿ� �Լ��� ����
#include <cstring>		// mfc ������Ʈ�� ���ڿ� Ŭ������ ����

#include <string>		// stl �����̳ʷ� c++ ��ݿ��� ��� ������ operator ����

using namespace std;

int main()
{
	// ���ڿ� ���� �Լ� : ���ڿ� ���� ������ �Ұ����ϱ� ������ ����Ʈ ������ �޸� ���縦 �̿��Ͽ� ���ڿ� ������ ����Ѵ�.

	// (���� ���� ���� �迭�� �ּ�, ���� ���� ���� �迭�� �޸� ũ��, ������ ���ڿ��� �ּ�)
	// errno_t strcpy_s(char* _Destination, rsize_t _SizeInBytes,char const* _Source)

	// char	szName[32] = "hello_world";
	// char	szTemp[32] = "after";

	// strcpy_s(szName, sizeof(szName), "helloworld");
	// strcpy_s(szName, sizeof(szName), szTemp);
	// cout << szName << endl;

	// ���ڿ� ���� �Լ� : �� ���ڿ��� �ϳ��� ���ڿ��� �����Ͽ� �������� ���ڿ��� ����� �Լ�

	// (������ ���� ����� ������ �迭�� �ּ�, ������ ����� ������ �迭�� �޸� ũ��, ������ ���ڿ��� �ּ�)
	// errno_t strcat_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source)

	// char	szName[32] = "Hello";
	// char	szTemp[32] = "_World";
	// 
	// strcat_s(szName, sizeof(szName), szTemp);
	// 
	// cout << szName << endl;
	// cout << szTemp << endl;

	// ���ڿ� ���� ���ϱ� �Լ� : null���ڸ� ������ ���ڿ��� ���̸� ���ϴ� ���

	// (���ڿ� ���̸� ���ϰ� ���� ���� �迭�� �ּ�)
	// size_t strlen(char* pName);

	// char	szName[32] = "hello_world";
	// cout << strlen(szName) << endl;

	// ���ڿ� �� �Լ� : �� ���ڿ��� ��ġ ���θ� �����ϴ� �Լ�
	// (���� ���ڿ� 1�� �ּ�, ���� ���ڿ� 2�� �ּ�)
	// int strcmp( char const* _Str1, char const* _Str2)

	// char	szName[32] = "hello";
	// 
	// if (!strcmp(szName, "hello"))
	// {
	// 	cout << "��ġ" << endl;
	// }
	// else
	// {
	// 	cout << "����ġ" << endl;
	// }

	// �����ڵ� ����� ���ڿ� ����� �Լ����� ����
	// 
	// wchar_t szName[32] = L"";
	// 
	// lstrcpy()
	// lstrcat
	// 
	// lstrcmp
	// lstrlen

	// string �����̳��� ��� ��
	
	// string		strName = "";	(�ƽ�Ű �ڵ� ���)
	// wstring		wstrName = L""; (���� �ڵ� ���)
	// 
	// strName = "���� ����";
	// cout << strName << endl;
	// 
	// strName += "_���յ� ����";
	// 
	// cout << strName << endl;
	// 
	// cout << strName.size() << endl;
	// cout << strName.length() << endl;
	// 
	// if (strName == "���� ����_���յ� ����")
	// 	cout << "��ġ" << endl;


	// char	szName[32] = "hello";
	// string	strTemp = "world";

	// strTemp = szName;
	// szName = strTemp;

	// c_str : ���� Ÿ���� ���� �ڷ����� ��ȯ
	// strcpy_s(szName, sizeof(szName), strTemp.c_str());

	// cout << szName << endl;
	//cout << strTemp << endl;

	return 0;
}