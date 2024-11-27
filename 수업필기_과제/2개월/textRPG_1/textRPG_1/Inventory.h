#pragma once
#include "pch.h"
#include "Player.h"

class CItem;

class CInventory
{
private:
	CCharacter* Player;
	vector<CItem*>* pVecArmorInv;
	vector<CItem*>* pVecItemInv;
private:
	void	Set_ArmorInv() { pVecArmorInv = dynamic_cast<CPlayer*>(Player)->Get_ArmorInv(); pVecItemInv = Player->Get_ItemInv(); }

public:
	CInventory():Player(nullptr), pVecArmorInv(nullptr), pVecItemInv(nullptr) {};
	~CInventory() {}

public:
	void	Initialize();
	void	Update();
	void	Sell_Update();

public:
	void	Set_Player(CCharacter* _pPlayer) { Player = _pPlayer; }

public:
	void	View_Armor();
	void	View_Item();
	void	View_Equipping(ARMORSLOT _TYPE);
	void	Sell_Armor();
	void	Sell_Item();
};

