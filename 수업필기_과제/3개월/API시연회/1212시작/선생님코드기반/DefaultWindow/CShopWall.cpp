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
	m_tInfo.fCX = 48.f;
	m_tInfo.fCY = 72.f;
	m_pImgKey = L"Wall";
	m_eRender = RENDER_GAMEOBJECT;

	// 벽 별로 imgpos 설정
	//m_iImgPosX = 0;
	//m_iImgPosY = 0;
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

	//HDC		hMemDChead = CBmpMgr::Get_Instance()->Find_Image(L"Wall");

	Rectangle(hDC
		, m_tRect.left + iScrollX
		, m_tRect.top + iScrollY - 24
		, m_tRect.right + iScrollX
		, m_tRect.bottom + iScrollY - 24);
}

void CShopWall::Release()
{
}
