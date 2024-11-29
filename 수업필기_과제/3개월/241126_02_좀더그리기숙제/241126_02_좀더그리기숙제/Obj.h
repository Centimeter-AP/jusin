#pragma once
#include "Define.h"
class CObj
{
public:
	CObj() : m_lSpeed(0), enKeyDir(KUP) { ZeroMemory(&mInfo, sizeof(INFO)); ZeroMemory(&mRect, sizeof(RECT)); }
	virtual ~CObj() {}

public:
	virtual void	Update()		 PURE;
	virtual void	Late_Update()	 PURE;
	virtual void	Render(HDC _hdc) PURE;
	virtual void	Initialize()	 PURE;
	virtual void	Release()		 PURE;

public:
	void	Set_Rect();
	void	Set_Pos(float _fX, float _fY) { mInfo.fX = _fX; mInfo.fY = _fY; }
	void	Set_Dir(KDIRECTION _Dir) { enKeyDir = _Dir; }
	INFO	Get_Info() const { return mInfo; }
	RECT*	Get_Rect() { return &mRect; }

protected:
	INFO		mInfo;
	RECT		mRect;
	LONG		m_lSpeed;
	KDIRECTION	enKeyDir;
	bool		isDead;
};

