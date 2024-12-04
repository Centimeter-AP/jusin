#pragma once
#include "Obj.h"
#include "Define.h"

class CCollisionMgr
{
public:
	static void	Collision_Circle(list<CObj*> _Dst, list<CObj*> _Src);
	static bool	Check_Circle(CObj* _Dst, CObj* _Src);

};

