#pragma once

#include "CObj.h"
#include "CAnimation.h"
#include "CBmpMgr.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {};

public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObj* Create(float _fX, float _fY, float _fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Angle(_fAngle);

		return pObj;
	}
	static CObj* Create(float _fX, float _fY, float _fCX, float _fCY, float _fAngle)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);
		pObj->Set_Angle(_fAngle);

		return pObj;
	}

	static CAnimation* Create(CObj* _Target, FPOINT _tSize, int _iDuration, int _iMaxFrame, const TCHAR* _ImgKey)
	{
		CAnimation* pAnim = new T;
		pAnim->Initialize();
		pAnim->Set_hMemDC(CBmpMgr::Get_Instance()->Find_Image(_ImgKey));
		pAnim->Set_Target(_Target);
		pAnim->Set_Vector(ANINFO({ 0.f,0.f }
			, { _Target->Get_Info().fX,_Target->Get_Info().fY }
			, _tSize
			, _Target->Get_Info()
			, _iDuration
			, _iMaxFrame
		));

		return pAnim;
	}
};

