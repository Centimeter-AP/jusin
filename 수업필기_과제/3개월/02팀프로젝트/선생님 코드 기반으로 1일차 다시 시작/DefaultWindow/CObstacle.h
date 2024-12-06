#pragma once
#include "CObj.h"
#include "Define.h"
class CObstacle : public CObj
{
public:
	CObstacle() {}
	~CObstacle() {}
public:
	void Initialize() PURE;
	int Update() PURE;
	void Late_Update() PURE;
	void Render(HDC hDC) PURE;
	void Release() PURE;
};

