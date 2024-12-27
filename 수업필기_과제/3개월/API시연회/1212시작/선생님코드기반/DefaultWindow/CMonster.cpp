#include "pch.h"
#include "CMonster.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CObjMgr.h"
#include "CBeatMgr.h"
#include "CSoundMgr.h"
#include "CPlayer.h"

CMonster::CMonster()
	:m_fTime(0.f), m_fJumpPower(0.f), m_iCurTileIdx(0)
	, m_iHeadTileIdx(0), m_bMove(false), m_fShadowY(0.f)
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    m_tInfo.fCX = 48.f;
    m_tInfo.fCY = 48.f;
    m_fSpeed = 6.f;

    //CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");
	m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();
	m_iHeadTileIdx = m_iTileIdx = m_iCurTileIdx = Find_MyTileIdx();

	m_tInfo.fX = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fX;
	m_tInfo.fY = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fY - 24.f; 
	m_pTarget = GET_PLAYER;
	m_eDir = DIR_UP;

    m_pImgKey = L"Monster";
	m_fJumpPower = 9.5f;
	Get_TileX();
	Get_TileY();
    m_eRender = RENDER_GAMEOBJECT;
	m_iMaxHP = 6;
	m_iHP = 6;
}

int CMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

	if (BEATMGR->Get_ObjectAbleToMove() == true)
	{
		m_iTileIdx = Find_MyTileIdx();
		if (m_pTarget != nullptr)
		{
			Find_Player();
		}
		if (Can_Move())
			m_bMove = true;
		else
			m_iHeadTileIdx = m_iCurTileIdx;
		BEATMGR->Set_ObjectAbleToMove(false);

	}
	Jumping();

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{

    __super::Move_Frame();
}


void CMonster::Find_Player()
{
	Get_TileX();
	Get_TileY();
	int iPHTileIdx = static_cast<CPlayer*>(m_pTarget)->Get_HeadTileIdx();


	int iPlayerX = iPHTileIdx % TILEX;
	int iPlayerY = iPHTileIdx / TILEX;

	if (iPlayerX == m_iTileX && iPlayerY == m_iTileY)
		return;

	if (abs(iPlayerX - m_iTileX) >= abs(iPlayerY - m_iTileY))	// 가로 거리가 더 멀 경우
	{
		if (iPlayerX - m_iTileX > 0)	// 플레이어가 오른쪽에 있음
		{
			m_eDir = DIR_RIGHT;
			m_iHeadTileIdx = m_iCurTileIdx + 1;
		}
		else							// 플레이어가 왼쪽에 있음
		{
			m_eDir = DIR_LEFT;
			m_iHeadTileIdx = m_iCurTileIdx - 1;
		}
	}
	else
	{
		if (iPlayerY - m_iTileY > 0)	// 플레이어가 아래에 있음
		{
			m_eDir = DIR_DOWN;
			m_iHeadTileIdx = m_iCurTileIdx + TILEX;
		}
		else							// 플레이어가 위에 있음
		{
			m_eDir = DIR_UP;
			m_iHeadTileIdx = m_iCurTileIdx - TILEX;
		}
	}
}



void CMonster::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    Rectangle(hDC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);


    //GdiTransparentBlt(hDC,			// 복사 받을 DC
    //    m_tRect.left + iScrollX,	// 복사 받을 위치 좌표 X, Y	
    //    m_tRect.top + iScrollY,
    //    (int)m_tInfo.fCX,			// 복사 받을 이미지의 가로, 세로
    //    (int)m_tInfo.fCY,
    //    hMemDC,						// 복사할 이미지 DC	
    //    0,							// 비트맵 출력 시작 좌표(Left, top)
    //    0,
    //    (int)m_tInfo.fCX,			// 복사할 이미지의 가로, 세로
    //    (int)m_tInfo.fCY,
    //    RGB(255, 255, 255));		// 제거할 색상
}

void CMonster::Release()
{
}

void CMonster::Jumping()
{
	if (m_bMove) // 실제로 타일을 이동했는가
	{
		float fHeadX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
		float fHeadY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;
		float fCurX = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fX;
		float fCurY = (*m_pvecTile)[m_iCurTileIdx]->Get_Info().fY - 24.f;

		switch (m_eDir)
		{
		case DIR_LEFT:
			m_fJumpPower = 9.5f;
			// origfy가 이제 m_Curidx고
			// 오른쪽은 m_headidx로 비교
			if (fHeadY < m_tInfo.fY)
			{
				m_tInfo.fY = fHeadY;
				m_tInfo.fX = fHeadX;
				m_bMove = false;
				m_fTime = 0.f;
				m_iCurTileIdx = m_iHeadTileIdx;
			}
			else
			{
				m_tInfo.fX -= (m_fSpeed * cosf(45.f * PI / 180) * m_fTime);
				if (fHeadX > m_tInfo.fX)
					m_tInfo.fX = fHeadX;
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
			}
			break;
		case DIR_RIGHT:
			m_fJumpPower = 9.5f;
			if (fHeadY < m_tInfo.fY)
			{
				m_tInfo.fY = fHeadY;
				m_tInfo.fX = fHeadX;
				m_bMove = false;
				m_fTime = 0.f;
				m_iCurTileIdx = m_iHeadTileIdx;
			}
			else
			{
				m_tInfo.fX += (m_fSpeed * cosf(45.f * PI / 180) * m_fTime);
				if (fHeadX < m_tInfo.fX)
					m_tInfo.fX = fHeadX;
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
			}
			break;
		case DIR_UP:
			m_fJumpPower = 20.f;

			if (fHeadY > m_tInfo.fY)
			{
				m_tInfo.fY = fHeadY;
				m_tInfo.fX = fHeadX;
				m_fShadowY = fHeadY - 20.f;
				m_bMove = false;
				m_iCurTileIdx = m_iHeadTileIdx;
				m_fTime = 0.f;
			}
			else
			{
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.1f;
				if ((m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.2f < 0)
				{
					m_tInfo.fY = fHeadY - 5.f;
					//m_fShadowY = fHeadY - 20.f;
					//m_bMove = false;
					m_iCurTileIdx = m_iHeadTileIdx;
					m_fTime = 0.f;
				}
			}

			m_fShadowY += -2.f * m_fTime - (9.8f * m_fTime * m_fTime) * 0.45f;
			break;
		case DIR_DOWN:
			m_fJumpPower = 20.f;

			m_tInfo.fY += (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime);
			if ((m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) < 0)
			{
				m_tInfo.fY = fHeadY;
				m_tInfo.fX = fHeadX;
				m_bMove = false;
				m_fShadowY = fHeadY - 20.f;
				m_iCurTileIdx = m_iHeadTileIdx;
				m_fTime = 0.f;
			}
			m_fShadowY -= -6.f * m_fTime - (9.8f * m_fTime * m_fTime);
			if (m_fShadowY > fHeadY - 20.f)
				m_fShadowY = fHeadY - 20.f;
			break;
		default:
			break;
		}
		m_fTime += 0.15f;
	}
	else
	{
		m_fTime = 0.f;
	}

}

bool CMonster::Can_Move()
{
	float	fHeadX(0.f), fHeadY(0.f);
	fHeadX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
	fHeadY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY;

	int iPHTileIdx = static_cast<CPlayer*>(m_pTarget)->Get_HeadTileIdx();

	int iPlayerX = iPHTileIdx % TILEX;
	int iPlayerY = iPHTileIdx / TILEX;
	//return CTileMgr::Get_Instance()->Check_TileObject(m_iHeadTileIdx);

	CObj* pHeadWall = CTileMgr::Get_Instance()->Is_Wall_Exist(fHeadX, fHeadY);
	CObj* pHeadMonster = CObjMgr::Get_Instance()->Is_Monster_Exist(m_iHeadTileIdx);

	if (pHeadWall != nullptr)		// 벽 검사
	{
		return false;
	}
	else if (pHeadMonster != nullptr)
	{
		if (pHeadMonster == this)
			return true;
		return false;
	}
	else if (iPHTileIdx == m_iHeadTileIdx)
	{
		return false;
	}
	else
		return true;
	return true;

}
