#include "pch.h"
#include "CBullet_Elec.h"
#include "CScrollMgr.h"
#include "CBmpMgr.h"
#include "CAnimMgr.h"
#include "CAbstractFactory.h"


CBullet_Elec::CBullet_Elec() :iBulletCount(0)
{
	ZeroMemory(&m_tEelc_Bullet1, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet2, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet3, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet4, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet5, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet6, sizeof(IMAGE));
	ZeroMemory(&m_tEelc_Bullet7, sizeof(IMAGE));
}

CBullet_Elec::~CBullet_Elec()
{
}

void CBullet_Elec::Initialize()
{
	m_eBulletId = BUL_ELEC;

	m_tInfo.fCX = 77.f;
	m_tInfo.fCY = 80.f;
	m_fSpeed = 5.f;


	/******************************************************************************************************************/
	CAnimMgr::Get_Instance()->Insert_Animation(L"Bullet_Elec",						// �ִϸ��̼� Ű ��
									CAbstractFactory<CAnimation>::Create(this,		// this ����
																		{77, 80},	// �̹��� ������(��ü ũ��� ������ �� m_tInfo.fCX, m_tInfo.fCY)
																		30,			// �ִϸ��̼� �ӵ� (30 ~ 100 ����)
																		7,			// �ִϸ��̼� �� ������ ��
																		L"Boss_Elec"));	// �̹��� Ű ��
																		// Create�� �ִ� �̹��� Ű ���� bmpmgr�� �̿��� �̹����� ã�� �뵵�� ���
																		// �ִϸ��̼� Ű ���� ���� �̹������� �ٸ� ������ �ִϸ��̼��� ����� �뵵

	// Edit_Animation�� ��¥ �̹������� ���� LT��ǥ�� ã�ƿ� �־����� ���
	// ���Ƿ� ������ �� LT ��ǥ�� ������ �Է����ִ� �뵵
	// ���� ������� �̷���� �ϳ��� �̹����� ���� �ʿ�x

	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec",// �ִϸ��̼� Ű��
											{ 5, 90 },		// �̹������� �ڸ��� ������ LT��ǥ
											{ 77, 80 },		// �̹��� ������(��ü ũ��� ������ �� m_tInfo.fCX, m_tInfo.fCY) / �̹��� ����� �ٲ� ��츦 ������ ����
												0);			// �̹��� ������ �ε��� (0���� ����)
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 89,90 }, { 77, 80 }, 1);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 181, 89 }, { 77, 80 }, 2);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 262, 90 }, { 77, 80 }, 3);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 338, 90 }, { 77, 80 }, 4);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 422, 92 }, { 77, 80 }, 5);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec", { 487, 90 }, { 77, 80 }, 6);
	/******************************************************************************************************************/


	//m_tEelc_Bullet1 = { 5,90 };
	//m_tEelc_Bullet2 = { 89,90 };
	//m_tEelc_Bullet3 = { 181,89 };
	//m_tEelc_Bullet4 = { 262,90 };
	//m_tEelc_Bullet5 = { 338,90 };
	//m_tEelc_Bullet6 = { 422,92 };
	//m_tEelc_Bullet7 = { 487,90 };

}

int CBullet_Elec::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet_Elec::Late_Update()
{
	// Late_Update���� ���� �ʿ� X

	/*iBulletCount++;

	if (iBulletCount < 5)
	{
		m_tNowState = m_tEelc_Bullet1;
	}
	else if (iBulletCount < 10)
	{
		m_tNowState = m_tEelc_Bullet2;
	}
	else if (iBulletCount < 15)
	{
		m_tNowState = m_tEelc_Bullet3;
	}
	else if (iBulletCount < 20)
	{
		m_tNowState = m_tEelc_Bullet4;
	}
	else if (iBulletCount < 25)
	{
		m_tNowState = m_tEelc_Bullet5;
	}
	else if (iBulletCount < 30)
	{
		m_tNowState = m_tEelc_Bullet6;
	}
	else if (iBulletCount < 40)
	{
		m_tNowState = m_tEelc_Bullet7;
		iBulletCount = 0;
	}*/
}

void CBullet_Elec::Render(HDC hDC)
{
	//HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Boss_Elec");

	//int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	//int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	//GdiTransparentBlt(hDC,						// ���� ���� DC
	//	m_tInfo.fX + iScrollX,
	//	m_tInfo.fY + iScrollY,					// ���� ���� ��ġ ��ǥ X, Y			
	//	m_tInfo.fCX, m_tInfo.fCY,				// ���� ���� �̹����� ����, ����
	//	hMemDC,									// ������ �̹��� DC	
	//	m_tNowState._iX, m_tNowState._iY,		// ��Ʈ�� ��� ���� ��ǥ(Left, top)
	//	m_tInfo.fCX, m_tInfo.fCY,				/// ������ �̹����� ����, ����
	//	RGB(128, 0, 128));						// ��� ȿ�� ����(�״�� ���)

	// ���ϴ� �ִϸ��̼� Render�� �ҷ��ָ� ��
	CAnimMgr::Get_Instance()->Render(hDC, L"Bullet_Elec", this);
								// hDC, �ִϸ��̼�Ű��, this����
}

void CBullet_Elec::Release()
{
}