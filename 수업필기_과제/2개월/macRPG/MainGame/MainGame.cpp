#include "../precom.h"
#include "../Info.h"
#include "../System/System.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Field = nullptr;
	cout << GREEN << "CMainGame" << NOCOLOR << " 생성자 호출" << endl;
}

CMainGame::~CMainGame()
{
	Release();
	cout << RED << "CMainGame" << NOCOLOR << " 소멸자 호출" << endl;
}

// 저게 오늘 디코에서 유경님이 
// 아직 안알려줘서
// 못쓰는거 아니냐고
// ㄱ래서 다운캐스팅 해야하는거 아니냐고 하는거
// 안배웟어요


void	CMainGame::Initialize()
{
	if (Player == nullptr)
	{
		Player = new CPlayer;
		Player->Initialize();
	}
	Field = new CField;
	Field->Initialize();
}



void	CMainGame::Update()
{
	int iInput(0);

	while (1)
	{
		// system("clear");
		Player->Print_Info();
		cout << "행선지를 정해주세요." << endl;
		cout << "1. 필드  2. 상점  3. 저장  4. 종료" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case MENU::FIELD:
			Field->Update();
			break;
		
		case MENU::SHOP:
			cout << "공사중" << endl;
			sleep(1);
			break;
		
		case MENU::SAVE:
			cout << "선생님이 저장을 안알려줬지롱" << endl;
			sleep(1);
			break;
		
		case MENU::EXIT:
			cout << "게임을 종료합니다." << endl;
			return ;
		
		default:
			break;
		}
	}
}

void	CMainGame::Release()
{
	SAFEDELETE(Player);
	SAFEDELETE(Field);
}

