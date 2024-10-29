#include "../precom.h"
#include "../Info.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
	Player = nullptr;
	Field = nullptr;
	cout << "CMainGame 생성자 호출" << endl;
}

CMainGame::~CMainGame()
{
	Release();
	cout << "CMainGame 소멸자 호출" << endl;
}

void	CMainGame::Initialize()
{
	Player = new CPlayer;
	Player->Initialize();
	Field = new CField;
	Field->Initialize();

}



void	CMainGame::Update()
{

}

void	CMainGame::Release()
{
	SAFEDELETE(Player);
	SAFEDELETE(Field);
}

