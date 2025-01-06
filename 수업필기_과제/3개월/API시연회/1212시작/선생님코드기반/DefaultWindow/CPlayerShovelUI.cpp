#include "pch.h"
#include "CPlayerShovelUI.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"
#include "CItem.h"


void CPlayerShovelUI::Initialize()
{
    m_tInfo = { 50.f, 125.f, 60.f, 66.f };
    m_pImgKey = L"Shovels";
    m_pTarget = CObjMgr::Get_Instance()->Get_Player();
    m_pCurShov = static_cast<CPlayer*>(m_pTarget)->Get_CurShovel();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/UI_Shovel.bmp", L"UI_Shovel");
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Half.bmp", L"Heart_Half");
    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heart_Empty.bmp", L"Heart_Empty");
    m_eRender = RENDER_UI;
}

int CPlayerShovelUI::Update()
{
    __super::Update_Rect();
    return OBJ_NOEVENT;
}

void CPlayerShovelUI::Late_Update()
{
    m_pCurShov = static_cast<CPlayer*>(m_pTarget)->Get_CurShovel();

    m_iItemPosX = static_cast<CItem*>(m_pCurShov)->Get_ImgPosX();
}

void CPlayerShovelUI::Render(HDC hDC)
{

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"UI_Shovel");
    HDC		hMemDCCurShov = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

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
        m_tRect.left + 6,			// ���� ���� ��ġ ��ǥ X, Y	
        m_tRect.top + 6,
        48,							// ���� ���� �̹����� ����, ����
        60,
        hMemDCCurShov,								// ������ �̹��� DC	
        m_iItemPosX,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
        0,
        48,							// ������ �̹����� ����, ����
        60,
        RGB(255, 0, 255));					// ������ ����

}

void CPlayerShovelUI::Release()
{
}
