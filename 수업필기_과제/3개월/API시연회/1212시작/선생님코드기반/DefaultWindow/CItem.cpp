#include "pch.h"
#include "CItem.h"
#include "CPlayer.h"
#include "CScrollMgr.h"

void CItem::Find_TileIdx_OnMap()
{
	m_iTileIdx = ((int)m_tInfo.fY / TILECY) * TILEX + ((int)m_tInfo.fX / TILECX);
}

void CItem::Find_Player_OnSameTile()
{
	if (m_pTarget != nullptr)
	{
		if ((m_pTarget)->Get_TileIdx() == m_iTileIdx)
			m_bIsPlayerOnTile = true;
		else
			m_bIsPlayerOnTile = false;
	}
}


void CItem::Draw_Price(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HFONT hFont = CreateFont(15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, 
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("NecroSans"));
	HFONT hOldFont = (HFONT)SelectObject(hDC, hFont);

	// �۾� ���� ����
	SetTextColor(hDC, RGB(255, 255, 255));
	SetBkMode(hDC, TRANSPARENT);

	// �ؽ�Ʈ ���� ���� (�߾� ����)
	int oldAlign = SetTextAlign(hDC, TA_CENTER);

	// ��ǥ ����
	int x = static_cast<int>(m_tInfo.fX);
	int y = static_cast<int>(m_tInfo.fY + m_tInfo.fCY / 2 - 10);

	// �۾� ���
	TCHAR szText[32];
	wsprintf(szText, L"%d", m_iPrice);
	TextOut(hDC, x + iScrollX, y + iScrollY, szText, lstrlen(szText));

	// ��Ʈ ���� �� �ؽ�Ʈ ���� ������� ����
	SetTextAlign(hDC, oldAlign);
	SelectObject(hDC, hOldFont);
	DeleteObject(hFont);
}
