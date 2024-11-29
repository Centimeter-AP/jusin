#pragma once
#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj() {}

public:
	virtual int		Update()		 PURE;
	virtual void	Late_Update()	 PURE;
	virtual void	Render(HDC _hdc) PURE;
	virtual void	Initialize()	 PURE;
	virtual void	Release()		 PURE;
	
public:
	void	Set_Rect();
	void	Set_Dir(KDIRECTION _Dir) { enKeyDir = _Dir; }
	void	Set_Pos(float _fX, float _fY) { mInfo.fX = _fX; mInfo.fY = _fY; }
	void	Set_Size(float _fSize) { mInfo.fCX = mInfo.fCY = _fSize; }
	void	Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void	Set_Dead() { isDead = true; }
	INFO	Get_Info() { return mInfo; }
	RECT*	Get_Rect() { return &mRect; }

protected:
	INFO		mInfo;
	RECT		mRect;
	float		m_fSpeed;
	float		m_fAngle;
	float		m_fDistance;
	KDIRECTION	enKeyDir;
	bool		isDead;
};

