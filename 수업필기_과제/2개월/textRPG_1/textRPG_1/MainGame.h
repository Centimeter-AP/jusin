#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H

#include "Character.h"
#include "Field.h"
#include "Player.h"
#include "Shop.h"


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
	CCharacter* Player;
	CField* Field;
	CShop* Shop;
};

#endif