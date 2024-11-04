#pragma once

#include "CObj.h"

class CPlayer : public CObj
{
public:
	enum JOBINDEX { WARRIOR = 1, MAGE, THIEF, END };

public:
	CPlayer();
	~CPlayer();
	
public:
	void		Select_Job();
	void		Set_Hp(int _iHp) { m_tInfo.iHp = _iHp; }

};

