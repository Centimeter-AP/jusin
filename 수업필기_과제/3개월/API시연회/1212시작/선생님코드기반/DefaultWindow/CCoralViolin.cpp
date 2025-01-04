#include "pch.h"
#include "CCoralViolin.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"
#include "CSoundMgr.h"



// 해야하는거
// 이거만들어

void CCoralViolin::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 6.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Monster/Boss/.bmp", L"Violin");
    m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
    m_iHeadTileIdx = m_iTileIdx = Find_MyTileIdx();

    m_tInfo.fX = (*m_pvecTile)[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*m_pvecTile)[m_iTileIdx]->Get_Info().fY - 24.f;
    m_pTarget = GET_PLAYER;
    m_eDir = DIR_UP;

    m_tFrame.iFrameStart = 0;
    m_tFrame.iFrameEnd = 3;
    m_tFrame.iMotion = 0;
    m_tFrame.dwSpeed = 100;
    m_tFrame.dwTime = GetTickCount64();

    m_pImgKey = L"Violin";
    m_fJumpPower = 9.5f;
    Get_TileX();
    Get_TileY();
    m_eRender = RENDER_GAMEOBJECT;
    m_iMaxHP = 1;
    m_iHP = 1;
    m_iDamage = 1;

    m_HP_UI.Set_Target(this);
    m_HP_UI.Initialize();
    CObjMgr::Get_Instance()->Add_Object(OBJ_UI, &m_HP_UI);
}

int CCoralViolin::Update()
{
	return 0;
}

void CCoralViolin::Late_Update()
{
}

void CCoralViolin::Render(HDC hDC)
{
}

void CCoralViolin::Release()
{
}
