#pragma once
#include "CWeapon.h"
class CDagger : public CWeapon
{
	// CWeapon을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

