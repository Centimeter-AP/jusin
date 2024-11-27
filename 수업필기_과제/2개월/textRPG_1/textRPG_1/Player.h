#pragma once
#ifndef PLAYER_H
# define PLAYER_H

# include "Character.h"
# include "Info.h"
# include "pch.h"

class CArmor;

class CPlayer : public CCharacter
{
private:
	PLAYERINFO	mPInfo;
	vector<CItem*> vecArmorInv;
	CItem* mArmorSlot[ARMOR_END];

public:
	CPlayer();
	CPlayer(string sName, int _iHP, int _iAtk);
	virtual ~CPlayer();

public:
	void	Initialize();
	void	Release();

public:
	PLAYERINFO* Get_PInfo() { return &mPInfo; };
	vector<CItem*>* Get_ArmorInv() { return &vecArmorInv; }
	CItem* Get_TypeSlot(ARMORSLOT _TYPE) const { return mArmorSlot[_TYPE];}

public:
	void	Level_Up();
	void	Player_Lose();
	void	Player_Win();
	void	Print_Info();
	void	Equip_Armor(CItem* pArmor);
	void	Unequip_Armor(CItem* pArmor);
	void	Buy_Armor(CItem* pArmor);
	void	Sell_Armor(CItem* pArmor);
	void	Buy_Item(CItem* pItem);
	void	Sell_Item(CItem* pItem);

};

#endif
