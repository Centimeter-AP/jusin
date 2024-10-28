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
		cout << "직업을 선택해주세요." << endl;
		cout << "1. 전사  2. 마법사  3. 도적" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(3)
			break;
	}
	switch (iInput)
	{
	case WARRIOR:
		Player = new CPlayer("전사", 120, 9);
		break;

	case MAGE:
		Player = new CPlayer("마법사", 100, 10);
		break;

	case ROGUE:
		Player = new CPlayer("도적", 95, 11);
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
		Monster = new CMonster("초급 고블린", 30, 3);
		break;

	case NORMAL:
		Monster = new CMonster("중급 오크", 50, 5);
		break;

	case HARD:
		Monster = new CMonster("상급 악마", 100, 10);
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
		cout << "행선지를 정해주세요." << endl;
		cout << "1. 필드  2. 상점  3. 저장  4. 종료" << endl;
		cout << "입력 : ";
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
		cout << "저장에 성공했습니다." << endl;
		// system("pause");
		//sleep(1);
	}
	else
	{
		cout << "저장에 실패하였습니다.. " << endl;
	}
}

void CMainGame::LoadFile()
{
	FILE* fLoad = nullptr;
	fLoad = fopen("./Save.sav", "rb");
	if (!Player)
		Player = new CPlayer("이름", 0, 0);

	if (fLoad)
	{
		//fread(Player, sizeof(CPlayer), 1, fLoad);
		fread_s(Player, sizeof(CPlayer), sizeof(CPlayer), 1, fLoad);
		fclose(fLoad);
		cout << "불러오기에 성공했습니다." << endl;
	}
	else
	{
		cout << "세이브가 없습니다. " << endl;
	}
}

void	CMainGame::CinFailException(bool i)
{
	// system("clear");
	cout << "잘못 입력하셨습니다." << endl;
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
		cout << "┌"; for (int i = 0; i < 38; ++i) cout << "─"; cout << "┐" << endl;
		cout << "│    TEXT RPG   ~BRAND NEW C++ VER~    │" << endl;
		cout << "└"; for (int i = 0; i < 38; ++i) cout << "─"; cout << "┘" << endl;
		cout << endl;
		if (iFlag) { /*sleep(1); */ iFlag = 0; }

		cout << "1. 처음부터\t\t2. 이어하기" << endl;
		cout << "입력 : ";
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
			cout << "1.초급  2. 중급  3. 고급  4. 전 단계";
			if (!iHeal)
				cout << "  5. 휴식처";		// iHeal==0 TRUE
			cout << "\n입력 : ";
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
		cout << "1. 공격  2. 도망" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(2);
		if (iInput == 1)
		{
			Player->Attack(Monster);
			Monster->Attack(Player);
			if (Player->Get_iHP() <= 0)
			{
				cout << "플레이어 패배!" << endl;
				cout << "경험치를 잃고 부활합니다." << endl;
				Player->Set_iExp(-1 * (Monster->Get_iAtk() * 3));
				Player->Set_FullHP();
				system("pause");
				break;
			}
			if (Monster->Get_iHP() <= 0)
			{
				cout << "플레이어 승리!" << endl;
				cout << Monster->Get_iAtk() * 2 << "의 경험치 획득" << endl;
				Player->Set_iExp(Monster->Get_iAtk() * 2);
				system("pause");
				break;
			}
		}
	}
}
