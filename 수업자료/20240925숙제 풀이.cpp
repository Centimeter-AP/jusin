#include <iostream>

using namespace std;

int main()
{

#pragma region ���� �̸� ��Ģ

	// 1. ���� �̸��� ���ĺ��� ���ڷ� ���� �� �� �ִ�. ��, ���ڰ� �� �տ� ��ġ�� �� ����.
	// 2. ���� �̸��� ��, �ҹ��ڸ� Ȯ���� �����Ѵ�.
	// 3. ���α׷��� ���� �����ϴ� �⺻ Ű����� �̸��� ���� �� ����.
	// ex)	int	namespace = 100; (x)
	// 4. ���� �̸��� ���� �Ǵ� Ư�� ���ڰ� ���� �� �� ����. ��, _�� ���
	// ex) int Player_Hp = 100; (o)
	// 5. ���� �̸��� ������ �� ���� �Ǵ� �� ����(�ʱ�ȭ) �� �� ����.

#pragma endregion

#pragma region ǥ���

	// 1. �밡���� ǥ��� : ���� �̸� �տ� �ڷ����� ���ϴ� ���ڸ� ����
	// ex) int iHp; float fTime; char cName;

	// 2. ī�� ǥ��� : �ܾ�� �ܾ� ���̸� �빮�ڷ� �����ϴ� ���
	// ex) int playerHp

	// 3. �Ľ�Į ǥ��� : �ܾ��� ���� ���ڸ� ������ �빮�ڷ� ǥ���ϴ� ���
	// ex) int PlayerHp

	// 4. ����� ǥ��� : �ܾ�� �ܾ� ���̿� _�� ���
	// ex) void	Set_Damage();
	// ex) void	Render(int _iHp);

#pragma endregion

#pragma region ����Ǯ��

	int		iKorean(0), iEnglish(0), iMath(0), iTotal(0);
	float	fAver(0.f);

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKorean;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEnglish;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath;

	iTotal = iKorean + iEnglish + iMath;
	
	// ������ �� ��ȯ(casting)
	// fAver = iTotal / 3.f;

	// ����� �� ��ȯ(casting)
	fAver = (float)iTotal / 3.f;
	// fAver = float(iTotal) / 3.f;

	// '\t' : ��Ű�� ���� �� ��ŭ ������ ����
	cout << "����" << '\t' << "����\t����\t����\t���" << endl;
	cout << iKorean << '\t' << iEnglish << '\t' << iMath << '\t' << iTotal << '\t' << fAver << endl;

#pragma endregion

	return 0;
}