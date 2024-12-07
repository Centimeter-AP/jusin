#include "pch.h"
#include "CMonster.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"
#include "CAnimMgr.h"
#include "CAbstractFactory.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
    Release();
}

void CMonster::Initialize()
{
    m_tInfo.fCX = 32.f;
    m_tInfo.fCY = 32.f;
    m_fSpeed = 3.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/tile_cut.bmp", L"Monster");
}

int CMonster::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    float   fWidth(0.f), fHeight(0.f), fDiagonal(0.f), fRadian(0.f);

    fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
    fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

    fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

    fRadian = acosf(fWidth / fDiagonal);

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
    //if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
    //    m_fSpeed *= -1.f;
}

void CMonster::Render(HDC hDC)
{
    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Monster");

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
        RGB(128, 0, 128));		    // 제거할 색상
}

void CMonster::Release()
{
}
