#include "pch.h"

int main()
{
	vector<int> vecInt;
	
	vecInt.push_back(10);	// �ڿ������� �ϳ��� �ֱ�

	vecInt.size();	// �迭�� ������ ��ȯ, size_t(unsigned long long)���

	vecInt.pop_back();		// �ڿ������� �ϳ��� ����

	vecInt.capacity();		// �迭�� ��ü ũ��(�Ҵ�� �ִ� ũ��)��ȯ

	vecInt.clear();			// ������ ���� (���Ҵ� ������ �Ҵ�� ������ �����)
	vecInt.empty();			// ���ư�?Y:N


	vector<int> vecTemp;

	vecInt.swap(vecTemp);	// ���� ��ȯ�� (�޸� ũ�⵵ ��ȯ��)

	vector<int>().swap(vecTemp); // �ӽð�ü�� ��ȯ���� �޸𸮿� ī�Ľ�Ƽ �� �� 0���� �ʱ�ȭ��
	vecTemp.shrink_to_fit();	// C++11���� �����Ǵ� �޸𸮰��� 0 �ʱ�ȭ �Լ�


	vecInt.front();		// �� �� ����
	vecInt.back();		// �� �� ����

}