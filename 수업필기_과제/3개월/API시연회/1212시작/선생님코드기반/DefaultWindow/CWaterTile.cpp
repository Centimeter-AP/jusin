#include "pch.h"
#include "CWaterTile.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"
#include "CObjMgr.h"

CWaterTile::CWaterTile()
{
}

CWaterTile::~CWaterTile()
{
}

void CWaterTile::Initialize()
{
    m_tInfo.fCX = TILECX;
    m_tInfo.fCY = TILECY;
    m_pImgKey = L"WaterTile";
    m_eRender = RENDER_BACKGROUND;
    m_iTileIdx = Find_MyTileIdx();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile_Water.bmp", L"WaterTile");
}

int CWaterTile::Update()
{
    if (m_bDead)
    {
        return OBJ_DEAD;
    }

	auto pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
	for (auto& pTile : (*pvecTile))
	{
		if (pTile->Get_TileIdx() == m_iTileIdx)
		{
			m_iDrawID = static_cast<CTile*>(pTile)->Get_DrawID();
		}
	}

	__super::Update_Rect();

    return OBJ_NOEVENT;
}

void CWaterTile::Late_Update()
{
}

void CWaterTile::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	BitBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		TILECX,
		TILECY,
		hMemDC,
		52 * m_iDrawID + 2,
		2,
		SRCCOPY);
}

void CWaterTile::Release()
{
}
