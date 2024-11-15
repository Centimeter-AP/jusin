#pragma once
#ifndef BOMB_H
# define BOMB_H

# include <iostream>
# include "Item.h"

class CBomb : public CItem
{
public:
	CBomb() { iPrice = 500; m_sName = "ÆøÅº"; };
	~CBomb() {};

	void	Use(CCharacter* obj);
	void	Explain();
	CItem*	Clone();
};

#endif