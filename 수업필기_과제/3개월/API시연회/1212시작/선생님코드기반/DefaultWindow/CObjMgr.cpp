#include "pch.h"
#include "CObjMgr.h"
#include "CCollisionMgr.h"
#include "CTileMgr.h"
#include "CBeatMgr.h"
#include "CItem.h"
#include "CLeftBar.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}

CObjMgr::~CObjMgr()
{
	Release();
}

CObj* CObjMgr::Get_Target(OBJID eID, CObj* pDst)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj*	pTarget = nullptr;
	float	fDistance(0.f);

	for (auto& Src : m_ObjList[eID])
	{
		if (Src->Get_Dead())
			continue;

		float		fWidth = abs(pDst->Get_Info().fX - Src->Get_Info().fX);
		float		fHeight = abs(pDst->Get_Info().fY - Src->Get_Info().fY);

		float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = Src;
			fDistance = fDiagonal;
		}
	}		

	return pTarget;
}

CObj* CObjMgr::Is_Item_Exist(float fx, float fy)
{

	if (!m_ObjList[OBJ_ITEM].empty())
	{
		auto iter = find_if(m_ObjList[OBJ_ITEM].begin(), m_ObjList[OBJ_ITEM].end(), [fx, fy](CObj* pItem) {return ((pItem->Get_Info().fX == fx) && (pItem->Get_Info().fY - 8 <= fy && pItem->Get_Info().fY >= fy)); });
		// 8.f
		if (iter == m_ObjList[OBJ_ITEM].end())
			return nullptr;
		else
			return (*iter);
	}
	else
		return nullptr;
	//return false;
}
CObj* CObjMgr::Is_Item_Exist(int	_iTileIdx)
{

	if (!m_ObjList[OBJ_ITEM].empty())
	{
		auto iter = find_if(m_ObjList[OBJ_ITEM].begin(), m_ObjList[OBJ_ITEM].end(),
			[_iTileIdx](CObj* pItem) {return (pItem->Get_TileIdx() == _iTileIdx); });		// 8.f
		if (iter == m_ObjList[OBJ_ITEM].end())
			return nullptr;
		else
			return (*iter);
	}
	else
		return nullptr;
	//return false;
}

CObj* CObjMgr::Is_Monster_Exist(float fx, float fy)
{
	if (!m_ObjList[OBJ_MONSTER].empty())
	{
		auto iter = find_if(m_ObjList[OBJ_MONSTER].begin(), m_ObjList[OBJ_MONSTER].end(),
			[fx, fy](CObj* pItem) {return ((pItem->Get_Info().fX == fx) && (pItem->Get_Info().fY == fy)); });
		if (iter == m_ObjList[OBJ_MONSTER].end())
			return nullptr;
		else
			return (*iter);
	}
}

CObj* CObjMgr::Is_Monster_Exist(int	_iTileIdx)
{
	if (!m_ObjList[OBJ_MONSTER].empty())
	{
		auto iter = find_if(m_ObjList[OBJ_MONSTER].begin(), m_ObjList[OBJ_MONSTER].end(),
			[_iTileIdx](CObj* pItem) {return (pItem->Get_TileIdx() == _iTileIdx); });
		if (iter == m_ObjList[OBJ_MONSTER].end())
			return nullptr;
		else
			return (*iter);
	}
}


void CObjMgr::Get_Item(CItem* _pItem)
{

}



void CObjMgr::Add_Object(OBJID eID, CObj* pObj)
{
	if (OBJ_END <= eID || nullptr == pObj)
		return;

	m_ObjList[eID].push_back(pObj);
}

int CObjMgr::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();
			CBeatMgr::Get_Instance()->Update();

			if (OBJ_DEAD == iResult)
			{
				if (dynamic_cast<CLeftBar*>(*iter) != nullptr)
				{
					CBeatMgr::Get_Instance()->Delete_Bar((*iter));
				}
				Safe_Delete<CObj*>(*iter);
				(*iter) = nullptr;
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	return 0;
}

void CObjMgr::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& pObj : m_ObjList[i])
		{
			pObj->Late_Update();

			if (m_ObjList[i].empty())
				break;

			RENDERID	eID = pObj->Get_GroupID();
			m_RenderList[eID].push_back(pObj);
		}
	}
	for (auto& pWall : CTileMgr::Get_Instance()->Get_WallVec())
	{
		m_RenderList[RENDER_GAMEOBJECT].push_back(pWall);
	}
}

void CObjMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < RENDER_END; ++i)
	{
		m_RenderList[i].sort([](CObj* pDst, CObj* pSrc)->bool 
			{ 
				return pDst->Get_Info().fY < pSrc->Get_Info().fY; 
			});

		for (auto& pObj : m_RenderList[i])
			pObj->Render(hDC);

		m_RenderList[i].clear();
	}
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}

void CObjMgr::Delete_ID(OBJID eID)
{
	for (auto& pObj : m_ObjList[eID])
		Safe_Delete(pObj);

	m_ObjList[eID].clear();
}
