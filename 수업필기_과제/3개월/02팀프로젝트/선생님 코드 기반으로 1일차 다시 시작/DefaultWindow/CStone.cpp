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
        GdiTransparentBlt(hDC,			// ���� ���� DC
            m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
            m_tRect.top + iScrollY,
            (int)m_tInfo.fCX,			// ���� ���� �̹����� ����, ����
            (int)m_tInfo.fCY,
            hMemDC,						// ������ �̹��� DC	
            0,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
            0,
            (int)m_tInfo.fCX,			// ������ �̹����� ����, ����
            (int)m_tInfo.fCY,
            RGB(128, 0, 128));		// ������ ����
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
    //m_pTarget(player)�� pebble�� ���� ������ üũ
    return false;
}

void CStone::Throw()
{

    // ���� ���� ������ �׸��� ���ư���(����?)
    // ���� �Ŀ� x�� ��ȭ�� ���� �ֱ� ������ ����
    // ���� Y�� �̵� / �� �� ���� �浹 �� ����
    // 
}

