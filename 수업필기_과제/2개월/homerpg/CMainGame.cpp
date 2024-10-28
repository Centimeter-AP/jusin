#include "pch.h"
#include "CMainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Monster = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void	CMainGame::InitializePlayer()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		cout << "������ �������ּ���." << endl;
		cout << "1. ����  2. ������  3. ����" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(3)
			break;
	}
	switch (iInput)
	{
	case WARRIOR:
		Player = new CPlayer("����", 120, 9);
		break;

	case MAGE:
		Player = new CPlayer("������", 100, 10);
		break;

	case ROGUE:
		Player = new CPlayer("����", 95, 11);
		break;

	default:
		break;
	}

}

void CMainGame::InitializeMonster(int _iMob)
{
	SAFE_DELETE(Monster)
	switch (_iMob)
	{
	case EASY:
		Monster = new CMonster("�ʱ� ���", 30, 3);
		break;

	case NORMAL:
		Monster = new CMonster("�߱� ��ũ", 50, 5);
		break;

	case HARD:
		Monster = new CMonster("��� �Ǹ�", 100, 10);
		break;

	default:
		break;
	}
}

void	CMainGame::Update()
{
	int	iInput(0);

	while (1)
	{
		system("cls");
		Player->RenderInfo();
		cout << "�༱���� �����ּ���." << endl;
		cout << "1. �ʵ�  2. ����  3. ����  4. ����" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(4)
			switch (iInput)
			{
			case 1:
				Field();
				break;

			case 2:
				//Shop();
				break;

			case 3:
				SaveFile();
				break;

			case 4:
				return;

			default:
				break;
			}
	}
	
}
void	CMainGame::Release()
{
	SAFE_DELETE(Player)
	SAFE_DELETE(Monster)
}


void CMainGame::RenderAll()
{
	Player->RenderInfo();
	Monster->RenderInfo();
}

void CMainGame::SaveFile()
{
	FILE* fSave = nullptr;
	fSave = fopen("./Save.sav", "wb");
	if (fSave)
	{
		fwrite(Player, sizeof(CPlayer), 1, fSave);
		fclose(fSave);
		cout << "���忡 �����߽��ϴ�." << endl;
		// system("pause");
		//sleep(1);
	}
	else
	{
		cout << "���忡 �����Ͽ����ϴ�.. " << endl;
	}
}

void CMainGame::LoadFile()
{
	FILE* fLoad = nullptr;
	fLoad = fopen("./Save.sav", "rb");
	if (!Player)
		Player = new CPlayer("�̸�", 0, 0);

	if (fLoad)
	{
		//fread(Player, sizeof(CPlayer), 1, fLoad);
		fread_s(Player, sizeof(CPlayer), sizeof(CPlayer), 1, fLoad);
		fclose(fLoad);
		cout << "�ҷ����⿡ �����߽��ϴ�." << endl;
	}
	else
	{
		cout << "���̺갡 �����ϴ�. " << endl;
	}
}

void	CMainGame::CinFailException(bool i)
{
	// system("clear");
	cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	// system("pause");
	if (i)
	{
		cin.clear();
		while (cin.get() == '\n') continue;
	}
}

void	CMainGame::StartMenu()
{
	int	iInput(0), iFlag(1);

	while (1)
	{
		system("cls");
		cout << "��"; for (int i = 0; i < 38; ++i) cout << "��"; cout << "��" << endl;
		cout << "��    TEXT RPG   ~BRAND NEW C++ VER~    ��" << endl;
		cout << "��"; for (int i = 0; i < 38; ++i) cout << "��"; cout << "��" << endl;
		cout << endl;
		if (iFlag) { /*sleep(1); */ iFlag = 0; }

		cout << "1. ó������\t\t2. �̾��ϱ�" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(2)
			if (iInput == 1)
				InitializePlayer();
			else
				LoadFile();
		break;
	}
}
void CMainGame::Field()
{
	int 	iInput(0), iHeal(1);

	while (1)
	{
		rand() % 3 == 0 ? iHeal = 0 : iHeal = 1;
		while (1)
		{
			system("cls");
			Player->RenderInfo();
			cout << "1.�ʱ�  2. �߱�  3. ���  4. �� �ܰ�";
			if (!iHeal)
				cout << "  5. �޽�ó";		// iHeal==0 TRUE
			cout << "\n�Է� : ";
			cin >> iInput;
			CINEXCEPTION(BACK - iHeal);
			break;
		}
		if (iInput == BACK)
			return;
		else if (iInput == HEAL)
			Player->Set_FullHP();
		else
		{
			InitializeMonster(iInput);
			Battle();
			SAFE_DELETE(Monster)
		}
	}
}

//void CMainGame::Shop()
//{
//}

void CMainGame::Battle()
{
	int iInput(0);
	while (1)
	{
		system("cls");
		RenderAll();
		cout << "1. ����  2. ����" << endl;
		cout << "�Է� : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 1)
		{
			Player->Attack(Monster);
			Monster->Attack(Player);
			if (Player->Get_iHP() <= 0)
			{
				cout << "�÷��̾� �й�!" << endl;
				cout << "����ġ�� �Ұ� ��Ȱ�մϴ�." << endl;
				Player->Set_iExp(-1 * (Monster->Get_iAtk() * 3));
				Player->Set_FullHP();
				system("pause");
				break;
			}
			if (Monster->Get_iHP() <= 0)
			{
				cout << "�÷��̾� �¸�!" << endl;
				cout << Monster->Get_iAtk() * 2 << "�� ����ġ ȹ��" << endl;
				Player->Set_iExp(Monster->Get_iAtk() * 2);
				system("pause");
				break;
			}
		}
	}
}
