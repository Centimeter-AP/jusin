#pragma once

#include "CObj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(const char* pName, int _iHp, int _iAttack);
	~CMonster();
};

