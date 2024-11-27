#pragma once
#include "Obj.h"
class CMonster :  public CObj
{
public:
	CMonster():isWall(false) {};
	virtual ~CMonster() {};
	
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void Initialize() override;
	void Release() override;

private:
	bool isWall;
};

