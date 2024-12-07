#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"
#include "CKeyMgr.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"
#include "CStone.h"
#include "CFireWall.h"
#include "CAnimMgr.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);


	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CStone>::Create());

	 for (int i = 0; i < 30; ++i)
	 {
	 	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(i * 32, 400, 0.f));
	 	CObjMgr::Get_Instance()->Get_LastMonster()->Set_Target(CObjMgr::Get_Instance()->Get_Player());
	 }
	 CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CFireWall>::Create());



	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Back.bmp", L"Back");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");

}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	CAnimMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	CAnimMgr::Get_Instance()->Late_Update();
	CKeyMgr::Get_Instance()->Update();

}


void CMainGame::Render()
{
#pragma region  FPS Ãâ·Â
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
#pragma endregion
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	HDC		hGroundDC = CBmpMgr::Get_Instance()->Find_Image(L"Ground");
	
	BitBlt(hMemDC, 0, 0, WINCX, WINCY, hGroundDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->Render(hMemDC);

	BitBlt(m_hDC,
		0, 0, WINCX, WINCY,
		hMemDC,
		0,
		0,
		SRCCOPY);

}

void CMainGame::Release()
{
	CBmpMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CObjMgr::DestroyInstance();
	ReleaseDC(g_hWnd, m_hDC);
}
