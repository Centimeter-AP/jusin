#include "pch.h"
#include "CCollisionMgr.h"
#include "CKeyMgr.h"
#include "CStone.h"

void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT rc{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::Collision_Circle(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT rc{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Circle(Dst, Src))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::Check_Circle(CObj* _Dst, CObj* _Src)
{
	float fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	float fWidth  = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float fHeight = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	return fRadius >= fDiagonal;
}

void CCollisionMgr::Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src)
{
	float	fX(0.f), fY(0.f);

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Rect(Dst, Src, &fX, &fY))
			{
				// 상 하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if (Dst->Get_Info().fY < Src->Get_Info().fY)
					{
						Dst->Set_PosY(-fY);
					}
					// 하 충돌
					else
					{
						Dst->Set_PosY(+fY);
					}
				}
				
				// 좌 우 충돌
				else
				{
					// 좌 충돌
					if (Dst->Get_Info().fX < Src->Get_Info().fX)
					{
						Dst->Set_PosX(-fX);
					}
					// 우 충돌
					else
					{
						Dst->Set_PosX(fX);
					}
				}
			}
		}
	}
}

bool CCollisionMgr::Check_Rect(CObj* _Dst, CObj* _Src, float* pX, float* pY)
{

	float		fX = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float		fY = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float		fRadiusX = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;
	float		fRadiusY = (_Dst->Get_Info().fCY + _Src->Get_Info().fCY) * 0.5f;

	if ((fRadiusX >= fX) && (fRadiusY >= fY))
	{
		*pX = fRadiusX - fX;
		*pY = fRadiusY - fY;
		return true;
	}

	return false;
}

// Src가 player
bool CCollisionMgr::Check_Near(CObj* _Dst, CObj* _Player, float* pX, float* pY)
{
	float		fOffsetX = 10.f;
	float		fOffsetY = 0.f;
	float		fX = abs(_Dst->Get_Info().fX - _Player->Get_Info().fX);
	float		fY = abs(_Dst->Get_Info().fY - _Player->Get_Info().fY);

	float		fRadiusX = (_Dst->Get_Info().fCX + _Player->Get_Info().fCX) * 0.5f;
	float		fRadiusY = (_Dst->Get_Info().fCY) * 0.5f;

	if ((fRadiusX + fOffsetX >= fX) && (fRadiusY >= fY))
	{
		if (((_Dst->Get_Info().fX < _Player->Get_Info().fX) && (_Player->Get_Direction() == DIR_LEFT)) ||
			((_Dst->Get_Info().fX > _Player->Get_Info().fX) && (_Player->Get_Direction() == DIR_RIGHT)))
			return true;
	}
	return false;
}

bool CCollisionMgr::Collision_RectNear(list<CObj*> _Dst, list<CObj*> _Src)
{
	float	fX(0.f), fY(0.f);

	for (auto& Dst : _Dst)
	{
		for (auto& Pl : _Src)
		{
			// 근접한지 체크
			if (Check_Near(Dst, Pl, &fX, &fY))
			{
				// 플레이어의 무기가 SUPERARM(GUTSMAN)이고 들어온 Obstacle이 Pebble일 경우
				if (/*(Pl->Get_Bullet()) &&*/ (nullptr != dynamic_cast<CStone*>(Dst)))
				{
					// 이 모든!!! 조건을 만족하고 있을 때 상호작용키(공격키?)를 누르면
					if (CKeyMgr::Get_Instance()->Key_Down('E'))
					{
						// Pebble삭제 후 
						Dst->Set_Dead();
						// player에 pebble bullet 추가
						// Pl->Set_Bullet(SUPERARM?)
					}
				}
				return true;
			}
		}
	}
	return false;
}
