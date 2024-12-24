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

	GdiTransparentBlt(hDC,					// 복사 받을 DC
		m_tRect.left,			// 복사 받을 위치 좌표 X, Y	
		m_tRect.top,
		m_tInfo.fCX,							// 복사 받을 이미지의 가로, 세로
		m_tInfo.fCY,
		hMemDC,								// 복사할 이미지 DC	
		m_tInfo.fCX * m_iBeat,	// 비트맵 출력 시작 좌표(Left, top)
		0,
		m_tInfo.fCX,							// 복사할 이미지의 가로, 세로
		m_tInfo.fCY,
		RGB(255, 0, 255));					// 제거할 색상
}

void CHeartbeat::Release()
{
}
