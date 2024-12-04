#include "pch.h"
#include "CMainGame.h"
#include "CAbstractFactory.h"
#include "CCollisionMgr.h"
#include "CObjMgr.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount()), m_iFPS(0), m_LinePos{ { 100 , WINCY - 100 }, {300,WINCY - 100},{500,WINCY - 300},{700,WINCY - 300} }
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

	for (int i = 0; i < 7; ++i)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(rand() % WINCX, rand() % WINCY, 0.f));
		CObjMgr::Get_Instance()->Get_LastMonster()->Set_Target(CObjMgr::Get_Instance()->Get_Player());
	}
}

void CMainGame::Update()
{

	CObjMgr::Get_Instance()->Update();
	

}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}


void CMainGame::Render()
{
#pragma region  FPS ���
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
#pragma endregion
	
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	MoveToEx(m_hDC, m_LinePos[0].x, m_LinePos[0].y, nullptr);
	LineTo(m_hDC, m_LinePos[1].x,  m_LinePos[1].y);
	LineTo(m_hDC, m_LinePos[2].x,  m_LinePos[2].y);
	LineTo(m_hDC, m_LinePos[3].x,  m_LinePos[3].y);
	CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{

	CObjMgr::DestroyInstance();

	ReleaseDC(g_hWnd, m_hDC);
}
