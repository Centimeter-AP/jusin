#include <iostream>

using namespace std;

#pragma region �Լ� �����ε�

// �Լ� �����ε� : �Լ��� �̸��� ���� ���, �Ű� ������ ��Ȳ�� ���� � �Լ��� ȣ�� �� �� ������ Ÿ�ӿ� �����Ǵ� ����

// 1. �Ű� ������ ������ ���� �Լ��� ȣ���� ����
// 2. �Ű� ������ �ڷ����� ���� �Լ��� ȣ���� ����
// 3. �Լ� ��ȯŸ���� �ٸ��ٰ� �ؼ� �����ε��� ���������� ����

// void	Render();
// 
// void	Render(int _iData);
// // int		Render(int _iData);
// 
// void	Render(float _fData);
// void	Render(int _iData, int _iSrc);
// 
// int main()
// {
// 	Render(100);
// 
// 	return 0;
// }
// 
// void Render()
// {
// 	cout << "hello world" << endl;
// }
// 
// void Render(int _iData)
// {
// 	cout << "hello" << _iData << endl;
// }
// 
// void Render(float _fData)
// {
// 	cout << "hello float" << _fData << endl;
// }
// 
// void Render(int _iData, int _iSrc)
// {
// 	cout << "hello " << _iData << '\t' << _iSrc << endl;
// }
//int		Render(int _iData)
//{
//	cout << "hello ��ȯ Ÿ��" << endl;
//
//	return _iData;
//}

#pragma endregion

#pragma region default �Ű� ����

// default �Ű� ���� : �Լ� ���� ��, �⺻���� �����Ͽ� �Ű� ���� ���� ���� �� ������ �����ϰ� �ϴ� ����

// 1. �ʱ�ȭ���̱� ������ ���� ������ �� �ѹ��� �⺻���� �������ش�(�Լ� ���Ǻο� default �Ű� ���� ������ �������� ����)
// 2. default �Ű������� �������� ���� �Ű� ������ ȣ�� ������ ���ԵǴ� ������ ��������, default �Ű� ������ �ִ� �Ű� ������ ��� ������ ������ ���ԵǾ� ����
// 3. default �Ű������� �Ű� ������ ���� ���� ��� �� �����ʿ� �ִ� �Ű� �������� �⺻ ���� ������� ��
// 4. �Լ� �����ε� ��, ��ȣ�� ȣ���� �����ϱ� ������ ���� �� �� �κ��� ����ؾ� ��

// void	Draw();
// void	Draw(int _iSrc = 100, int _iData = 200); // �ʱ�ȭ��
// 
// int main()
// {
// 	Draw();
// 	
// 	//Draw(300, 400);
// 
// 	return 0;
// }
// 
// void Draw()
// {
// 	cout << "hello world" << endl;
// }
// 
// void	Draw(int _iSrc, int _iData)
// {
// 	cout << _iSrc << '\t' << _iData << endl;
// }

#pragma endregion

#pragma region ��� �Լ�

void	Recursive(int _iNumber);

int main()
{
	// ��� : �ǵ��ƿ�, �ڱ� �ڽſ��� �ٽ� ���ƿ��� ��Ȳ
	
	// 1. Ż�� ������ �ݵ�� �����ؾ� �Ѵ�.
	// 2. ū ������ �߰� �ɰ��� �ذ��Ѵٴ� ��Ģ�� ö���� �����ϰ� �ִ� ����

	// ���� : �ܼ��� �ڵ�� �ݺ����� ������ �ذ� �� �� �ִ�.
	// ���� : �޸� ���� ���ϰ� ������ �ӵ��� ����.

	Recursive(3);

	return 0;
}

void	Recursive(int _iNumber)
{
	if (0 >= _iNumber)
		return;

	cout << "��� ȣ��" << endl;

	Recursive(--_iNumber);
}

#pragma endregion

