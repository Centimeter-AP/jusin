#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"

CPlayer::CPlayer() : m_LinePos { { 100, WINCY - 100 }, { 300,WINCY - 100 }, { 500,WINCY - 300 }, { 700,WINCY - 300 } }
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo  = { 100.f, WINCY - 100.f, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_fDistance = 100.f;
}

int CPlayer::Update()
{
	Key_Input();

	// CObj::Update_Rect();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayer::Late_Update()
{
	// degree to radian

	m_tPosin.x = long(m_tInfo.fX + (m_fDistance * cosf(m_fAngle * (PI / 180.f))));
	m_tPosin.y = long(m_tInfo.fY - (m_fDistance * sinf(m_fAngle * (PI / 180.f))));
}


void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		m_tRect.left, 
		m_tRect.top, 
		m_tRect.right, 
		m_tRect.bottom);

	// 포신
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	// GetKeyState
	// GetAsyncKeyState // 함수 호출 시 반환되는 값에 따른 키 값 처리 가능

#pragma region 복습

	/*if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}

		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}

		else
		{
			m_tInfo.fX += m_fSpeed;
		}

	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}

		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}

		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}

	else if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
		m_pBullet->push_back(Create_Bullet(DIR_LU));
		m_pBullet->push_back(Create_Bullet(DIR_RU));
	}

	if (GetAsyncKeyState('W')) m_pBullet->push_back(Create_Bullet(DIR_UP));
	if (GetAsyncKeyState('S')) m_pBullet->push_back(Create_Bullet(DIR_DOWN));
	if (GetAsyncKeyState('A'))
	{
		m_pBullet->push_back(Create_Bullet(DIR_LEFT));
	}

	if (GetAsyncKeyState('D'))
	{
		m_pBullet->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, DIR_RIGHT));
	}*/
#pragma endregion
	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fX += -m_fSpeed * cosf(m_fAngle * (PI / 180.f));
		m_tInfo.fY -= -m_fSpeed * sinf(m_fAngle * (PI / 180.f));
	}
	

	if (GetAsyncKeyState(VK_LEFT))
	{
		for (int i = 1; i < 4; ++i)
		{
			if (m_LinePos[i].x > m_tInfo.fX)
			{
				if (m_fSpeed > 0)
					m_fSpeed *= -1;
				Move_Line(m_LinePos[i], m_LinePos[i - 1]);
				break;
			}
		}
		//m_fAngle += 5.f;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		for (int i = 1; i < 4; ++i)
		{
			if (m_LinePos[i].x > m_tInfo.fX)
			{
				if (m_fSpeed < 0)
					m_fSpeed *= -1;
				Move_Line(m_LinePos[i], m_LinePos[i - 1]);
				break;
			}
		}
		//m_fAngle -= 5.f;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_BULLET, CAbstractFactory<CGuideBullet>::
			Create((float)m_tPosin.x, (float)m_tPosin.y, m_fAngle));
	}

	if (GetAsyncKeyState(VK_F1))
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_SHIELD, Create_Shield());
	}

}

CObj* CPlayer::Create_Shield()
{
	CObj* pShield = CAbstractFactory<CShield>::Create();
	
	pShield->Set_Target(this);

	return pShield;
}

void CPlayer::Move_Line(POINT Dst, POINT Src)
{
	float	fResX, fResY;
	fResX = m_tInfo.fX + m_fSpeed;
	float	fM(0.f);

	fM = (Src.y - Dst.y) / (Src.x - Dst.x);

	fResY = fM * (fResX - Dst.x) + Dst.y;

	m_tInfo.fX = fResX;
	m_tInfo.fY = fResY;

}


void CPlayer::Move_Line2(POINT Dst, POINT Src)
{
	float	fResX, fResY;
	fResX = m_tInfo.fX - m_fSpeed;
	float	fM(0.f);

	fM = (Src.y - Dst.y) / (Src.x - Dst.x);

	fResY = fM * (fResX - Dst.x) + Dst.y;

	m_tInfo.fX = fResX;
	m_tInfo.fY = fResY;

}

