#pragma once
#ifndef BOMB_H
# define BOMB_H

# include <iostream>
# include "Item.h"

class CBomb : public CItem
{
public:
	CBomb() { strcpy_s(m_szName, size(m_szName), "ÆøÅº"); };
	~CBomb() {};

	void	Use(CCharacter* obj);
	void	Explain();
	CItem* Clone();
};

#endif