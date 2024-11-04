#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	CObj(const char* pName, int _iHp, int _iAttack);
	~CObj();

public:
	void		Set_Damage(int _iAttack) { m_tInfo.iHp -= _iAttack; }
	INFO		Get_Info() { return m_tInfo; }

	void		Render();
	void		Release();

protected:
	INFO		m_tInfo;

};

