#pragma once

#include "Item.h"
#include "Info.h"

class CArmor : public CItem
{
protected:
	int			iAtk;
	int			iHP;
	bool		isEquip;
	ARMORSLOT	enType;

public:	
	CArmor() :iAtk(0), iHP(0), isEquip(false), enType(ARMOR_END) {}
	CArmor(int _iAtk, int _iHP, ARMORSLOT _enType, string _sName, bool _isEquip = false)
	{
		iAtk = _iAtk; iHP = _iHP, enType = _enType; m_sName = _sName; isEquip = _isEquip;
	}
	virtual ~CArmor() {}

public:
	void Use(CCharacter* obj);
	CItem* Clone();
	void Explain();

public:
	void	Initialize();
	void	Equip(CCharacter* obj);
	void	Unequip(CCharacter* obj);
	void	Make_Armor();

};

