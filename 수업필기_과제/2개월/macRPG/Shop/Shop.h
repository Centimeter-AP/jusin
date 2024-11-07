#pragma once
#ifndef SHOP_H
# define SHOP_H

# include "../Item/Item.h"

class CShop
{
	private:
		CItem *mSales[4];
		CCharacter	*Player;
	public:
		CShop();
		~CShop();

		void	Initialize();
		void	Update();
		void	Release();

		void	Set_Player(CCharacter *_Player);

};

#endif


#include "../Info.h"
#include "../Item/Potion/Potion.h"
#include "../Player/Player.h"

CShop::CShop()
{
	for (int i = 0; i < 4; ++i)
	{
		mSales[i] = nullptr;
	}
	Player = nullptr;
}
CShop::~CShop()
{
	Release();
}

void	CShop::Set_Player(CCharacter *_Player)
{
	Player = _Player;
}

void	CShop::Initialize()
{
	for (int i = 0; i < 4; ++i)
	{
		mSales[i] = new CPotion;
	}
}

void	CShop::Update()
{
	int iInput(0);
	
	while (1)
	{
		cout << "상점이지롱" << endl;
		cin >> iInput;
	}
}

void	CShop::Release()
{
	for (int i = 0; i < 4; ++i)
	{
		SAFEDELETE(mSales[i]);
	}
}
