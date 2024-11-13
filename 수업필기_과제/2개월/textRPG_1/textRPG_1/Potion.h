#pragma once
#ifndef POTION_H
# define POTION_H

# include "Item.h"

class CCharacter;

class CPotion : public CItem
{
public:
	CPotion() { strcpy_s(m_szName, size(m_szName), "����"); };;
	~CPotion() {};	

	void	Use(CCharacter* obj);
	void	Explain();
	CItem* Clone();

	
};

#endif