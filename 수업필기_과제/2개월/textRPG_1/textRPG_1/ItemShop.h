#pragma once
#include "Shop.h"
#include "System.h"


class CItemShop : public CShop
{
private:
	vector<CItem*> vecItemSales;

public:
	CItemShop() { vecItemSales.reserve(ITEMINVMAX); };
	virtual ~CItemShop() { Release(); };

public:
	void	Initialize();
	void	Update();
	void	Release() { for_each(vecItemSales.begin(), vecItemSales.end(), Safe_Delete<CItem*>); }

public:
	void	View_List();
	void	Select_Item(int idx);

};

