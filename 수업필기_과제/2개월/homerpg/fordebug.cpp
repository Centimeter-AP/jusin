#include "pch.h"



int main()
{
	srand((unsigned int)time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CMainGame mainGame;

	mainGame.StartMenu();
	mainGame.Update();

	return 0;
}