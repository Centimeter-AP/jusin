#include <iostream>

using namespace std;



const char* Func()
{
	// char	szName[32] = "";
	// cin >> szName;
	// return szName;

	char*	pHeapName = (char*)calloc(32, sizeof(char));

	cin >> pHeapName;

	return pHeapName;
}

int main()
{

	 //char* pName = Func();
	 //cout << pName << endl;
	 //
	 //free(pName);
	 //pName = NULL;


	// ���� �Ҵ� : ���� �޸� �� heap ������ ����ϸ�, �� Ÿ�ӿ� �޸𸮸� �Ҵ��ϰ� �����ϴ� ������ ���´´�.

	// 1. ������ ���� heap ������ ���� �� �� ����.
	// 2. �޸� ��ȯ�� �ݵ�� ����߸� �޸� ������ �߻����� �ʴ´�. 
	// 3. ���α׷� ���� ���� ���� �Ҵ��ϰ� ���� ��ȯ�� �� ���α׷��Ӱ� �����ؾ� �Ѵ�.
	// 4. heap �������� ������ �̸��� ���� �� ����.

	/////////////////////////////////////////////////////////////////////////

#pragma region c��� �����Ҵ�

	// c��� �����Ҵ� ��� : �Լ��� ����� ���
	// 
	// void* malloc(size_t size)
	// void* calloc(size_t count, size_t size)

	// void	free(void* pointer);

	// void* (void ������) : � �ڷ����� �ּ����� �� �� ���� �� ��ü�Ͽ� ����ϴ� ������,
	// �ּҸ� �̿��Ͽ� ���� �޸� ������ �����ϰ��� �� ��(�����͸� ����ϰ��� �� ��)�� �ݵ�� ������� �� ��ȯ�� ����� �Ѵ�.

	// ���� �迭 : �� Ÿ�� �ÿ� �Ҵ��ϴ� �迭

	// int* p = NULL;
	// 
	// p = (int*)malloc(sizeof(int));
	// 
	// *p = 10;
	// 	
	// cout << p << endl;
	// cout << *p << endl;
	// 
	// free(p);	// ����ߴ� heap �޸� ��ȯ
	// p = NULL;	// ��۸� �����Ͱ� �߻����� �ʵ��� �ݵ�� �����͸� null�� ä����� �Ѵ�.
	// 
	// cout << "------------------------" << endl;
	// 
	// cout << p << endl;		// ��۸� ������ 
	// 
	// *p = 20;
	// 
	// cout << *p << endl;


	//p = (int*)malloc(sizeof(int) * 4);
	//p = (int*)calloc(4, 4);		// �Ҵ��� heap ������ �ڵ� 0 �ʱ�ȭ ����

	// cout << p << endl;
	// 
	// p[0] = 10;
	// p[1] = 20;
	// p[2] = 30;
	// p[3] = 40;

	// for (int i = 0; i < 4; ++i)
	// 	cout << p[i] << endl;

	// *p = 10;
	// cout << *p << endl;

#pragma endregion

#pragma region c++ �����Ҵ�

	 // int* p = new int(100);
	 // 
	 // cout << p << endl;
	 // cout << *p << endl;
	 // 
	 // cout << "-------------------" << endl;
	 // 
	 // *p = 10;
	 // 
	 // cout << *p << endl;
	 // 
	 // delete p;
	 // p = nullptr;

	// int		iInput(0);
	// cin >> iInput;
	// 
	// int* p = new int[iInput]{10, 20, 30};
	// 
	// for (int i = 0; i < iInput; ++i)
	// 	cout << p[i] << endl;
	// 
	// delete[] p;		// ���� �迭�� �޸� ��ȯ�ϴ� ����
	// p = nullptr;

#pragma endregion

	return 0;
}