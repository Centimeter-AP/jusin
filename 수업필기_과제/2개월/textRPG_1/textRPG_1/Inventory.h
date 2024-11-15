#pragma once
#include "pch.h"
#include "Player.h"

class CItem;

class CInventory
{
private:
	CCharacter* pPlayer;
	vector<CItem*>* pVecArmorInv;

private:
	void	Set_ArmorInv() { dynamic_cast<CPlayer*>(pPlayer)->Get_ArmorInv(); }

public:
	CInventory():pPlayer(nullptr), pVecArmorInv(nullptr) {};
	~CInventory() { Release(); }

public:
	void	Initialize();
	void	Update();
	void	Release();

public:
	void	Set_Player(CCharacter* _pPlayer) { pPlayer = _pPlayer; }

public:
	void	View_List();
};

