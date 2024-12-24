#include "pch.h"
#include "CHeartbeat.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"

void CHeartbeat::Initialize()
{
	m_tInfo = { (float)WINCX * 0.5f, (float)WINCY - 70.f, 80.f, 100.f };
    m_pImgKey = L"Heartbeat";

	

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Heartbeat.bmp", L"Heartbeat");
    m_eRender = RENDER_UI;
}

int CHeartbeat::Update()
{


	if (CBeatMgr::Get_Instance()->Get_RightTimeBeat())
	{
		if (m_iBeat == 0)
		{
			m_iBeat = 1;
		}
	}
	else
	{
		m_iBeat = 0;
	}


	__super::Update_Rect();
    return OBJ_NOEVENT;
}

void CHeartbeat::Late_Update()
{
}

void CHeartbeat::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Heartbeat");

	GdiTransparentBlt(hDC,					// ���� ���� DC
		m_tRect.left,			// ���� ���� ��ġ ��ǥ X, Y	
		m_tRect.top,
		m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
		m_tInfo.fCY,
		hMemDC,								// ������ �̹��� DC	
		m_tInfo.fCX * m_iBeat,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		0,
		m_tInfo.fCX,							// ������ �̹����� ����, ����
		m_tInfo.fCY,
		RGB(255, 0, 255));					// ������ ����
}

void CHeartbeat::Release()
{
}
