#include "pch.h"
#include "CMagicCheese.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CObjMgr.h"
#include "CTileMgr.h"

void CMagicCheese::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 48.f;
    m_pImgKey = L"Cheese";
    m_fSpeed = 2.f;
    m_iImgPosX = 0;
    m_iPrice = 150;

    m_tInfo.fX = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fY - 24.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Item/cheese.bmp", L"Cheese");
    m_eRender = RENDER_MAPITEM;
    m_eItemType = ITEM_HEAL;
}

int CMagicCheese::Update()
{
	return 0;
}

void CMagicCheese::Late_Update()
{
}

void CMagicCheese::Render(HDC hDC)
{
}

void CMagicCheese::Release()
{
}
