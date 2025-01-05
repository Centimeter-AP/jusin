#include "pch.h"
#include "CTile.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"

CTile::CTile() : m_iDrawID(0), m_iOption(0), m_pObject{0,}
{
}

CTile::~CTile()
{
	Release();
}

void CTile::Initialize()
{
	m_tInfo.fCX = TILECX;
	m_tInfo.fCY = TILECY;

	m_pImgKey = L"Tile";
	m_eRender = RENDER_BACKGROUND;

}

int CTile::Update()
{
	m_iTileIdx = Find_MyTileIdx();
	if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_BOSS)
	{
		m_pImgKey = L"Tile_Boss";
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTile::Late_Update()
{
	for (int i = 0; i < TOBJ_END; ++i)
	{
		if (m_pObject[i] != nullptr)
		{
			if (m_pObject[i]->Get_TileIdx() != this->Get_TileIdx())
			{
				m_pObject[i] = nullptr;
			}
		}
	}
}

void CTile::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	
	int		iBeatCorrect(0);
	iBeatCorrect = (CBeatMgr::Get_Instance()->Get_BeatCombo() ? 1 : 0);

	//GdiTransparentBlt(hDC,			// 복사 받을 DC
	//	m_tRect.left + iScrollX,	// 복사 받을 위치 좌표 X, Y	
	//	m_tRect.top + iScrollY,
	//	TILECX,						// 복사 받을 이미지의 가로, 세로
	//	TILECY,
	//	hMemDC,						// 복사할 이미지 DC	
	//	52 * m_iDrawID + 2,			// 비트맵 출력 시작 좌표(Left, top)
	//	52 * 0 + 2,					// 타일 크기가 상하좌우 2픽셀씩 더 있
	//	TILECX,						// 복사할 이미지의 가로, 세로
	//	TILECY,
	//	RGB(255, 0, 255));			// 제거할 색상

	BitBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top  + iScrollY,
		TILECX,
		TILECY,
		hMemDC,
		52 * m_iDrawID + 2,
		52 * iBeatCorrect + 2 ,
		SRCCOPY);

}

void CTile::Release()
{
}
