#include <iostream>

using namespace std;

void Render(void);		// �Լ� �����(�̷� �Լ��� ������ �����Ϸ����� �˷��ִ� ����)

void Print(int _iData);

int	 Get_Number(void);	// ��ȯ Ÿ���� �ִ� ������ �Լ����� �ݵ�� return Ű���尡 ���ԵǾ�� �Ѵ�.

int	Add(int _iDst, int _iSrc);

// return 
// 
// 1. �Լ��� ���������� �����Ŵ
// 2. ���� ���� �ü���� ��ȯ

int main()
{
	// �Լ� : �ڵ��� ���뼺�� ���� ����� ����ϴ� ��� ����

	// �Լ��� ���� ���
	// 
	// 1. ��ȯ Ÿ�� : �Լ� ���� ��, �ش� �ڷ������� ���� ��ȯ�ؾ� ���� �˸��� ����
	// 2. �Լ� �̸� : �Լ� �ڵ带 ȣ���ϱ� ���� ������ Ű
	// 3. �Ű�����(�Ķ����, ���ڰ�)


	// for(int i = 0; i < 5; ++i)
	// 	Render();

	// Render();	// �Լ� ȣ��
	
	// int		iSrc(100);
	// 
	// Print(iSrc);			// call by value : �� ���翡 ���� ȣ��
	// 
	// cout << iSrc << endl;

	// cout << Get_Number() << endl;
	
	// Print(Get_Number());
	// cout << Add(10, 20) << endl;


	return 0;
}

// �Լ� ���Ǻ�
void		Render(void)
{
	cout << "hello world" << endl;
}

void Print(int _iData)
{
	_iData += 10;

	cout << _iData << endl;
}

int	 Get_Number(void)
{
	//return 200;

	int		iTest(200);		// ���� ����

	return iTest;
}

int	Add(int _iDst, int _iSrc)
{
	return _iDst + _iSrc;
}

// 1. ���Ǳ� ���� �ڵ带 �Լ��� �̿��Ͽ� �籸���϶�
// - �Լ��� �ϳ��� ��ɸ� ����Ѵ�


// 1. ������ ���� : ������
// 2. ������ ���� : �����Ҵ�
// 3. ������ ���� : �������̵�