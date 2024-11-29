#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster() : isWall(false) {};
	~CMonster() {};

public:
	int	 Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Initialize() override;
	void Release() override;

private:
	bool	isWall;
};

