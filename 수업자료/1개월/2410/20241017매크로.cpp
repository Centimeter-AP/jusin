#include <iostream>

using namespace std;

// ��� ��ũ�� : �ܼ� ġȯ�̶� �������� �ӵ��� ������ ��������, �׷��� ������ Ÿ�ӿ� ��ũ���� ������ �ľ� �� �� ����.

#define		PI			3.14f
#define		MIN_STR		32
#define		MAX_STR		256

// �Լ� ��ũ�� : �Լ��� ����� �� ��ũ��, �ܼ��� �ڵ� ������ ��ũ��ȭ ��Ŵ
// 
// ����ϰ��� �ϴ� �ڷ����� ������ ����
// ������ �켱 ������ ������� �ʰ� �ܼ� ġȯ�� ����
// �� �� ������ �� ��¥�� ���� �ڵ�� ��ũ�η� ���� ���� ����

#define		SQUARE(X)		((X) \
* (X))	

// �Լ� ��ũ���� �پ��� ����

// Ư�� �׸��� ���ڿ��� ġȯ��Űū ����
#define		STRING(A, B)	#A "�� ������ "   #B "�Դϴ�"

// ��ũ�� ������ ����
#define		COMBINE(A, B)		A##B

// �Լ� ��ũ�� ��� ��

#define		SAFE_DELETE(p)		if(p) {	delete p; 	p = nullptr; }


int main()
{
	// cout << PI << endl;
	// 
	// int* p = NULL;
	// 
	// char	szMin[MIN_STR] = "";
	// char	szMax[MAX_STR] = "";

	// cout << SQUARE(10) << endl;
	// cout << SQUARE(20l) << endl;
	// cout << SQUARE(1.1f) << endl;
	// cout << SQUARE(1.245) << endl;

	//cout << SQUARE(2 + 2) << endl;
	// cout << 2 + 2 * 2 + 2 << endl;

	//cout << STRING(ȫ�浿, ����) << endl;
	// cout << COMBINE(10, 20) << endl;

	int* p = new int;

	SAFE_DELETE(p);

	return 0;
}