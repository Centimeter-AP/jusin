#include "pch.h"
#include "CBedrock.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"

CBedrock::CBedrock()
{
}

CBedrock::~CBedrock()
{
}

void CBedrock::Initialize()
{

	// �� ��� 30px

	m_tInfo.fCX = 48.f;
	m_tInfo.fCY = 78.f;
	m_pImgKey = L"Wall";
	m_eRender = RENDER_GAMEOBJECT;
	m_enWallType = BEDROCK;

	// �� ���� imgpos ����
	m_iImgPosX = 192;
	m_iImgPosY = 576;


	m_iHP = 999;
	m_iPowerNeeded = POWER_NOEXCEPTION;
}

int CBedrock::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CBedrock::Late_Update()
{

}

void CBedrock::Render(HDC hDC)
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

void CBedrock::Release()
{
}
