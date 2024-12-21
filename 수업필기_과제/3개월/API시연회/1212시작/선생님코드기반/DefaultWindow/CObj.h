#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	INFO				Get_Info() { return m_tInfo; }
	const INFO*			Get_Info_Pointer() { return &m_tInfo; }
	const RECT*			Get_Rect() { return &m_tRect; }
	DIRECTION			Get_Direction() { return m_eDir; }

	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	const RENDERID Get_GroupID() const { return m_eRender; }

	void		Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void		Set_PosY(float _fY) { m_tInfo.fY += _fY; }

	void		Set_Direction(DIRECTION eDir) { m_eDir = eDir; }
	void		Set_Dead() { m_bDead = true; }
	void		Set_HP(int	_iDmg) { m_iHP -= _iDmg; }
	void		Set_Angle(float _fAngle) { m_fAngle = _fAngle; }

	void		Set_Target(CObj* pTarget) { m_pTarget = pTarget; }
	bool		Get_Dead() { return m_bDead; }
	int			Get_HP() { return m_iHP; }
	int			Get_MaxHP() { return m_iMaxHP; }

	void		Set_ImgKey(const TCHAR* pImgKey) { m_pImgKey = pImgKey; }

	int			Get_TileIdx() { return m_iTileIdx; }
	float		Get_Speed() { return m_fSpeed; }
	void		Set_Speed(float _speed) { m_fSpeed = _speed; }
	void		Set_SpeedReverse() { m_fSpeed *= -1.f; }

public:
	virtual void		Initialize()PURE;
	virtual int			Update()PURE;
	virtual void		Late_Update()PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release()PURE;

public:
	void		Update_Rect();
	void		Move_Frame();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	FRAME		m_tFrame;

	float		m_fSpeed;
	float		m_fAngle;
	float		m_fDistance;

	bool		m_bDead;
	DIRECTION	m_eDir;
	RENDERID	m_eRender;

	CObj*		m_pTarget;

	const TCHAR*		m_pImgKey;

	int			m_iHP;
	int			m_iMaxHP;
	int			m_iArmor;
	int			m_iTileIdx;
};

