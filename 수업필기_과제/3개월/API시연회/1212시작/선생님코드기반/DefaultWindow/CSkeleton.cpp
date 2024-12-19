#include "pch.h"
#include "CSkeleton.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CBeatMgr.h"

void CSkeleton::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 3.f;

    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");

    m_iTileIdx = ((int)m_tInfo.fY / TILECY) * TILEX + ((int)m_tInfo.fX / TILECX);
    m_tInfo.fX = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fY - 24.f;

    m_pImgKey = L"Monster";

    m_eRender = RENDER_GAMEOBJECT;
}

int CSkeleton::Update()
{
    if (m_bDead)
        return OBJ_DEAD;
    if (CBeatMgr::Get_Instance()->Get_PlayerActed() || CBeatMgr::Get_Instance()->Get_BeatMissed())
    {
        if (m_eCurState == AFTER_JUMP)
            m_eCurState = BEFORE_JUMP;
        else
            m_eCurState = AFTER_JUMP;
    }
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CSkeleton::Late_Update()
{
    switch (m_eCurState)
    {
    case CSkeleton::BEFORE_JUMP:

        break;
    case CSkeleton::AFTER_JUMP:

        break;
    default:
        break;
    }

    
}

void CSkeleton::Render(HDC hDC)
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

void CSkeleton::Release()
{
}
