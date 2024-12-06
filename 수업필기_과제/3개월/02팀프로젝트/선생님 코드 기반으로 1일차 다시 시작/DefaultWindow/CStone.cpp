#include "pch.h"
#include "CStone.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"
#include "CCollisionMgr.h"

CStone::CStone()
{
}

CStone::~CStone()
{
    Release();
}

void CStone::Initialize()
{
    m_tInfo.fX = 400.f;
    m_tInfo.fY = 250.f;
    m_tInfo.fCX = 16.f;
    m_tInfo.fCY = 16.f;
    m_fSpeed = 3.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/tile_imsi.bmp", L"Tile");

}

int CStone::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CStone::Late_Update()
{
    
}

void CStone::Render(HDC hDC)
{
    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tile");


    if (m_bGround)
    {
        GdiTransparentBlt(hDC,			// 복사 받을 DC
            m_tRect.left + iScrollX,	// 복사 받을 위치 좌표 X, Y	
            m_tRect.top + iScrollY,
            (int)m_tInfo.fCX,			// 복사 받을 이미지의 가로, 세로
            (int)m_tInfo.fCY,
            hMemDC,						// 복사할 이미지 DC	
            0,							// 비트맵 출력 시작 좌표(Left, top)
            0,
            (int)m_tInfo.fCX,			// 복사할 이미지의 가로, 세로
            (int)m_tInfo.fCY,
            RGB(128, 0, 128));		// 제거할 색상
    }
    else
    {
        Rectangle(hDC, m_tRect.left  + iScrollX, m_tRect.top    + iScrollY,
                       m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);
    }
}

void CStone::Release()
{
}

bool CStone::Is_Hold()
{
    //m_pTarget(player)가 pebble을 선택 중인지 체크
    return false;
}

void CStone::Throw()
{

    // 보는 방향 포물선 그리며 날아가기(점프?)
    // 점프 식에 x값 변화도 같이 주기 각도는 고정
    // 일정 Y축 이동 / 선 벽 몹에 충돌 시 삭제
    // 
}

