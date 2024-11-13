#pragma once
#ifndef ITEM_H
# define ITEM_H

#include "pch.h"

class CCharacter;
class CItem
{
protected:
	char m_szName[32];
public:
	CItem() {};
	CItem& operator =(const CItem& rhs)
	{

	}
	virtual ~CItem() {};

	virtual void	Use(CCharacter* obj) = 0;
	virtual CItem* Clone() = 0;
	virtual void	Explain() = 0;
	const char* Get_Name() { return m_szName; }
};

#endif
