#include "pch.h"
#include "CPlayerMoney.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"
#include "CPlayer.h"

void CPlayerMoney::Initialize()
{

    m_tInfo = { (float)WINCX - 100.f, 125.f, 40.f, 40.f };
    m_pImgKey = L"Gold";
	m_iMoney = static_cast<CPlayer*>(GET_PLAYER)->Get_Money();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Gold.bmp", L"Gold");
    m_eRender = RENDER_UI;
}

int CPlayerMoney::Update()
{
	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CPlayerMoney::Late_Update()
{
	m_iMoney = static_cast<CPlayer*>(GET_PLAYER)->Get_Money();

}

void CPlayerMoney::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

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
        RGB(255, 0, 255));


	HFONT hFont = CreateFont(15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, NONANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("NecroSans"));
	HFONT hOldFont = (HFONT)SelectObject(hDC, hFont);

	// �۾� ���� ����
	SetTextColor(hDC, RGB(255, 255, 255));
	SetBkMode(hDC, TRANSPARENT);

    TCHAR szText[32];
    wsprintf(szText, L"x%d", m_iMoney);
    TextOut(hDC, m_tRect.left + 50, m_tRect.top + 10, szText, lstrlen(szText));


	// ��Ʈ ���� �� �ؽ�Ʈ ���� ������� ����
	SelectObject(hDC, hOldFont);
	DeleteObject(hFont);








}

void CPlayerMoney::Release()
{
}
