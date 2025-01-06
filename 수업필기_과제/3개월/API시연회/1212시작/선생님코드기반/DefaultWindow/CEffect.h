#pragma once
#include "CObj.h"
class CEffect : public CObj
{
public:
	CEffect();
	virtual ~CEffect();
public:
	void Initialize() PURE;
	int Update() PURE;
	void Late_Update() PURE;
	void Render(HDC hDC) PURE;
	void Release() PURE;
};

