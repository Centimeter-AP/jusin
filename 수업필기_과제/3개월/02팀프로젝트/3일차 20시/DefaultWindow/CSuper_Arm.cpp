#include "pch.h"
#include "CSuper_Arm.h"
#include "CScrollMgr.h"
#include "CAbstractFactory.h"
#include "Boss_GutsMan.h"

CSuper_Arm::CSuper_Arm()
{
}

CSuper_Arm::~CSuper_Arm()
{
	Release();
}

void CSuper_Arm::Initialize()
{
	m_tInfo.fCX = 64.f;
	m_tInfo.fCY = 64.f;
	m_tInfo.fX = m_pTarget->Get_Info().fX;
	m_tInfo.fY = m_pTarget->Get_Info().fY;


	m_fSpeed = 10.f;//�̵��ӵ�
	m_fDistance = 100.f;//�̵��Ÿ�
	m_fJumpPower = 10.f; //�⺻ ���� �Ŀ�
	m_iHp = 1; // �÷��̾� HP(����)
	m_fTime = 0.f;
}

int CSuper_Arm::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	m_eDir = dynamic_cast<CBoss_GutsMan*>(m_pTarget)->Get_Direction();

	if (dynamic_cast<CBoss_GutsMan*>(m_pTarget)->Get_HoldBullet() == true)
	{
		if (m_eDir == DIR_RIGHT)
		{
			m_tInfo.fX = m_pTarget->Get_Info().fX - m_pTarget->Get_Info().fCX * 0.5f;
			m_tInfo.fY = m_pTarget->Get_Info().fY - m_pTarget->Get_Info().fCY;
		}
		else
		{
			m_tInfo.fX = m_pTarget->Get_Info().fX + m_pTarget->Get_Info().fCX * 0.5f;
			m_tInfo.fY = m_pTarget->Get_Info().fY - m_pTarget->Get_Info().fCY ;
		}
	}
	else
	{
		if (m_eDir == DIR_LEFT)
			m_tInfo.fX -= m_fJumpPower * cosf(45.f) * m_fTime;
		else if (m_eDir == DIR_RIGHT)
			m_tInfo.fX += m_fJumpPower * cosf(45.f) * m_fTime;
		m_tInfo.fY -= (m_fJumpPower * sinf(45.f) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
		m_fTime += 0.1f;

		if (m_tInfo.fY >= WINCY/* - 132.f*/ || m_tInfo.fX >= WINCX/* - 132.f */|| m_tInfo.fX <=0/* 132.f*/)
		{
			m_fTime = 0.f;
			m_bDead = true;
		}
	}

	__super::Update_Rect();
	return OBJ_NOEVENT;
}

void CSuper_Arm::Late_Update()
{
}

void CSuper_Arm::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	Rectangle(hDC,
	m_tRect.left + iScrollX,
	m_tRect.top + iScrollY,
	m_tRect.right + iScrollX,
	m_tRect.bottom + iScrollY);
}

void CSuper_Arm::Release()
{
}
