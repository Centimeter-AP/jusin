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
	int		iCount;

public:
	CItem():iPrice(0), iCount(1) { m_sName = ""; };
	virtual ~CItem() {};

	virtual void	Use(CCharacter* obj) = 0;
	virtual CItem* Clone() = 0;
	virtual void	Explain() = 0;

public:
	string	Get_Name() const	{ return m_sName; }
	int		Get_Price() const	{ return iPrice; }
	int		Get_Count() const	{ return iCount; }
	void	Set_Count(int i)	{ iCount += i; }
};

#endif
