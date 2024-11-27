#pragma once
#ifndef SHOP_H
# define SHOP_H
# include "Character.h"

class CItem;

class CShop
{
protected:
	CCharacter* Player;
	string		sPlayerWeapon;

public:
	CShop();
	virtual ~CShop();

	virtual void	Initialize();
	virtual void	Update();
	virtual void	Release() {};

	void	Set_Player(CCharacter* _Player);
	//virtual void	View_List();
	//void	Render_Item(CItem* _Item);
	void	Select_Item(int idx);
};

#endif

