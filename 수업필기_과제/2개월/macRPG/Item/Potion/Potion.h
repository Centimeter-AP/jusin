#pragma once
#ifndef POTION_H
# define POTION_H

# include "../Item.h"

class CCharacter;

class CPotion : public CItem
{
	public:
		CPotion(){strcpy(m_szName, "포션");};;
		~CPotion(){};

		void	Use(CCharacter *obj);
		void	Explain();
		CItem*	Clone();
};

#endif
