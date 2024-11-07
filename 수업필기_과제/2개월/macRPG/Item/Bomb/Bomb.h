#pragma once
#ifndef BOMB_H
# define BOMB_H

# include <iostream>
# include "../Item.h"

class CBomb : public CItem
{
	public:
		CBomb(){strcpy(m_szName, "폭탄");};
		~CBomb(){};

		void	Use(CCharacter *obj);
		void	Explain();
		CItem*	Clone();
};

#endif
