#pragma once
#ifndef ITEM_H
# define ITEM_H

#include "pch.h"

class CCharacter;
class CItem
{
protected:
	char	m_szName[32];
	int		iPrice;
public:
	CItem():iPrice(0) { strcpy_s(m_szName, strlen(m_szName) + 1, ""); };
	CItem& operator =(const CItem& rhs)
	{

	}
	virtual ~CItem() {};

	virtual void	Use(CCharacter* obj) = 0;
	virtual CItem* Clone() = 0;
	virtual void	Explain() = 0;
	const char* Get_Name() const { return m_szName; }
	int	Get_Price() const { return iPrice; }
};

#endif
