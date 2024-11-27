#include "pch.h"
#include "MainGame.h"
#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

CMainGame::CMainGame() : m_hdc(nullptr), m_pPlayer(nullptr), m_pMonster(nullptr)
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	if (nullptr != m_pMonster)
	{
		m_pMonster->Update();
	}
	if (!m_BulletList.empty())
	{
		for (auto iBullet = m_BulletList.begin(); iBullet != m_BulletList.end();)
		{
			if ((*iBullet)->Get_Info().fX <= 100 ||
				(*iBullet)->Get_Info().fX >= WINCX - 100 ||
				(*iBullet)->Get_Info().fY <= 100 ||
				(*iBullet)->Get_Info().fY >= WINCY - 100)
			{
				Safe_Delete<CObj*>(*iBullet);
				iBullet = m_BulletList.erase(iBullet);
				continue;
			}
			else if (nullptr != m_pMonster)
			{
				if (IntersectRect(&m_temp, (*iBullet)->Get_Rect(), m_pMonster->Get_Rect()))
				{
					Safe_Delete<CObj*>(m_pMonster);
					Safe_Delete<CObj*>(*iBullet);
					iBullet = m_BulletList.erase(iBullet);
					continue;
				}
			}
			(*iBullet)->Update();
			iBullet++;
		}
	}

}

void CMainGame::Render()
{
	Rectangle(m_hdc, 0, 0, WINCX, WINCY);
	Rectangle(m_hdc, 100, 100, WINCX - 100, WINCY - 100);

	m_pPlayer->Render(m_hdc);
	if (nullptr != m_pMonster)
		m_pMonster->Render(m_hdc);
	for (auto& iBullet : m_BulletList)
		iBullet->Render(m_hdc);

	TCHAR		szBufBUL[32] = L"";
	//TCHAR		szBufFPS[32] = L"";
	wsprintf(szBufBUL, L"Bullet : %d", m_BulletList.size());
	TextOut(m_hdc, 50, 50, szBufBUL, lstrlen(szBufBUL));
	//wsprintf(szBufFPS, L"FPS : %d", );
}

void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
		dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);
	}
	if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pMonster->Initialize();
	}
}

void CMainGame::Release()
{
	Safe_Delete<CObj*>(m_pPlayer);
	Safe_Delete<CObj*>(m_pMonster);

	for_each(m_BulletList.begin(), m_BulletList.end(), Safe_Delete<CObj*>);
	m_BulletList.clear();    //////////

	ReleaseDC(g_hWnd, m_hdc);
}
