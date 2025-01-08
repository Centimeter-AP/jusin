#include "pch.h"
#include "CPlayerHP.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"

void CPlayerHP::Initialize()
{
    m_tInfo = { (float)WINCX - 150.f, 125.f, 48.f, 44.f };
    //m_pImgKey = L"Heart_Full";
    m_iHP = CObjMgr::Get_Instance()->Get_Player()->Get_HP();
    m_iMaxHP = CObjMgr::Get_Instance()->Get_Player()->Get_MaxHP();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Full.bmp", L"Heart_Full");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Half.bmp", L"Heart_Half");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Empty.bmp", L"Heart_Empty");
    m_eRender = RENDER_UI;

}

int CPlayerHP::Update()
{
  
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayerHP::Late_Update()
{
    m_iMaxHP = CObjMgr::Get_Instance()->Get_Player()->Get_MaxHP();
    m_iHP = CObjMgr::Get_Instance()->Get_Player()->Get_HP();

}

void CPlayerHP::Render(HDC hDC)
{
    HDC		hMemDCFull = CBmpMgr::Get_Instance()->Find_Image(L"Heart_Full");
    HDC		hMemDCHalf = CBmpMgr::Get_Instance()->Find_Image(L"Heart_Half");
    HDC		hMemDCEmpty = CBmpMgr::Get_Instance()->Find_Image(L"Heart_Empty");

    int iLessHP = m_iMaxHP - m_iHP;
    if (m_iHP % 2 == 1)
    {
        for (int i = 0; i < iLessHP / 2; ++i)
        {
            GdiTransparentBlt(hDC,					// ���� ���� DC
                m_tRect.left - 50 * i,			// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top,
                (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDCEmpty,								// ������ �̹��� DC	
                0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));					// ������ ����
            if (i + 1 == iLessHP / 2)
            {
                m_tRect.left -= 50 * (i + 1);
            }
        }
        GdiTransparentBlt(hDC,					// ���� ���� DC
            m_tRect.left,			// ���� ���� ��ġ ��ǥ X, Y	
            m_tRect.top,
            (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
            (int)m_tInfo.fCY,
            hMemDCHalf,								// ������ �̹��� DC	
            0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
            0,
            (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
            (int)m_tInfo.fCY,
            RGB(255, 0, 255));
        m_tRect.left -= 50;
        for (int i = 0; i < (m_iMaxHP - iLessHP) / 2; ++i)
        {
            GdiTransparentBlt(hDC,					// ���� ���� DC
                m_tRect.left - 50 * i,			// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top,
                (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDCFull,								// ������ �̹��� DC	
                0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));					// ������ ����
        }
    }
    else
    {
        for (int i = 0; i < iLessHP / 2; ++i)
        {
            GdiTransparentBlt(hDC,					// ���� ���� DC
                m_tRect.left - 50 * i,			// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top,
                (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDCEmpty,								// ������ �̹��� DC	
                0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));					// ������ ����
            if (i + 1 == iLessHP / 2)
            {
                m_tRect.left -= 50 * (i + 1);
            }
        }
        for (int i = 0; i < (m_iMaxHP - iLessHP) / 2; ++i)
        {
            GdiTransparentBlt(hDC,					// ���� ���� DC
                m_tRect.left - 50 * i,			// ���� ���� ��ġ ��ǥ X, Y	
                m_tRect.top,
                (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
                (int)m_tInfo.fCY,
                hMemDCFull,								// ������ �̹��� DC	
                0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
                0,
                (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
                (int)m_tInfo.fCY,
                RGB(255, 0, 255));					// ������ ����
        }
    }





    //if (m_iHP % 2)
    //{
    //    int iLessHP = m_iMaxHP - m_iHP;
    //    for (int i = 0; i < iLessHP / 2; ++i)
    //    {
    //        Rectangle(hDC, m_tRect.left - 50.f * i, m_tRect.top,
    //                       m_tRect.right - 50.f * i, m_tRect.bottom);
    //    }
    //    Rectangle(hDC, m_tRect.left - 50.f * iLessHP / 2, m_tRect.top, m_tRect.right - 50.f * iLessHP / 2, m_tRect.bottom);
    //    for (int i = iLessHP / 2 + 1; i < m_iHP / 2; ++i)
    //    {
    //        Rectangle(hDC, m_tRect.left - 50.f * i,  m_tRect.top,
    //                        m_tRect.right - 50.f * i, m_tRect.bottom);
    //    }
    //}
    //else
    //{
    //    for (int i = 0; i < m_iMaxHP / 2; ++i)
    //    {
    //        //Rectangle(hDC, m_tRect.left - 50.f * i, m_tRect.top,
    //        //    m_tRect.right - 50.f * i, m_tRect.bottom);

    //        GdiTransparentBlt(hDC,					// ���� ���� DC
    //            m_tRect.left - 50.f * i,			// ���� ���� ��ġ ��ǥ X, Y	
    //            m_tRect.top,
    //            m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
    //            m_tInfo.fCY,
    //            hMemDCFull,								// ������ �̹��� DC	
    //            0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
    //            0,
    //            m_tInfo.fCX,							// ������ �̹����� ����, ����
    //            m_tInfo.fCY,
    //            RGB(255, 0, 255));					// ������ ����
    //    }
    //}

    //int health = playerHealth; 
    //for (int i = 0; i < MAX_HEALTH / 2; i++) 
    //{ 
    //    int iconX = x - (i * ICON_SIZE); 
    //    if (health >= 2) 
    //    {
    //        graphics.DrawImage(fullHealthImage, iconX, y, ICON_SIZE, ICON_SIZE);
    //        health -= 2; 
    //    } 
    //    else if (health == 1) 
    //    { 
    //        graphics.DrawImage(halfHealthImage, iconX, y, ICON_SIZE, ICON_SIZE);
    //        health -= 1; 
    //    } 
    //    else 
    //    {
    //        graphics.DrawImage(emptyHealthImage, iconX, y, ICON_SIZE, ICON_SIZE);
    //    } 
    //}

}

void CPlayerHP::Release()
{
}
