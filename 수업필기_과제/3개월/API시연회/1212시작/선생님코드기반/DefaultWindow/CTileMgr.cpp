#include "pch.h"
#include "CTileMgr.h"
#include "CAbstractFactory.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"
#include "CWallMgr.h"
#include "CWall.h"
#include "CDirtWall.h"
#include "CShopWall.h"
#include "CBedrock.h"
#include "CStoneWall.h"

CTileMgr* CTileMgr::m_pInstance = nullptr;

CTileMgr::CTileMgr()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (j == 0)
				float fX = (float)(j * TILECX) + (TILECX >> 1);
			float fX = (float)(j * TILECX) + (TILECX >> 1);
			if (i == 0)
				float fY = (float)(i * TILECY) + (TILECY >> 1);
			float fY = (float)(i * TILECY) + (TILECY >> 1);

			CObj* pTile = CAbstractFactory<CTile>::Create(fX, fY);
			m_vecTile.push_back(pTile);
		}
	}
}

int CTileMgr::Update()
{
	for (auto& pTile : m_vecTile)
		pTile->Update();
	for (auto& pWall : m_vecWall)
		pWall->Update();

	return 0;
}

void CTileMgr::Late_Update()
{
	for (auto& pTile : m_vecTile)
		pTile->Late_Update();
	for (auto& pWall : m_vecWall)
		pWall->Late_Update();
}

void CTileMgr::Render(HDC hDC)
{
	// for (auto& pTile : m_vecTile)
	// 	pTile->Render(hDC);

	int		iScrollX = abs((int)CScrollMgr::Get_Instance()->Get_ScrollX() / TILECX);
	int		iScrollY = abs((int)CScrollMgr::Get_Instance()->Get_ScrollY() / TILECY);

	int		iMaxX = iScrollX + WINCX / TILECX + 2;
	int		iMaxY = iScrollY + WINCY / TILECY + 2;


	/*** Tile Render ***/
	for (int i = iScrollY; i < iMaxY; ++i)
	{
		for (int j = iScrollX; j < iMaxX; ++j)
		{
			int		iIndex = i * TILEX + j;

			if (0 > iIndex || m_vecTile.size() <= (size_t)iIndex)
				continue;
			if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_EDIT)	
			{
				if (iIndex % 2)
					dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(1);
			}
			m_vecTile[iIndex]->Render(hDC);
		}
	}

	/*** Wall Render ***/
	//sort(m_vecWall.begin(), m_vecWall.end(), [](CObj* pDst, CObj* pSrc)->bool {return pDst->Get_Info().fY < pSrc->Get_Info().fY; });
	for (auto& pWall : m_vecWall)
	{
		if (pWall->Get_Info().fX / TILECX >= iScrollX
			&& pWall->Get_Info().fX / TILECX <= iMaxX)
		{
			if (pWall->Get_Info().fY / TILECY >= iScrollY
				&& pWall->Get_Info().fY / TILECY <= iMaxY)
			{
				
				pWall->Render(hDC);
			}
		}
	}
	/*******************/
}

void CTileMgr::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), Safe_Delete<CObj*>);
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();

	for_each(m_vecWall.begin(), m_vecWall.end(), Safe_Delete<CObj*>);
	m_vecWall.clear();
	m_vecWall.shrink_to_fit();
}

void CTileMgr::Picking_Tile(POINT pt, int iDrawID, int iOption)
{
	int		x = pt.x / TILECX;
	int		y = pt.y / TILECY;

	int	iIndex = y * TILEX + x;

	if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
		return;

	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(iDrawID);
	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_Option(iOption);
}

void CTileMgr::Tile_Shine()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if(i % 2)
		{
			if (dynamic_cast<CTile*>(m_vecTile[i])->Get_DrawID() == 0)
				dynamic_cast<CTile*>(m_vecTile[i])->Set_DrawID(2);
			else
				dynamic_cast<CTile*>(m_vecTile[i])->Set_DrawID(0);
		}
		else
		{
			if (dynamic_cast<CTile*>(m_vecTile[i])->Get_DrawID() == 0)
				dynamic_cast<CTile*>(m_vecTile[i])->Set_DrawID(1);
			else
				dynamic_cast<CTile*>(m_vecTile[i])->Set_DrawID(0);
		}
	}
}

bool CTileMgr::Is_Wall_Exist(float	fx, float fy)
{
	if (!m_vecWall.empty())
	{
		auto iter = find_if(m_vecWall.begin(), m_vecWall.end(), [fx, fy](CObj* pWall) {return ((pWall->Get_Info().fX == fx) && (pWall->Get_Info().fY == fy)); });
		if (iter == m_vecWall.end())
			return false;
		else
			return true;
	}
	else
		return false;
}

void CTileMgr::Make_Object(POINT pt, int iDrawID, int iOption)
{
	int		x = pt.x / TILECX;
	int		y = pt.y / TILECY;

	int	iIndex = y * TILEX + x;

	if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
		return;
	switch (iOption)
	{
	case OPT_TILE:
		//dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(iDrawID);
		break;
	case OPT_WALL:
		float fx = m_vecTile[iIndex]->Get_Info().fX;
		float fy = m_vecTile[iIndex]->Get_Info().fY;
		CObj* pWall(nullptr);
		auto iter = find_if(m_vecWall.begin(), m_vecWall.end(), [fx, fy](CObj* pWall) {return ((pWall->Get_Info().fX == fx) && (pWall->Get_Info().fY == fy)); });
		if ((m_vecWall.end() == iter) || dynamic_cast<CWall*>(*iter)->Get_WallType() != iDrawID)
		{
			if (iter != m_vecWall.end())
			{
				Safe_Delete<CObj*>((*iter));
				iter = m_vecWall.erase(iter);
			}
			switch (iDrawID)
			{
			case WALLTYPE::DIRT_WALL:
				pWall = CAbstractFactory<CDirtWall>::Create(fx, fy);
				m_vecWall.push_back(pWall);
				break;
			case WALLTYPE::SHOP_WALL:
				pWall = CAbstractFactory<CShopWall>::Create(fx, fy);
				m_vecWall.push_back(pWall);
				break;
			case WALLTYPE::STONE_WALL:
				pWall = CAbstractFactory<CStoneWall>::Create(fx, fy);
				m_vecWall.push_back(pWall);
				break;
			case WALLTYPE::BEDROCK:
				pWall = CAbstractFactory<CBedrock>::Create(fx, fy);
				m_vecWall.push_back(pWall);
				break;
			default:
				break;
			}
		}
		break;
	}
	sort(m_vecWall.begin(), m_vecWall.end(), [](CObj* pDst, CObj* pSrc)->bool {return pDst->Get_Info().fY < pSrc->Get_Info().fY; });
	//dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(iDrawID);
	//dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_Option(iOption);
}

void CTileMgr::Delete_Object(POINT pt, int iOption)
{
}

void CTileMgr::Save_Tile()
{
	HANDLE hFile = CreateFile(L"../Data/Tile.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	int		iDrawID(0), iOption(0);
	DWORD	dwByte(0);

	for (auto& pTile : m_vecTile)
	{
		iDrawID = dynamic_cast<CTile*>(pTile)->Get_DrawID();
		iOption = dynamic_cast<CTile*>(pTile)->Get_Option();

		WriteFile(hFile, pTile->Get_Info_Pointer(), sizeof(INFO), &dwByte, NULL);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, NULL);
	}
	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Tile Save", L"己傍", MB_OK);

}


void CTileMgr::Save_Wall()
{
	HANDLE hFile = CreateFile(L"../Data/Wall.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	DWORD	dwByte(0);

	for (auto& pWall : m_vecWall)
	{
		WriteFile(hFile, pWall, sizeof(CWall), &dwByte, NULL);
	}
	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Wall Save", L"己傍", MB_OK);

}


void CTileMgr::Load_Wall()
{
	HANDLE hFile = CreateFile(L"../Data/Wall.dat", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	DWORD	dwByte(0);
	CWall	Wall;


	while (true)
	{
		int iRes = ReadFile(hFile, &Wall, sizeof(CWall), &dwByte, NULL);

		if (0 == dwByte)
			break;
		
		CObj* pWall(nullptr);

		switch (Wall.Get_WallType())
		{
		case WALLTYPE::DIRT_WALL:
			pWall = CAbstractFactory<CDirtWall>::Create(Wall.Get_Info());
			m_vecWall.push_back(pWall);
			break;
		case WALLTYPE::SHOP_WALL:
			pWall = CAbstractFactory<CShopWall>::Create(Wall.Get_Info());
			m_vecWall.push_back(pWall);
			break;
		case WALLTYPE::STONE_WALL:
			pWall = CAbstractFactory<CStoneWall>::Create(Wall.Get_Info());
			m_vecWall.push_back(pWall);
			break;
		case WALLTYPE::BEDROCK:
			pWall = CAbstractFactory<CBedrock>::Create(Wall.Get_Info());
			m_vecWall.push_back(pWall);
			break;
		default:
			break;
		}
	}
	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Load Wall", L"己傍", MB_OK);

}




void CTileMgr::Load_Tile()
{
	HANDLE hFile = CreateFile(L"../Data/Tile.dat", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	int		iDrawID(0), iOption(0);
	DWORD	dwByte(0);
	INFO	tTile{};

	Release();

	while (true)
	{
		int iRes = ReadFile(hFile, &tTile, sizeof(INFO), &dwByte, NULL);
		iRes = ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		iRes = ReadFile(hFile, &iOption, sizeof(int), &dwByte, NULL);

		if (0 == dwByte)
			break;

		CObj* pTile = CAbstractFactory<CTile>::Create(tTile.fX, tTile.fY);
		dynamic_cast<CTile*>(pTile)->Set_DrawID(iDrawID);
		dynamic_cast<CTile*>(pTile)->Set_Option(iOption);

		m_vecTile.push_back(pTile);
	}



	CloseHandle(hFile);
	MessageBox(g_hWnd, L"Load Save", L"己傍", MB_OK);

}
