#pragma once
#include "Shop.h"

class CItem;

class CArmorShop : public CShop
{
private:
	vector<CItem*> vecArmorSales[ARMOR_END];

public:
	CArmorShop();
	virtual ~CArmorShop();

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	View_List(ARMORSLOT _TYPE);
};