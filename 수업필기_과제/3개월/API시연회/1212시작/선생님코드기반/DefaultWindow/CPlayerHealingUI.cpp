#include "pch.h"
#include "CPlayerHealingUI.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"
#include "CItem.h"

void CPlayerHealingUI::Initialize()
{
    m_tInfo = { 50.f, 195.f, 60.f, 66.f };
    m_pImgKey = L"UI_Healing";
    m_pTarget = CObjMgr::Get_Instance()->Get_Player();
    m_pCurHealingItem = nullptr;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/UI_Healing.bmp", L"UI_Healing");
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Half.bmp", L"Heart_Half");
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Empty.bmp", L"Heart_Empty");
    m_eRender = RENDER_UI;
}

int CPlayerHealingUI::Update()
{
    __super::Update_Rect();

    return 0;
}

void CPlayerHealingUI::Late_Update()
{
    m_pCurHealingItem = static_cast<CPlayer*>(m_pTarget)->Get_CurHealing();
    if (m_pCurHealingItem == nullptr)
        m_bHasItem = false;
    else
    {
        m_bHasItem = true;
        m_pImgKey = static_cast<CItem*>(m_pCurHealingItem)->Get_ImgKey();
    }
}

void CPlayerHealingUI::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_Healing");
    //switch (m_eItemName)
    //{
    //case CPlayerHealingUI::NORMALCHEESE:
    //    m_pImgKey = L"Apple";
    //    break;
    //case CPlayerHealingUI::MAGICCHEESE:
    //    m_pImgKey = L"MagicCheese";
    //    break;
    //default:
    //    break;
    //}
    HDC		hMemDCCur = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    if (m_bHasItem)
    {
        GdiTransparentBlt(hDC,					// ���� ���� DC
            m_tRect.left,			// ���� ���� ��ġ ��ǥ X, Y	
            m_tRect.top,
            (int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
            (int)m_tInfo.fCY,
            hMemDC,								// ������ �̹��� DC	
            0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
            0,
            (int)m_tInfo.fCX,							// ������ �̹����� ����, ����
            (int)m_tInfo.fCY,
            RGB(255, 0, 255));					// ������ ����

        GdiTransparentBlt(hDC,					// ���� ���� DC
            m_tRect.left + 6,		// ���� ���� ��ġ ��ǥ X, Y	
            m_tRect.top + 10,
            48,							// ���� ���� �̹����� ����, ����
            48,
            hMemDCCur,								// ������ �̹��� DC	
            0,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
            0,
            48,							// ������ �̹����� ����, ����
            48,
            RGB(255, 0, 255));					// ������ ����
    }

}

void CPlayerHealingUI::Release()
{
}
