#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include "Info.h"

class CItem;
class CArmor;

class CCharacter
{
protected:
	INFO	mInfo;
	vector<CItem*> vecItemInv;
	vector<CItem*> vecArmorSlot[ARMOR_END];

public:
	CCharacter();
	virtual ~CCharacter();

	virtual void	Initialize() = 0;
	virtual void	Release() = 0;

public:
	INFO* Get_Info() { return &mInfo; }
	int		Get_CritDamage();
	void	Set_Item(CItem* _pItem);

public:
	virtual void	Print_Info() = 0;
	void	Attack(CCharacter* obj);

};

#endif
