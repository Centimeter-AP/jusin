#include "pch.h"
#include "CTauren.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"
#include "CSoundMgr.h"

void CTauren::Initialize()
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 6.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Monster/MinotaursIdle.bmp", L"MinotaursIdle");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Monster/MinotaursFaint.bmp", L"MinotaursFaint");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Monster/MinotaursCharge.bmp", L"MinotaursCharge");
    m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
    m_iHeadTileIdx = m_iTileIdx = m_iCurTileIdx = Find_MyTileIdx();

    m_tInfo.fX = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fY - 24.f;
    m_pTarget = GET_PLAYER;
    m_eDir = DIR_LEFT;
    m_ePrevDir = DIR_LEFT;

    m_tFrame.iFrameStart = 0;
    m_tFrame.iFrameEnd = 3;
    m_tFrame.iMotion = 0;
    m_tFrame.dwSpeed = 100;
    m_tFrame.dwTime = GetTickCount64();

    m_pImgKey = L"MinotaursIdle";
    m_fJumpPower = 9.5f;
    Get_TileX();
    Get_TileY();
    m_eRender = RENDER_GAMEOBJECT;
    m_iMaxHP = 10;
    m_iHP = 10;
}

int CTauren::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    if (BEATMGR->Get_ObjectAbleToMove() == true)
    {
        if (m_eCurState == IDLE_ACT)
        {
            //BEATMGR->Set_ObjectAbleToMove(false);
            m_eCurState = IDLE_ACT;
            m_iHeadTileIdx = m_iCurTileIdx;
            m_iTileIdx = Find_MyTileIdx();
            m_iBeforeAct = 1;
            return OBJ_NOEVENT;
        }
        else
        {
            m_iBeforeAct = 0;
            m_eCurState = IDLE_ACT;
        }

        m_iTileIdx = Find_MyTileIdx();
        if (m_pTarget != nullptr)
        {
            Find_Player();
        }
        if (Can_Move())
        {
            m_bMove = true;
        }
        else
        {
            m_iHeadTileIdx = m_iCurTileIdx;
        }
        //BEATMGR->Set_ObjectAbleToMove(false);
    }

    Jumping();

    __super::Update_Rect();

    return OBJ_NOEVENT;
	return 0;
}

void CTauren::Late_Update()
{
}

void CTauren::Render(HDC hDC)
{
}

void CTauren::Release()
{
}
