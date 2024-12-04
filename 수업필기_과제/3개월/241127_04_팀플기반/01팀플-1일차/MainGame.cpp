#include "pch.h"
#include "MainGame.h"
#include "AbFactory.h"
#include "Player.h"
#include "Monster.h"
#include "SubPlayer.h"
#include "CollisionMgr.h"

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);
	
	m_ObjList[OBJ_PLAYER].push_back(CAbFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_SubPlayer(&m_ObjList[OBJ_SUBPLAYER]);
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_RotBullet(&m_ObjList[OBJ_ROTBULLET]);
	m_ObjList[OBJ_SUBPLAYER].push_back(CAbFactory<CSubPlayer>::Create());
	m_ObjList[OBJ_SUBPLAYER].front()->Initialize();
	m_ObjList[OBJ_MONSTER].push_back(CAbFactory<CMonster>::Create());
}

void CMainGame::Update()
{

	//for 문: list배열 0 - obj_end / 배열내부list iter - end()
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			if (STAT_DEAD == (*iter)->Update())
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
	if (GetAsyncKeyState(VK_LSHIFT))
	{
		m_ObjList[OBJ_SUBPLAYER].push_back(CAbFactory<CSubPlayer>::Create());
		m_ObjList[OBJ_SUBPLAYER].front()->Initialize();
	}
}

void CMainGame::Late_Update()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& obj : m_ObjList[i])
			obj->Late_Update();
	}
	if (rand() % 1000 < 10)
		m_ObjList[OBJ_MONSTER].push_back(CAbFactory<CMonster>::Create());

	CCollisionMgr::Collision_Circle(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
	CCollisionMgr::Collision_Circle(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_ROTBULLET]);

}

void CMainGame::Render()
{
	Rectangle(m_hdc, 0, 0, WINCX, WINCY);
	Rectangle(m_hdc, GAME_WIN_LEFT, GAME_WIN_TOP, GAME_WIN_RIGHT, GAME_WIN_BOTTOM);


	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& obj : m_ObjList[i])
			obj->Render(m_hdc);
	}

	int iFR = dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Get_FireRate();
	TCHAR		szBufBUL[32] = L"";
	wsprintf(szBufBUL, L"Bullet : %d\nFireRate : %d", static_cast<int>(m_ObjList[OBJ_BULLET].size()) + static_cast<int>(m_ObjList[OBJ_ROTBULLET].size()), iFR);
	TextOut(m_hdc, 50, 50, szBufBUL, lstrlen(szBufBUL));

}

void CMainGame::Release()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_hdc);
}
