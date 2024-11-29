#include "pch.h"
#include "CollisionMgr.h"

void CCollisionMgr::Coll_Ellipse_Check(list<CObj*> _Dst, list<CObj*> _Src, HDC&	m_hdc)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			float fDistance = sqrt(SQUARE(Src->Get_Info().fX - Dst->Get_Info().fX) + SQUARE(Src->Get_Info().fY - Dst->Get_Info().fY));
			if (fDistance < (Dst->Get_Info().fCX + Src->Get_Info().fCY) * 0.5f)
			{
				
			}
		}
	}
}
