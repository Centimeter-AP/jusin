#include "pch.h"
#include "CGold.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CObjMgr.h"
#include "CTileMgr.h"
#include "CPlayer.h"
#include "CSoundMgr.h"

void CGold::Initialize()
{
    m_tInfo.fCX = 62.f;
    m_tInfo.fCY = 62.f;
    m_pImgKey = L"GoldHoard";
    m_iPrice = 20;
    // 20, 50, 200
	m_bOnMap = true;
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Item/gold.bmp", L"GoldHoard");
    m_eRender = RENDER_MAPITEM;
    m_eItemType = ITEM_GOLD;
}

int CGold::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
    if (m_iPrice > 0 && m_iPrice <= 20)
    {
        m_tFrame.iFrameStart = 0;
    }
    else if (m_iPrice > 20 && m_iPrice <= 50)
    {
		m_tFrame.iFrameStart = 1;
	}
	else if (m_iPrice > 50)
	{
		m_tFrame.iFrameStart = 2;
	}
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CGold::Late_Update()
{
    if (m_bOnMap)
    {
        Find_TileIdx_OnMap();
        CTileMgr::Get_Instance()->Set_TileObject(m_iTileIdx, TOBJ_ITEM, this);
    }
}

void CGold::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    if (m_bOnMap)
    {
        //if (m_bIsPlayerOnTile == false)
        {
            GdiTransparentBlt(hDC,			// ���� ���� DC
                m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top + iScrollY,
                (int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDC,						// ������ �̹��� DC	
                (int)m_tInfo.fCX * m_tFrame.iFrameStart,					// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,			// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));		// ������ ����

        }
    }
}

void CGold::Release()
{
}
