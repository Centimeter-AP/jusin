#include "pch.h"
#include "CHeartbeat.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "Define.h"
#include "CAbstractFactory.h"
#include "CMissInputText.h"

void CHeartbeat::Initialize()
{
	m_tInfo = { (float)WINCX * 0.5f, (float)WINCY - 145.f, 80.f, 100.f };
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

	if (BEATMGR->Get_InputBeatMissed() == true)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CMissInputText>::Create());
		BEATMGR->Set_InputBeatMissed(false);
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
	HDC		hMemDCskiptext = CBmpMgr::Get_Instance()->Find_Image(L"beatskipped1");	// �׸��� �� xy ��ǥ ����?

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Heartbeat");

	GdiTransparentBlt(hDC,					// ���� ���� DC
		m_tRect.left,			// ���� ���� ��ġ ��ǥ X, Y	
		m_tRect.top,
		(int)m_tInfo.fCX,							// ���� ���� �̹����� ����, ����
		(int)m_tInfo.fCY,
		hMemDC,								// ������ �̹��� DC	
		(int)m_tInfo.fCX * m_iBeat,	// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		0,
		(int)m_tInfo.fCX,							// ������ �̹����� ����, ����
		(int)m_tInfo.fCY,
		RGB(255, 0, 255));					// ������ ����

	TCHAR szText[32];
	wsprintf(szText, L"�޺� ��� : %d��", CBeatMgr::Get_Instance()->Get_BeatCombo() + 1);
	TextOut(hDC, 
			WINCX / 2 - 55, 
			WINCY - 100,
			szText, lstrlen(szText));


	//if (CBeatMgr::Get_Instance()->Get_BeatMissed())
	//{

	//	GdiTransparentBlt(hDC,
	//		m_tRect.left,
	//		m_tRect.top,
	//		77,
	//		15,
	//		hMemDCskiptext,
	//		0,
	//		0,
	//		77,
	//		15,
	//		RGB(255, 0, 255));
	//}


}

void CHeartbeat::Release()
{
}
