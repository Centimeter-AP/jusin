#include "pch.h"
#include "CTitaniumShovel.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CObjMgr.h"
#include "CTileMgr.h"

void CTitaniumShovel::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 78.f;
    m_pImgKey = L"Shovels";
    m_fSpeed = 2.f;
    m_iImgPosX = 48;

    m_iPrice = 200;
    m_tInfo.fX = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fY - 24.f;
    //m_iTileIdx = ((int)m_tInfo.fY / TILECY) * TILEX + ((int)m_tInfo.fX / TILECX);
    m_pTarget = GET_PLAYER;
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Item/Shovels.bmp", L"Shovels");
    m_eRender = RENDER_EFFECT;
    m_iPower = POWER_TWO;
    m_eItemType = ITEM_SHOVEL;
}

int CTitaniumShovel::Update()
{
    if (m_bUsing)
    {
        m_tInfo.fX = m_tInfo.fY = 0.f;
        m_eRender = RENDER_EFFECT;
        Get_RenderPos();
    }
    else if (m_bOnMap)
    {
        Find_Player_OnSameTile();

        m_eRender = RENDER_MAPITEM;
        m_iFrameTicker += (int)m_fSpeed;

        switch (m_iFrameTicker)
        {
        case 20:
        case 40:
        case 60:
        case 80:
            m_iAnimationOffsetY += (int)m_fSpeed;
            break;
        case 0:

        case 100:
            m_fSpeed *= -1.f;
            break;
        default:
            break;
        }
    }

    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CTitaniumShovel::Late_Update()
{
    if (m_bUsing)
    {
        ++m_iFrameTicker;
        if (m_iFrameTicker >= m_iShowFrame)
        {
            m_bUsing = !m_bUsing;
            m_iFrameTicker = 0;
        }
    }
    if (m_bOnMap)
    {
        Find_TileIdx_OnMap();   // ���ֵ� ��� ������?

        CTileMgr::Get_Instance()->Set_TileObject(m_iTileIdx, TOBJ_ITEM, this);

    }
}

void CTitaniumShovel::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
    if (m_bIsSelling)
    {
        Draw_Price(hDC);
    }
    if (m_bOnMap)
    {
        if (m_bIsPlayerOnTile == false)
        {
            GdiTransparentBlt(hDC,			// ���� ���� DC
                m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top + iScrollY + m_iAnimationOffsetY,
                (int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDC,						// ������ �̹��� DC	
                m_iImgPosX,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,			// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));		// ������ ����
        }
    }
    else if (m_bUsing)
    {
        GdiTransparentBlt(hDC,			// ���� ���� DC
            m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
            m_tRect.top - 15 + iScrollY,
            (int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
            (int)m_tInfo.fCY,
            hMemDC,						// ������ �̹��� DC	
            m_iImgPosX,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
            0,
            (int)m_tInfo.fCX,			// ������ �̹����� ����, ����
            (int)m_tInfo.fCY,
            RGB(255, 0, 255));		// ������ ����
    }
    else
        return;
}

void CTitaniumShovel::Release()
{
}
