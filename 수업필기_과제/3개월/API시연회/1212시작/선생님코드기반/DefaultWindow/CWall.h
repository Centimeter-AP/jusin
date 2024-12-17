#pragma once
#include "CObj.h"
class CWall : public CObj
{
public:
	CWall();
	virtual ~CWall();

public:
	void Initialize()	 PURE;
	int  Update()		 PURE;
	void Late_Update()	 PURE;
	void Render(HDC hDC) PURE;
	void Release()		 PURE;

protected:
	//int		m_iHP;				// 내구도 (HP)
	int		m_iPowerNeeded;		// 부수기 위해 필요한 힘 (삽 위력 최소컷)
	
	int		m_iImgPosX;
	int		m_iImgPosY;

	//int		m_iWallNumber[WALL_END][MISC_END];
};

