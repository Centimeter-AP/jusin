#pragma once
#include "CItem.h"
class CWeapon : public CItem
{
public:
	CWeapon() : m_iDamage(0){}
	virtual ~CWeapon(){}

public:
	virtual void Initialize()		PURE;
	virtual int Update()			PURE;
	virtual void Late_Update()		PURE;
	virtual void Render(HDC hDC)	PURE;
	virtual void Release()			PURE;

	int		Get_Damage() { return m_iDamage; }
protected:
	int		m_iDamage
	
};

