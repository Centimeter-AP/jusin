#include <iostream>

using namespace std;

int main()
{
	// �ּ� : �����Ϸ��� �ڵ�� �ν����� �ʵ��� ����� ���α׷��� ����
	// ���� �ּ� : �� �ٸ� �ּ� ó��
	// /* */ ���� �ּ� : ���� ���� �ּ� ó��

#pragma region ������ ��� ����

	// ������ ���

	// ��� : �޸� ������ ���� �����ϵ� �� ���� ���� �� �� ���� ������ �ڷ�
	// �б�� ���������� ���Ⱑ �Ұ����� ������

	// ���ͷ� ��� : �̹� �Ծ� �Ǵ� �Թ��� ���ؼ� ���� ���� �Ǿ��ִ� ���
	// �ɺ��� ��� : ���α׷��� ������ ���� ����� �����Ǵ� ��(const)

#pragma endregion 

	// ���α׷��� ���� ����

	// ������ �ּ� ���� : bit
	// ������ �ּ� ���� : byte		

	// ���� : ���α׷��� �ڵ� �帧�� ���� ���� ���°� ���ϴ� �ڷ�
	
	// int		iNumber;	  // ������ '����'�ϴ�
	// int		iNumber = 10; // ������ '����� ���ÿ� �ʱ�ȭ' �ϴ�(c ��� �ʱ�ȭ)
	// int		iNumber(10);  // ������ '����� ���ÿ� �ʱ�ȭ' �ϴ�(c++ �ʱ�ȭ)
	// 
	// cout << iNumber << endl;
	// 
	// iNumber = 20;
	// 
	// cout << iNumber << endl;

	// ���� Ÿ�� �ڷ���
	// short(2), int(4), long(4), long long(8)
	// __int16, __int32, __int64

	// unsigned short		sTemp = 0;		// -32768 ~ 32767
	// 										// 0 ~ 65535
	// sTemp = 32767;
	// sTemp = 32770;
	// sTemp = 65535;
	// 
	// cout << sTemp << endl;

	// �Ǽ� Ÿ�� �ڷ���
	// float(4), double(8), long double(8)

	// float		fTime = 0.f;
	// cout << fTime << endl;

	// ���� Ÿ�� �ڷ���
	// char(1), wchar_t(2), string(stl �����̳�) / wstring

	// �ƽ�Ű(ASCII)�ڵ�

	// SBCS -> MBCS -> WBCS

	// "ABCD"	-> 5BYTE 
	// "��������"-> 9BYTE

	// char	sName = 65;		// �ƽ�Ű �ڵ� ���� �ϳ��� ���� ����
	// 
	// sName = 98;
	// sName = 'q';			// ����
	// 
	// // sName = "hello";		// ���ڿ�
	// 
	// cout << sName << endl;

	// �� �ڷ��� : �� �Ǵ� ������ ǥ���ϱ� ���� ������ ��
	// bool(1)

	// bool	bSelect = -1;

	// bool	bSelect = true;
	// bSelect = false;
	// cout << bSelect << endl;

	// int		iInput(0);
	// 
	// cout << "���ڸ� �Է��ϼ��� : ";
	// cin >> iInput;
	// cout << endl;
	// 
	// cout << "���� : " << iInput << endl;

	// ����, ����, ���� ������ �Է� �ް�, ������ ����� ���ؼ� ��� ����ض�
	// ���� ���� ���� ���� ���
	// ?	?	?	 ?	  ?	

	return 0;
}