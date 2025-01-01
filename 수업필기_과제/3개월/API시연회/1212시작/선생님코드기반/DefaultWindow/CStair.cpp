#include "pch.h"
#include "CStair.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"
#include "CObjMgr.h"

void CStair::Initialize()
{
    m_tInfo.fCX = TILECX;
    m_tInfo.fCY = TILECY;
	m_pImgKey = L"Stair";
	m_eRender = RENDER_GAMEOBJECT;
    m_iTileIdx = Find_MyTileIdx();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile_Stair.bmp", L"Stair");

}

int CStair::Update()
{
	if (GET_PLAYER->Get_TileIdx() == m_iTileIdx)
	{
		Interact_Stair();
		return OBJ_NEXTSCENE;
	}

	__super::Update_Rect();
	//m_iIsClosed = 1;
    return OBJ_NOEVENT;
}

void CStair::Late_Update()
{
}

void CStair::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
    //Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	BitBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		TILECX,
		TILECY,
		hMemDC,
		52 * m_iIsClosed + 2,
		2,
		SRCCOPY);
}

void CStair::Release()
{
}

void CStair::Interact_Stair()
{
	CSceneMgr::Get_Instance()->Set_Scene(m_iNextScene);
}
