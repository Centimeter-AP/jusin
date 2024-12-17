#pragma once
#include "CObj.h"
class CWall : public CObj
{
public:
	CWall();
	virtual ~CWall();

public:
	virtual void Initialize()	 {}
	virtual int  Update() { return 0; }
	virtual void Late_Update()	 {}
	virtual void Render(HDC hDC) {}
	virtual void Release() {}

public:
	WALLTYPE	Get_WallType() { return m_enWallType; }

protected:
	//int		m_iHP;				// 내구도 (HP)
	int		m_iPowerNeeded;		// 부수기 위해 필요한 힘 (삽 위력 최소컷)
	
	int		m_iImgPosX;
	int		m_iImgPosY;

	WALLTYPE	m_enWallType;
};

