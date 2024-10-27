#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H

# include "Player.h"
# include "Monster.h"

class CMainGame
{
	private:
		CPlayer* Player;
		CMonster* Monster;
	public:
		CMainGame();
		~CMainGame();

		void	Initialize();
		void	Update();
		void	Release();

		void	SaveFile();
		void	LoadFile();
		void	CinFailException(bool i);

		void	StartMenu();
		void	Field();
		void	Shop();
		void	Battle();

};

#endif
