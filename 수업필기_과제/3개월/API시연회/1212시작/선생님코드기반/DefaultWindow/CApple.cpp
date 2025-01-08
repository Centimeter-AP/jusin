#include "pch.h"
#include "CApple.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CObjMgr.h"
#include "CTileMgr.h"
#include "CPlayer.h"
#include "CSoundMgr.h"

void CApple::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 48.f;
    m_pImgKey = L"Apple";
    m_fSpeed = 2.f;
    m_iImgPosX = 0;
    m_iPrice = 50;

    m_tInfo.fX = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fX;
    m_tInfo.fY = (*CTileMgr::Get_Instance()->Get_TileVec())[m_iTileIdx]->Get_Info().fY;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Item/Apple.bmp", L"Apple");
    m_eRender = RENDER_MAPITEM;
    m_eItemType = ITEM_HEAL;
}

int CApple::Update()
{
    if (m_bOnMap)
    {
        Find_Player_OnSameTile();

        //m_eRender = RENDER_MAPITEM;
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
	return 0;
}

void CApple::Late_Update()
{
    if (m_bOnMap)
    {
        Find_TileIdx_OnMap();
        CTileMgr::Get_Instance()->Set_TileObject(m_iTileIdx, TOBJ_ITEM, this);
    }
}

void CApple::Render(HDC hDC)
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
}

void CApple::Release()
{
}

void CApple::Use_Item()
{
	static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Set_HP(-2);
    CSoundMgr::Get_Instance()->StopSound(SOUND_EFFECT);
    CSoundMgr::Get_Instance()->PlaySound(L"sfx_item_food.ogg", SOUND_EFFECT, 1.f);
    
	m_bDead = true;
}
