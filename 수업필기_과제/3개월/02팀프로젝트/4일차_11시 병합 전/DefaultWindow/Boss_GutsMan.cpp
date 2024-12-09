#include "pch.h"
#include "Boss_GutsMan.h"
#include "CBullet.h"
#include "CScrollMgr.h"
#include "CLineMgr.h"
#include "BlockMgr.h"
#include "CAbstractFactory.h"
#include "CSuper_Arm.h"
#include "CObjMgr.h"
// bullet�� key input ����
// key input�� �ԷµǸ� �߻�?
// ������?
// �� Ÿ�� Ȧ��?

CBoss_GutsMan::CBoss_GutsMan()
{
	m_p_Boss_Bullet = nullptr;
	ZeroMemory(&HP_INFO, sizeof(HP_INFO));
	m_Boss_pPlayer = NULL;
	m_ullLast_Fire = 0;

	Bullet_X = 40;

	Hp_Count = 0;
	MAX_Hp = 10;

	m_bJump = true;
	m_fJumpPower = 10.f;
	m_fTime = 0.f;
	m_enState = STATE_IDLE;
	m_bHoldBullet = false;
	m_iStateCooldown = 30;
	m_eDir = DIR_LEFT;
	m_enMovingDir = DIR_LEFT;
}

void CBoss_GutsMan::Initialize()
{
	m_tInfo = { 500, 500, 42.f, 48.f };
	HP_INFO = { 200,200,200.f,200.f };
	m_fSpeed = 3.f;

}

int CBoss_GutsMan::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	switch (m_enState)
	{
	case CBoss_GutsMan::STATE_IDLE:
		m_iStateCooldown--;
		break;
	case CBoss_GutsMan::STATE_MOVE:
		if (m_enMovingDir == DIR_RIGHT) { m_tInfo.fX += 1.f; }
		else if (m_enMovingDir == DIR_LEFT) { m_tInfo.fX -= 1.f; }
		m_iStateCooldown--;
		break;
	case CBoss_GutsMan::STATE_HOLD:
		if (m_bHoldBullet == false)
		{
			m_bHoldBullet = true;

			CObjMgr::Get_Instance()->Add_Object(OBJ_BOSSBULLET, CAbstractFactory<CSuper_Arm>::Create(this));
		}
		m_iStateCooldown--;
		break;
	case CBoss_GutsMan::STATE_ATTACK:
		//m_tInfo.fY += 0.1f;
		if (m_bHoldBullet == true)
			m_bHoldBullet = false;
		//Attack();
		m_iStateCooldown--;
		break;
	case CBoss_GutsMan::STATE_JUMP:
		//m_tInfo.fY -= 0.1f;
		Jump();
		m_iStateCooldown--;
		break;
	default:
		break;
	}
	if (m_iStateCooldown == 0)
	{
		m_enState = GUTSTATE((m_enState + 1) % (int)STATE_END);
		switch (m_enState)
		{
		case CBoss_GutsMan::STATE_IDLE:
			m_iStateCooldown = 40;
			break;
		case CBoss_GutsMan::STATE_MOVE:
			m_iStateCooldown = 60;
			break;
		case CBoss_GutsMan::STATE_HOLD:
			m_iStateCooldown = 30;
			break;
		case CBoss_GutsMan::STATE_ATTACK:
			m_iStateCooldown = 60;
			break;
		case CBoss_GutsMan::STATE_JUMP:
			m_iStateCooldown = 100;
			break;
		case CBoss_GutsMan::STATE_END:
			break;
		default:
			break;
		}
		m_enMovingDir = DIRECTION(rand() % 2 + 1);
	}
	if (m_tInfo.fX >= WINCX - 100)
		m_tInfo.fX = WINCX - 100;
	else if (m_tInfo.fX <= 200)
		m_tInfo.fX = 200;
	if (m_tInfo.fY >= WINCY - 100)
		m_tInfo.fY = WINCY - 100;
	Update_Rect();
	return OBJ_NOEVENT;
}


void CBoss_GutsMan::Late_Update()
{
	if (CObjMgr::Get_Instance()->Get_Player()->Get_Info().fX < m_tInfo.fX)
		m_eDir = DIR_LEFT;
	else
		m_eDir = DIR_RIGHT;
}


void CBoss_GutsMan::Render(HDC hDC)
{
	// ��ũ�� ��ġ ���
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	// ���� ��ü �簢�� ������
	Rectangle(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		m_tRect.right + iScrollX,
		m_tRect.bottom + iScrollY);

	// ü�� �� ��� (m_fSpeed ���� Ȯ��)
	if (m_fSpeed == 0)
	{
		// ��ü ü�� �� , ����Ʈ,ž,����Ʈ,����
		Rectangle(hDC, 90, 80, 110, 200);  // �ϴ� �ִ�ä�� 580

		// ü�� �� ���� ����
		HBRUSH MyBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, MyBrush);

		// ���� ü�¿� ���� �� ���� ���
		Rectangle(hDC, 90, 80, 110, (200 - Hp_Count));

		// �귯�� ����
		SelectObject(hDC, OldBrush);
		DeleteObject(MyBrush);
	}
}




void CBoss_GutsMan::Release()
{
}

void CBoss_GutsMan::Key_Input()
{

}

CObj* CBoss_GutsMan::Create_Bullet()
{
	CObjMgr::Get_Instance()->Add_Object(OBJ_BOSSBULLET, CAbstractFactory<CSuper_Arm>::Create(this));

	return nullptr;
}

void CBoss_GutsMan::Jumping()
{

	//if (m_bJump)
	//{
	//	// ������ ��꿡 ���� y ��ġ ����
	//	m_tInfo.fY -= (m_fJumpPower * sinf(45.f) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
	//	m_fTime += 0.2f;

	//	if (bLineCol && (fY < m_tInfo.fY))
	//	{
	//		// �浹 �� ���� ����
	//		m_bJump = false;
	//		m_fTime = 0.f;
	//		m_tInfo.fY = fY;
	//	}
	//}
	//else if (bLineCol)
	//{
	//	// ���� �浹 �� ��ġ ����
	//	m_tInfo.fY = fY;
	//}
	//else
	//{
	//	// ���߿��� �߷� ����
	//	m_tInfo.fY += 9.8f * m_fTime * m_fTime * 0.5f;
	//	m_fTime += 0.2f;
	//}
}

void CBoss_GutsMan::Jump()
{
	if (m_bJump)
	{
		// ������ ��꿡 ���� y ��ġ ����
		m_tInfo.fY -= (m_fJumpPower * sinf(45.f) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
		m_fTime += 0.2f;

		if (500 <= m_tInfo.fY)
		{
			// �浹 �� ���� ����
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.fY = 500.f;
		}
	}
	else
	{
		// ���߿��� �߷� ����
		m_tInfo.fY = 500.f;
	}
}
//





