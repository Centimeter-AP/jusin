#include "pch.h"
#include "CPlayerArmorUI.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"
#include "CItem.h"

void CPlayerArmorUI::Initialize()
{
    m_tInfo = { 190.f, 125.f, 60.f, 66.f };
    m_pImgKey = L"armorgi";
    m_pTarget = CObjMgr::Get_Instance()->Get_Player();
    m_pCurArmor = nullptr;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/UI_Armor.bmp", L"UI_Armor");
    m_eRender = RENDER_UI;
}

int CPlayerArmorUI::Update()
{
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayerArmorUI::Late_Update()
{
    m_pCurArmor = static_cast<CPlayer*>(m_pTarget)->Get_CurArmor();

    if (m_pCurArmor == nullptr)
        m_bHasItem = false;
    else
        m_bHasItem = true;
}

void CPlayerArmorUI::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_Armor");
    HDC		hMemDCCur = CBmpMgr::Get_Instance()->Find_Image(L"armor_gi");

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
            m_tRect.top + 14,
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

void CPlayerArmorUI::Release()
{
}
