#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// int		iData(10);
	// 
	// cout << bitset<8>(iData) << endl;
	// cout << bitset<8>(~iData) << endl;
	// cout << (~iData) << endl;

// 	iData - iData
// 
// 	iData + (~iData) + 1 == 0
// 
// 
//		00001010
// 		11110101
// --------------
// 		11111111
// +		   1
// --------------
//    100000000	 

////////////////////////////////////////////

	// ����Ʈ ������(����Ʈ ������) : ������ŭ ��� ��Ʈ�� �̵���Ű�� ������
	// <<(���� ����Ʈ ������), >>(������ ����Ʈ ������)

	// char	iNumber(10);
	// 
	// cout << bitset<8>(iNumber) << endl;
	// cout << (iNumber >> 1) << endl;
	// 
	// cout << bitset<8>(iNumber >> 2) << endl;
	// cout << (iNumber >> 2) << endl;		// iNumber / (2^2)
	// 
	// cout << bitset<8>(iNumber << 2) << endl;
	// cout << (iNumber << 2) << endl;		// iNumber * (2^2)

	// ���� ������ : � ���� �ϳ� ������Ű�ų� �Ǵ� �ϳ� ���ҽ�Ű�� ����
	// ++, --

	// int		iTmp(100);

	// ++iTmp;	 // ���� ���� : �� ���� �� ����
	// iTmp++;	 // ���� ���� : �� ���� �� ����

	// ++(++iTmp);
	// cout << (iTmp) << endl;

	// ��� ������(������ �����) : ���� �ڱ� �ڽ��� ���� ���� �Ǵ� ���ҽ�ų ��� �������� ǥ�� ���¸� �ٿ��� ���� ���
	// +=, -=, *=, /=, %=, <<=, >>=
	
	// int	iTest(5);
	// // iTest = iTest + 10;
	// iTest += 10;
	// cout << iTest << endl;

	return 0;
}