#include "pch.h"
#include "CPebble.h"
#include "CKeyMgr.h"
#include "CObjMgr.h"
#include "CScrollMgr.h"

CPebble::CPebble()
{
}

CPebble::~CPebble()
{
    Release();
}

void CPebble::Initialize()
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 3.f;
}

int CPebble::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CPebble::Late_Update()
{
    if (Is_Hold())
    {
        if (CKeyMgr::Get_Instance()->Key_Down('E'))
        {

            Throw();
        }
    }
}

void CPebble::Render(HDC hDC)
{
    int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
    int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

    if (!m_bGround)
    {
        Rectangle(hDC, m_tRect.left  + iScrollX, m_tRect.top    + iScrollY,
                       m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);
    }
    else
    {
        Rectangle(hDC, m_tRect.left  + iScrollX, m_tRect.top    + iScrollY,
                       m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);
    }
}

void CPebble::Release()
{
}

bool CPebble::Is_Hold()
{
    //m_pTarget(player)가 pebble을 선택 중인지 체크
    return false;
}

void CPebble::Throw()
{

    // 보는 방향 포물선 그리며 날아가기(점프?)
    // 점프 식에 x값 변화도 같이 주기 각도는 고정
    // 일정 Y축 이동 / 선 벽 몹에 충돌 시 삭제
    // 
}

