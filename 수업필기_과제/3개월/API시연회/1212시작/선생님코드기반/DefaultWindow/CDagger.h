#pragma once
#include "CWeapon.h"
class CDagger : public CWeapon
{
	// CWeapon��(��) ���� ��ӵ�
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

