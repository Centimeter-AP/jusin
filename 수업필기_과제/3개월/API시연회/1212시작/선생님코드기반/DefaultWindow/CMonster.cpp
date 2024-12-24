#include "pch.h"
#include "CMonster.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 48.f;
    m_fSpeed = 3.f;

    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");

    m_iTileIdx = ((int)m_tInfo.fY / TILECY) * TILEX + ((int)m_tInfo.fX / TILECX);
    m_tInfo.fX = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fY - 24.f;
    m_pTarget = GET_PLAYER;

    m_pImgKey = L"Monster";

    m_eRender = RENDER_GAMEOBJECT;
}

int CMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

   
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{

}

void CMonster::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    Rectangle(hDC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);


    //GdiTransparentBlt(hDC,			// ���� ���� DC
    //    m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
    //    m_tRect.top + iScrollY,
    //    (int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
    //    (int)m_tInfo.fCY,
    //    hMemDC,						// ������ �̹��� DC	
    //    0,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
    //    0,
    //    (int)m_tInfo.fCX,			// ������ �̹����� ����, ����
    //    (int)m_tInfo.fCY,
    //    RGB(255, 255, 255));		// ������ ����
}

void CMonster::Release()
{
}
