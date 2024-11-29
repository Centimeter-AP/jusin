#pragma once
#include "Obj.h"

class CBullet : public CObj
{
public:
	CBullet() {};
	~CBullet() {};
public:
	int	 Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Initialize() override;
	void Release() override;
};

