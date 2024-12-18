#pragma once
#include "CItem.h"
class CWeapon : public CItem
{
public:
	CWeapon() {}
	virtual ~CWeapon(){}

public:
	virtual void Initialize()		PURE;
	virtual int Update()			PURE;
	virtual void Late_Update()		PURE;
	virtual void Render(HDC hDC)	PURE;
	virtual void Release()			PURE;


protected:

	
};

