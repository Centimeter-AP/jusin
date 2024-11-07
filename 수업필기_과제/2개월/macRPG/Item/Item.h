#pragma once
#ifndef ITEM_H
# define ITEM_H

# include <iostream>

class CCharacter;
class CItem
{
	protected:
		char m_szName[32];
	public:
		CItem(){};
		virtual ~CItem() {};

		virtual void	Use(CCharacter *obj) = 0;
		virtual CItem*	Clone() = 0;
		virtual void	Explain() = 0;
};

#endif

