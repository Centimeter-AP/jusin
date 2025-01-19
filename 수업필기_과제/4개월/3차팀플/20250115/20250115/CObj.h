#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

	void Initialize_OriginPoint(const int& _iCount, const int& _Radius, const float& _fStartAngle = 0.f);

public:
	INFO		Get_Info() { return m_tInfo; }


public:
	virtual void		Initialize()PURE;
	virtual void		Update()PURE;
	virtual void		Late_Update()PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release()PURE;


protected:
	INFO		m_tInfo;

	vector<D3DXVECTOR3> m_vOriginPointvec;
	vector<D3DXVECTOR3> m_vPointvec;

	float		m_fSpeed;
	float		m_fRadius;
	POINT*		m_pRenderPoint;
};

