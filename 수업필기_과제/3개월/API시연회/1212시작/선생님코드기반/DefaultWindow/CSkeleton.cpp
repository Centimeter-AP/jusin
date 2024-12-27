#include "pch.h"
#include "CSkeleton.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"
#include "CSoundMgr.h"

void CSkeleton::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 48.f;
    m_fSpeed = 6.f;

    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");
    m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
    m_iHeadTileIdx = m_iTileIdx = m_iCurTileIdx = Find_MyTileIdx();

    m_tInfo.fX = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fY - 24.f;
    m_pTarget = GET_PLAYER;
    m_eDir = DIR_UP;

    m_pImgKey = L"Monster";
    m_fJumpPower = 9.5f;
    Get_TileX();
    Get_TileY();
    m_eRender = RENDER_GAMEOBJECT;
    m_iMaxHP = 6;
    m_iHP = 6;
}

int CSkeleton::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    if (BEATMGR->Get_ObjectAbleToMove() == true)
    {
        if (m_eCurState == AFTER_ACT)
            m_eCurState = BEFORE_ACT;
        else
            m_eCurState = AFTER_ACT;

        m_iTileIdx = Find_MyTileIdx();
        if (m_pTarget != nullptr)
        {
            Find_Player();
        }
        if (Can_Move())
            m_bMove = true;
        else
            m_iHeadTileIdx = m_iCurTileIdx;
        BEATMGR->Set_ObjectAbleToMove(false);
    }

    Jumping();

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CSkeleton::Late_Update()
{
    switch (m_eCurState)
    {
    case CSkeleton::BEFORE_ACT:

        break;
    case CSkeleton::AFTER_ACT:

        break;
    default:
        break;
    }
    __super::Move_Frame();

}

void CSkeleton::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    Rectangle(hDC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);


    //GdiTransparentBlt(hDC,			// 복사 받을 DC
    //    m_tRect.left + iScrollX,	// 복사 받을 위치 좌표 X, Y	
    //    m_tRect.top + iScrollY,
    //    (int)m_tInfo.fCX,			// 복사 받을 이미지의 가로, 세로
    //    (int)m_tInfo.fCY,
    //    hMemDC,						// 복사할 이미지 DC	
    //    0,							// 비트맵 출력 시작 좌표(Left, top)
    //    0,
    //    (int)m_tInfo.fCX,			// 복사할 이미지의 가로, 세로
    //    (int)m_tInfo.fCY,
    //    RGB(255, 255, 255));		// 제거할 색상 
}

void CSkeleton::Release()
{
}
