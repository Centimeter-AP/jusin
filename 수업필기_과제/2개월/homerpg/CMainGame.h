#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H

# include "CPlayer.h"
# include "CMonster.h"

class CMainGame
{
private:
	CPlayer* Player;
	CMonster* Monster;

public:
	CMainGame();
	~CMainGame();

	void	InitializePlayer();
	void	InitializeMonster(int _iMob);
	void	Update();
	void	Release();

	void	RenderAll();
	void	SaveFile();
	void	LoadFile();
	void	CinFailException(bool i);

	void	StartMenu();
	void	Field();
	//void	Shop();
	void	Battle();
};

#endif