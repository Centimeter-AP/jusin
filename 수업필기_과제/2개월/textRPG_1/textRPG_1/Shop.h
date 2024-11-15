#pragma once
#ifndef SHOP_H
# define SHOP_H

class CItem;

class CShop
{
private:
	vector<CItem*> vecSales;
	CCharacter* Player;
public:
	CShop();
	~CShop();

	void	Initialize();
	void	Update();
	void	Release();

	void	Set_Player(CCharacter* _Player);
	void	View_List();
	void	Select_Item(int idx);
};

#endif

