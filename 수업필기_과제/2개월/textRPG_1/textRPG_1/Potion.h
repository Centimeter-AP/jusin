#pragma once
#ifndef POTION_H
# define POTION_H

# include "Item.h"

class CCharacter;

class CPotion : public CItem
{
public:
	CPotion() { iPrice = 500; m_sName = "����"; };;
	~CPotion() {};	

	void	Use(CCharacter* obj);
	void	Explain();
	CItem*	Clone();

	
};

#endif