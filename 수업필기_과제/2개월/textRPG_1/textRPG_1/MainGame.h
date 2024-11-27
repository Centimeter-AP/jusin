#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H


class CInventory;
class CField;
class CShop;
class CCharacter;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

	void	Initialize();
	void	Update();
	void	Release();

	//void	StartMenu();
	void	Select_Shop();

private:
	CCharacter*	Player;
	CInventory* Inven;
	CField*		Field;
	CShop*		ItemShop;
	CShop*		ArmorShop;
};

#endif