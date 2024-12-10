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
	CAnimMgr::Get_Instance()->Insert_Animation(L"Bullet_Elec",						// 애니메이션 키 값
									CAbstractFactory<CAnimation>::Create(this,		// this 고정
																		{77, 80},	// 이미지 사이즈(개체 크기와 동일할 시 m_tInfo.fCX, m_tInfo.fCY)
																		30,			// 애니메이션 속도 (30 ~ 100 정도)
																		7,			// 애니메이션 총 프레임 수
																		L"Boss_Elec"));	// 이미지 키 값
																		// Create에 넣는 이미지 키 값은 bmpmgr를 이용해 이미지를 찾는 용도로 사용
																		// 애니메이션 키 값은 같은 이미지여도 다른 상태의 애니메이션을 만드는 용도

	// Edit_Animation은 통짜 이미지에서 직접 LT좌표를 찾아와 넣어줬을 경우
	// 임의로 프레임 별 LT 좌표를 수정해 입력해주는 용도
	// 같은 사이즈로 이루어진 하나의 이미지일 때는 필요x

	CAnimMgr::Get_Instance()->Edit_Animation(L"Bullet_Elec",// 애니메이션 키값
											{ 5, 90 },		// 이미지에서 자르기 시작할 LT좌표
											{ 77, 80 },		// 이미지 사이즈(개체 크기와 동일할 시 m_tInfo.fCX, m_tInfo.fCY) / 이미지 사이즈가 바뀔 경우를 상정해 넣음
												0);			// 이미지 프레임 인덱스 (0부터 시작)
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
	// Late_Update에서 수정 필요 X

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

	//GdiTransparentBlt(hDC,						// 복사 받을 DC
	//	m_tInfo.fX + iScrollX,
	//	m_tInfo.fY + iScrollY,					// 복사 받을 위치 좌표 X, Y			
	//	m_tInfo.fCX, m_tInfo.fCY,				// 복사 받을 이미지의 가로, 세로
	//	hMemDC,									// 복사할 이미지 DC	
	//	m_tNowState._iX, m_tNowState._iY,		// 비트맵 출력 시작 좌표(Left, top)
	//	m_tInfo.fCX, m_tInfo.fCY,				/// 복사할 이미지의 가로, 세로
	//	RGB(128, 0, 128));						// 출력 효과 설정(그대로 출력)

	// 원하는 애니메이션 Render만 불러주면 됨
	CAnimMgr::Get_Instance()->Render(hDC, L"Bullet_Elec", this);
								// hDC, 애니메이션키값, this고정
}

void CBullet_Elec::Release()
{
}