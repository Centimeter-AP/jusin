#include "pch.h"
#include "Field.h"
#include "Info.h"
#include "System.h"
#include "Player.h"
#include "Monster.h"

CField::CField() : iStep(0), iMaxStep(0), iEncounterFlag(0)
{
	Player = nullptr;
	Monster = nullptr;
	cout << GREEN << "CField" << NOCOLOR << " ������ ȣ��" << endl;
}
CField::~CField()
{
	Release();
	cout << RED << "CField" << NOCOLOR << " �Ҹ��� ȣ��" << endl;
}

void	CField::Initialize()
{
	iMaxStep = 30;
}

void	CField::Release()
{
	delete Monster;
}

void	CField::Update()
{
	int iInput(0);
	int iFlag(0);
	int iCount(0);

	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		if (iMaxStep - iStep > 0)
		{
			cout << Text(iFlag) << endl;
			cout << "======================================================" << endl;
			cout << "�ʵ� �������� ���� ���� �� : " << iMaxStep - iStep << endl;
			cout << "======================================================" << endl;
		}
		else
		{
			// if (Boss_Encounter())
			// {

			// }
			void;
		}

		cout << "1. ��������  2. �����Ѵ�  3. ������  4. ���Ƴ��´�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case 1:
			cout << "�������� �����ϴ�." << endl;
			 
			break;

		case 2:
			cout << "������ ���ư��ϴ�." << endl;
			
			break;

		case 3:
			cout << "�÷��̾� ���� ��" << endl;
			dynamic_cast<CPlayer*>(Player)->Level_Up();
			
			break;

		case 4:
			while (1)
			{
				system("pause"); system("cls");
				Player->Print_Info();
				cout << "���Ƴ����� �Ǹ� �̹� ���࿡���� ������ ���� ���� �ҽ��ϴ�. ���ư��ðڽ��ϱ�?" << endl;
				cout << "1. ���Ƴ�����  2. ����Ѵ�" << endl;
				cout << "�Է� : ";
				cin >> iInput;
				CINEXCEPTION(2);
				break;
			}
			if (iInput == 1)
			{
				iStep -= iCount / 2;
				if (iStep < 0)
					iStep = 0;
				return;
			}

			else
				continue;

		default:
			break;
		}
		Random_Encounter();
		iStep++;
		iCount++;
	}
}


void	CField::Random_Encounter()
{
	int iInput(0);
	if (!Monster)
		Monster = new CMonster("����", dynamic_cast<CPlayer*>(Player)->Get_PInfo()->iLvl + rand() % 3);
	// ���� ������
	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		Monster->Print_Info();
		cout << "1. ����  2. ����" << endl;
		cin >> iInput;
		if (iInput == 2)
			break;
		else if (iInput == 1)
		{
			if (Battle())
				break;
		}

	}
	delete Monster;
	Monster = nullptr;
}

const char* CField::Text(int _iFlag)
{
	int iRand(0);
	iRand = rand() % 4;
	(void)_iFlag;
	// if (_iFlag)
	switch (iRand)
	{
	case RAND1:
		return "������ ���ӿ��� ������� ���¥�� ���� �Ҹ��� �鸰��. \n�� �ؿ��� �������� ������ �����ӿ� ���� ������, �ٶ��� ��鸮�� ���������� ��ġ �������� ��ó�� ���δ�.";

	case RAND2:
		return "�� ���� ���� �ڲٸ� ���ϴ� ���ϴ�. \n����� ������ ���� �������, �ͼ��ߴ� �������� ������ ��������. \n��ġ �� ���� ����� ���η� �ϴ� �� ���� �η����� �����Ѵ�.";

	case RAND3:
		return "£�� �״��� �帮�� ���� ��ġ ����� ���δ� ���� �йڰ��� �ش�. \n�ڸ� ���ƺ���, ������ ���̿� � ���簡 ���� ���� �͸� ���� �Ҿ��� ����� ���ֽ��� ��������.";

	case RAND4:
		return "�Ӹ� ���� ������������ �Ⱬ�ϰ� �Ϸ��̸�, ��ġ �������� \n�ӻ����� �鸮�� ���� ������ ����Ų��.";

	default:
		return "Did something went wrong?";
	}
	return "switch is not working";
}

int		CField::Battle()
{
	Player->Attack(Monster);
	if (Monster->Get_Info()->iHP < 1)
	{
		cout << "�÷��̾� �¸�!" << endl;
		
		dynamic_cast<CPlayer*>(Player)->Player_Win();
		return 1;
	}
	Monster->Attack(Player);
	if (Player->Get_Info()->iHP < 1)
	{
		cout << "�÷��̾� �й�..." << endl;
		
		dynamic_cast<CPlayer*>(Player)->Player_Lose();
		return 1;
	}
	return 0;
}