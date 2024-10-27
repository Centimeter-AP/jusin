#include "pch.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Monster = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void	CMainGame::Initialize()
{
	int iInput(0);

	while (1)
	{
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
		Player = new CPlayer("마법사", 120, 9);
		break;
	
	case ROGUE	:
		Player = new CPlayer("도적", 120, 9);
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
		// system("clear"); //
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
			Shop();
			break;
		
		case 3:
			SaveFile();
			break;
		
		case 4:
			Release();
			return ;
		
		default:
			break;
		}
	}

}
void	CMainGame::Release()
{
	if (Player)
		SAFE_DELETE(Player)
	if (Monster)
		SAFE_DELETE(Monster)
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
		Player = new CPlayer;
	if (fLoad)
	{
		fread(Player, sizeof(CPlayer), 1, fLoad);
		fclose(fLoad);
		cout << "불러오기에 성공했습니다." << endl;
		// system("pause");
		// sleep(1);
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
		system("clear"); //
		cout << "┌"; for (int i = 0; i < 38; ++i) cout << "─"; cout << "┐" << endl;
		cout << "│    TEXT RPG   ~BRAND NEW C++ VER~    │" << endl;
		cout << "└"; for (int i = 0; i < 38; ++i) cout << "─"; cout << "┘" << endl;
		cout << endl;
		if (iFlag){sleep(1);iFlag=0;}

		cout << "1. 처음부터\t\t2. 이어하기" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(2)
		if (iInput == 1)
			Initialize();
		else
			LoadFile();
		break;
	}
}
void CMainGame::Field()
{

}

void CMainGame::Shop()
{
}
