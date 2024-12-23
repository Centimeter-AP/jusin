#include "pch.h"
#include "CLeftBar.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"

void CLeftBar::Initialize()
{
    m_tInfo = { 0.f , (float)WINCY - 70.f, 10.f, 48.f };
    m_pImgKey = L"Beatbar";
    m_fSpeed = 1.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heartbeat.bmp", L"Beatbar");
    m_eRender = RENDER_UI;
}

int CLeftBar::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    m_tInfo.fX += m_fSpeed * 4;



    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CLeftBar::Late_Update()
{
    if (m_fSpeed < 0)
    {
        if (m_tInfo.fX < (float)WINCX * 0.5f - 80.f)
        {
            m_bDead = true;
        }
        //if (m_tInfo.fX >= (float)WINCX * 0.5f - 80.f && m_tInfo.fX <= (float)WINCX * 0.5f + 80.f)
        //{
        //    CBeatMgr::Get_Instance()->Set_AbleBeatInterrval(true);

        //}
        //else
        //{
        //    CBeatMgr::Get_Instance()->Set_AbleBeatInterrval(false);
        //}
    }
    else
    {
        if (m_tInfo.fX > (float)WINCX * 0.5f + 80.f)
        {
            m_bDead = true;
        }
        //if (m_tInfo.fX <= (float)WINCX * 0.5f + 80.f && m_tInfo.fX >= (float)WINCX * 0.5f - 80.f)
        //{
        //    CBeatMgr::Get_Instance()->Set_AbleBeatInterrval(true);

        //}
        //else
        //{
        //    CBeatMgr::Get_Instance()->Set_AbleBeatInterrval(false);
        //}
    }
}

void CLeftBar::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CLeftBar::Release()
{
}
