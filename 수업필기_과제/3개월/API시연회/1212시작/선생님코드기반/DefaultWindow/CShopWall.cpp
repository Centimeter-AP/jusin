#include "pch.h"
#include "CShopWall.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"

CShopWall::CShopWall()
{
}
	
CShopWall::~CShopWall()
{
}

void CShopWall::Initialize()
{

	// 벽 기둥 30px

	m_tInfo.fCX = 48.f;
	m_tInfo.fCY = 78.f;
	m_pImgKey = L"Wall";
	m_eRender = RENDER_GAMEOBJECT;
	m_enWallType = SHOP_WALL;

	// 벽 별로 imgpos 설정
	m_iImgPosX = 0;
	m_iImgPosY = 576;
}

int CShopWall::Update()
{


	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CShopWall::Late_Update()
{

}

void CShopWall::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Wall");

	BitBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top - 15 + iScrollY,
		TILECX,
		78,
		hMemDC,
		m_iImgPosX,
		m_iImgPosY,
		SRCCOPY);


}

void CShopWall::Release()
{
}
