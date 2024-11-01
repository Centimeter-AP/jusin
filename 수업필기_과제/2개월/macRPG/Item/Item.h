#pragma once
#ifndef ITEM_H
# define ITEM_H

# include <iostream>

class CItem
{
	protected:
		char m_szName[32];
	public:
		CItem(){{strcpy(m_szName, "기본 아이템");};}
		virtual ~CItem() {};

		virtual void	Use() = 0;
		virtual CItem*	Clone() = 0;
};

#endif

