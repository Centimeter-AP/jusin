#include <iostream>
#include <windows.h>

using namespace std;

#pragma region ����ü

// struct tagInfo
// {
// 	int		iDst;
// 	float	fSrc;
// };
// 
// union uniInfo
// {
// 	short	iDst;
// 	float	fSrc;
// 
// };
// 
// int main()
// {
// 	// ����ü : ��� �� ���� ū �ڷ����� �޸� ���� �Ҵ��ϰ� �� �޸� ���� �����Ͽ� ����ϴ� ����� ���� �ڷ���
// 
// 	uniInfo		tInfo = { 3.14f };
// 
// 	//cout << &tInfo << endl;
// 	//cout << &(tInfo.iDst) << endl;
// 	//cout << &(tInfo.fSrc) << endl;
// 
// 	cout << "======================" << endl;
// 	
// 	cout << (tInfo.fSrc) << endl;
// 	cout << (tInfo.iDst) << endl;
// 
// 	return 0;
// }

#pragma endregion

#pragma region ����ü

enum NUMBER
{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	END
};

//enum TEST
//{
//	ONE = 100,
//	TWO,
//	THREE,
//	FOUR,
//	FIVE,
//	END
//};


int main()
{
	// ����ü : ����� ��ȣ(����)�� ���·� ���� �� �����Ͽ� ����ϱ� ���� ����

	// NUMBER	eNumber(THREE);
	// 
	// cout << eNumber << endl;
	// cout << NUMBER::FIVE << endl;
	// cout << sizeof(NUMBER) << endl;
	// 
	// int		iResult = ONE + FIVE;
	// cout << iResult << endl;

	// . �����ڴ� ����ü������ �������� ����
	//cout << eNumber.ONE << endl;

	return 0;
}

#pragma endregion