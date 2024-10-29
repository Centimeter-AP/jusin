#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H

#include "../Character/Character.h"
#include "../Field/Field.h"
#include "../Player/Player.h"

class CCharacter;
class CField;

class CMainGame
{
	public:
		CMainGame();
		~CMainGame();

		void	Initialize();
		void	Update();
		void	Release();

		void	StartMenu();

	private:
		CCharacter	*Player;
		CField		*Field;
};

#endif
