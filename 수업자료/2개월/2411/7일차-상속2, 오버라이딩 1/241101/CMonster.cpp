#include "pch.h"
#include "CMonster.h"

CMonster::CMonster()
{
}

CMonster::CMonster(const char* pName, int _iHp, int _iAttack)
	: CObj(pName, _iHp, _iAttack)
{
	
}

CMonster::~CMonster()
{

}

