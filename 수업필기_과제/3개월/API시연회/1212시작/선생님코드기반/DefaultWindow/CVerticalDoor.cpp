#include "pch.h"
#include "CVerticalDoor.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"

void CVerticalDoor::Initialize()
{

	// �� ��� 30px

	m_tInfo.fCX = 48.f;
	m_tInfo.fCY = 78.f;
	m_pImgKey = L"Wall";
	m_eRender = RENDER_GAMEOBJECT;
	m_enWallType = VDOOR_WALL;

	// �� ���� imgpos ����
	m_iImgPosX = 624;
	// 624 ����
	m_iImgPosY = 576;

	m_iHP = 1;
	m_iPowerNeeded = NO_POWER;
}

int CVerticalDoor::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_iTileIdx = Find_MyTileIdx();
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CVerticalDoor::Late_Update()
{

}

void CVerticalDoor::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Wall");

	GdiTransparentBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top - 15 + iScrollY, // �׸��� ���� ������ ����
		TILECX,
		78,
		hMemDC,
		m_iImgPosX,
		m_iImgPosY,
		TILECX,
		78,
		RGB(255, 0, 255));

}

void CVerticalDoor::Release()
{
}
