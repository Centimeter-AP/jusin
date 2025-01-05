#include "pch.h"
#include "CCoralBrass.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"
#include "CSoundMgr.h"


void CCoralBrass::Initialize()
{
    //드럼 82 110
//본체 86 120
//호른 72 116 46
//키보드 52 110 
    m_iImgCX = 72.f;
    m_iImgCY = 116.f;
    m_tInfo.fCX = 72.f;
    m_tInfo.fCY = 48.f;
    m_fSpeed = 6.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Monster/Boss/coralriff_horns.bmp", L"Brass");
    m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
    m_iHeadTileIdx = m_iTileIdx = Find_MyTileIdx();
    CTileMgr::Get_Instance()->Set_TileObject(m_iHeadTileIdx, TOBJ_ENTITY, this);

    m_tInfo.fX = (*m_pvecTile)[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*m_pvecTile)[m_iTileIdx]->Get_Info().fY;
    m_pTarget = GET_PLAYER;
    m_eDir = DIR_UP;

    m_tFrame.iFrameStart = 0;
    m_tFrame.iFrameEnd = 3;
    m_tFrame.iMotion = 0;
    m_tFrame.dwSpeed = 100;
    m_tFrame.dwTime = GetTickCount64();

    m_pImgKey = L"Brass";
    m_fJumpPower = 9.5f;
    Get_TileX();
    Get_TileY();
    m_eRender = RENDER_GAMEOBJECT;
    m_iMaxHP = 1;
    m_iHP = 1;
    m_iDamage = 2;

    m_HP_UI.Set_Target(this);
    m_HP_UI.Initialize();
    CObjMgr::Get_Instance()->Add_Object(OBJ_UI, &m_HP_UI);
}

int CCoralBrass::Update()
{
    if (m_bDead || m_iHP == 0)
    {
        CBeatMgr::Get_Instance()->Plus_BeatCombo();

        CSoundMgr::Get_Instance()->ChangeChannelVolume(SOUND_BOSS2, -0.1f);
        return OBJ_DEAD;
    }

    m_iTileIdx = Find_MyTileIdx();



    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CCoralBrass::Late_Update()
{
    __super::Move_Frame();
}

void CCoralBrass::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    //Rectangle(hDC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);

    GdiTransparentBlt(hDC,
        m_tRect.left - 10 + iScrollX,
        m_tRect.bottom - m_iImgCY + iScrollY,
        m_iImgCX,
        m_iImgCY,
        hMemDC,
        m_iImgCX * m_tFrame.iFrameStart,
        m_iImgCY * m_tFrame.iMotion,
        m_iImgCX,
        m_iImgCY,
        RGB(255, 0, 255));

    m_HP_UI.Render(hDC);
}

void CCoralBrass::Release()
{
    CObjMgr::Get_Instance()->Delete_Object(OBJ_UI, &m_HP_UI);
}
