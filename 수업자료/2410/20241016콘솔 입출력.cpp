#include <iostream>

using namespace std;

int main()
{
	// �ܼ� �����

	// �ؽ�Ʈ ��� : ���ڿ��� ���·� ����ڰ� �˾� �� �� �ִ� ���
	// ���̳ʸ� ��� : 2���� ���·� ����ڰ� �˾ƺ��� ����� ������ ���

	// ���ڿ� ����� �Լ�

	// ǥ�� �ܼ� ����� ��Ʈ���� ����

	// - stdin  : ǥ�� �Է� ��Ʈ��(�⺻ Ű���� ���)
	// - stdout : ǥ�� ��� ��Ʈ��(�⺻ ����� ���)
	// - stderr : ǥ�� ���� ��Ʈ��(�⺻ ����� ���)

	/////////////////////////////////////////////////////
	// 1. ���� ���� ��� �Լ� : �ƽ�Ű �ڵ� �� ���ڸ� ����ϴ� �Լ�

	// putchar(65);				// �ܼ� ��¿��� ��� ����(stdout���� ����)
	// putchar('S');

	// fputc('A', stdout);		// �Ű� ������ ��Ʈ�� ������ ����, ���������� ���� ����¿��� ���

	// 2. ���� ���� �Է� �Լ� : �ƽ�Ű �ڵ� �� ���ڸ� �Է� �޴� �Լ�

	// char	cName = getchar();	// �ܼ� �Է¿��� ��� ����(stdin���� ����)
	// putchar(cName);

	// char cTemp = fgetc(stdin);
	// fputc(cTemp, stdout);

	// EOF(end of file) : ������ ���� ���������� �˷��ִ� -1�� �ش��ϴ� �Լ�

	// while (true)
	// {
	// 	char	ch = getchar();
	// 
	// 	if (EOF == ch)			// ctrl + z�� ���� ��� �ܼ� ����� ��, EOF�� �߻�
	// 		break;
	// 
	// 	if ('a' <= ch && 'z' >= ch)
	// 		ch -= 32;
	// 
	// 	else if ('A' <= ch && 'Z' >= ch)
	// 		ch += 32;
	// 
	// 	putchar(ch);
	// }

	// 3. ���ڿ� ��� �Լ� : ���ڿ��� ����ϴ� �Լ�

	// puts("hello");			// �ܼ� ��¿��� ��� ����(�ڵ� ���� ����)
	// fputs("world", stdout); // ���������� ��� ����(�ڵ� ���� �������� ����)
	
	// \r : carriage return : ���� �� ������ ���� ��ɾ�

	// 4. ���ڿ� �Է� �Լ� : ���ڿ��� �Է��ϴ� �Լ�

	// char	szName[10] = "";

	// gets_s(szName);		// ����(space)�� ������� ����, enter�� ���ڿ��� ���� �� ����
	// puts(szName);

	// fgets(szName, sizeof(szName), stdin); // enter�� �о� �鿩 ������ �����ŭ�� �о���� �� ����
	// fputs(szName, stdout);

	// cin >> szName;
	// cout << szName << endl;

	// 5. ��� ���� ���� �Լ� : fflush
	
	// - �Է� ���۴� ������ ���Ⱑ �Ұ���
	// - ��� ���۸� ���� �۾� ���� ���� ���� �ʴ´�.

	// char	szID[9] = "";
	// char	szName[16] = "";
	// 
	// fgets(szID, sizeof(szID), stdin);
	// 
	// while ('\n' != getchar());
	// 
	// fgets(szName, sizeof(szName), stdin);
	// 
	// fputs(szID, stdout);
	// fputs(szName, stdout);
	

	return 0;
}