#include "pch.h"
#include "CPlayerHP.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"

void CPlayerHP::Initialize()
{
    m_tInfo = { (float)WINCX - 70.f, 70.f, 48.f, 48.f };
    m_pImgKey = L"PlayerHP";
    m_iHP = CObjMgr::Get_Instance()->Get_Player()->Get_HP();
    m_iMaxHP = CObjMgr::Get_Instance()->Get_Player()->Get_MaxHP();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heartbeat.bmp", L"Heartbeat");
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
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"PlayerHP");

    if (m_iHP % 2)
    {
        int iLessHP = m_iMaxHP - m_iHP;
        for (int i = 0; i < iLessHP / 2; ++i)
        {
            Rectangle(hDC, m_tRect.left - 50.f * i, m_tRect.top,
                           m_tRect.right - 50.f * i, m_tRect.bottom);
        }
        Rectangle(hDC, m_tRect.left - 50.f * iLessHP / 2, m_tRect.top, m_tRect.right - 50.f * iLessHP / 2, m_tRect.bottom);
        for (int i = iLessHP / 2 + 1; i < m_iHP / 2; ++i)
        {
            Rectangle(hDC, m_tRect.left - 50.f * i,  m_tRect.top,
                            m_tRect.right - 50.f * i, m_tRect.bottom);
        }
    }
    else
    {
        for (int i = 0; i < m_iMaxHP / 2; ++i)
        {
            Rectangle(hDC, m_tRect.left - 50.f * i, m_tRect.top,
                m_tRect.right - 50.f * i, m_tRect.bottom);
        }
    }
}

void CPlayerHP::Release()
{
}
