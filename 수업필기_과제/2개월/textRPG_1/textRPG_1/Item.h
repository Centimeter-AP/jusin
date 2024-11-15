#pragma once
#ifndef ITEM_H
# define ITEM_H

#include "pch.h"

class CCharacter;
class CItem
{
protected:
	string	m_sName;
	int		iPrice;

public:
	CItem():iPrice(0) { m_sName = ""; };
	CItem& operator =(const CItem& rhs)
	{

	}
	virtual ~CItem() {};

	virtual void	Use(CCharacter* obj) = 0;
	virtual CItem* Clone() = 0;
	virtual void	Explain() = 0;

public:
	string Get_Name() const { return m_sName; }
	int	Get_Price() const { return iPrice; }
};

#endif
