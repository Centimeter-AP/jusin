#include "pch.h"

// mutable Ű���� : const�� �б������� ��Ȳ�� �����ϰ� �� �� �ְ� ��

// try-catch ����ó��

int main()
{
	try
	{
		if (/*���ǹ�*/)
			throw /*���ܻ����̳� ����*/;
	}
	catch (const std::exception&/*�̿��� ���� �Է� ����, ���� �ڷ��������ε� ����*/)
	{
		/*���� throw �߰� �� ���� ����*/
	}
	catch (/*catch���� else ifó�� ������ ����*/)
	{
		/*��¼����¼��.*/
	}
}