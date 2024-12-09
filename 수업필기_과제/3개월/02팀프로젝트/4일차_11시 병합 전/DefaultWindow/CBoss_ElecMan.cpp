#include "pch.h"
#include "CBoss_ElecMan.h"
#include "CBullet.h"
#include "CBmpMgr.h"
#include "CObjMgr.h"
#include "CCollisionMgr.h"
#include "CAbstractFactory.h"
#include "CBullet_Elec.h"
#include "CAnimMgr.h"
#include "CScrollMgr.h"

CBoss_ElecMan::CBoss_ElecMan() 
	: m_p_Boss_Bullet(nullptr), m_Boss_pPlayer(nullptr),Hp_Count(0),
	MAX_Hp(0), m_fAttackRange(0.f), m_ulTime(0), m_BossState(IDLE),
	m_fChaseRange(0), m_iCount(0)
{
	ZeroMemory(&HP_INFO, sizeof(INFO));

	ZeroMemory(&m_tIdle, sizeof(IMAGE));
	ZeroMemory(&m_tAttack1, sizeof(IMAGE));
	ZeroMemory(&m_tAttack2, sizeof(IMAGE));
	ZeroMemory(&m_tNowState, sizeof(IMAGE));
	ZeroMemory(&m_tChase, sizeof(IMAGE));

}

CBoss_ElecMan::~CBoss_ElecMan()
{
}

void CBoss_ElecMan::Initialize()
{
	m_pTarget = CObjMgr::Get_Instance()->Get_Player();
	m_p_Boss_Bullet = CObjMgr::Get_Instance()->Get_List(OBJ_BOSSBULLET);
	m_tInfo = { 300, 450, 71, 71 };
	m_fAttackRange = 150.f;
	m_fChaseRange = 300.f;

	m_tIdle = { 0, 0 };
	m_tAttack1 = { 486, 0 };
	m_tAttack2 = { 413, 0 };
	m_tChase = { 280, 0 };


	MAX_Hp = 100;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Rock_Man/boss_elec_all.bmp", L"Boss_Elec"); // 이미지 하나만 불러오기
	CAnimMgr::Get_Instance()->Insert_Animation(L"Elec_Idle", CAbstractFactory<CAnimation>::Create(this, { 71, 71 }, 50, 1, L"Boss_Elec"));

	CAnimMgr::Get_Instance()->Insert_Animation(L"Elec_Attack", CAbstractFactory<CAnimation>::Create(this, { 71, 71 }, 460, 2, L"Boss_Elec"));
	CAnimMgr::Get_Instance()->Edit_Animation(L"Elec_Attack", { 413, 0 }, { 71,71}, 0);
	CAnimMgr::Get_Instance()->Edit_Animation(L"Elec_Attack", { 486, 0 }, { 71,71}, 1);

	CAnimMgr::Get_Instance()->Insert_Animation(L"Elec_Chase", CAbstractFactory<CAnimation>::Create(this, { 71, 71 }, 50, 1, L"Boss_Elec"));
	CAnimMgr::Get_Instance()->Edit_Animation(L"Elec_Chase", { 280, 0 }, { 71,71 }, 0);
	//하나의 이미지에서 원하는 애니메이션 분리해 제작 
}

int CBoss_ElecMan::Update()
{
	float Distance = CCollisionMgr::Collision_RangeChack(m_pTarget, this);

	if (Distance <= m_fChaseRange && Distance > m_fAttackRange)
	{
		m_BossState = CHASE;
		if (m_tInfo.fX > m_pTarget->Get_Info().fX)
			m_tInfo.fX -= 3.f;
		if(m_tInfo.fX < m_pTarget->Get_Info().fX)
			m_tInfo.fX += 3.f;
	}
	else if (Distance <= m_fAttackRange)
	{
		m_BossState = ATTACK;
	}
	else
	{
		m_BossState = IDLE;
	}
		
	__super::Update_Rect();
	return 0;
}

void CBoss_ElecMan::Late_Update()
{
	// 여기 ATTACK일 때 create_bullet이 있어서 주석처리를 못했음 ㅎㅎ;
	
	switch (m_BossState)
	{
	case IDLE:
		m_tNowState = m_tIdle;
		break;
	case ATTACK:
	{
		if (m_tNowState == m_tAttack1 || m_tNowState == m_tChase)
		{
			if (++m_iCount >= 30)
			{
				m_tNowState = m_tAttack2;
				m_iCount = 0;
			}
		}
		else if (m_tNowState == m_tAttack2)
		{
			if (++m_iCount >= 30)
			{
				m_p_Boss_Bullet->push_back(Create_Bullet(BUL_ELEC));
				m_tNowState = m_tAttack1;
				m_iCount = 0;
			}
		}
		break;
	}
	case CHASE:
	{
		m_tNowState = m_tChase;
	}
		break;
	default:
		break;
	}
}

void CBoss_ElecMan::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Boss_Elec");

	//GdiTransparentBlt(hDC,						// 복사 받을 DC
	//	m_tInfo.fX, m_tInfo.fY,					// 복사 받을 위치 좌표 X, Y			
	//	m_tInfo.fCX, m_tInfo.fCY,				// 복사 받을 이미지의 가로, 세로
	//	hMemDC,									// 복사할 이미지 DC	
	//	m_tNowState._iX, m_tNowState._iY,		// 비트맵 출력 시작 좌표(Left, top)
	//	71, 71,									// 복사할 이미지의 가로, 세로
	//	RGB(128, 0, 128));						// 출력 효과 설정(그대로 출력)
	
	switch (m_BossState)
	{
	case IDLE:
		CAnimMgr::Get_Instance()->Render(hDC, L"Elec_Idle", this);
		break;
	case ATTACK:
		GdiTransparentBlt(hDC,						// 복사 받을 DC
			m_tRect.left, m_tRect.top,					// 복사 받을 위치 좌표 X, Y			
			m_tInfo.fCX, m_tInfo.fCY,				// 복사 받을 이미지의 가로, 세로
			hMemDC,									// 복사할 이미지 DC	
			m_tNowState._iX, m_tNowState._iY,		// 비트맵 출력 시작 좌표(Left, top)
			71, 71,									// 복사할 이미지의 가로, 세로
			RGB(128, 0, 128));						// 출력 효과 설정(그대로 출력)
		break;
	case CHASE:
		CAnimMgr::Get_Instance()->Render(hDC, L"Elec_Chase", this);
		break;
	default:
		break;
	}

}

void CBoss_ElecMan::Release()
{
}

CObj* CBoss_ElecMan::Create_Bullet(BULLET_ID _type)
{
	return CAbstractFactory<CBullet_Elec>::Create(m_tInfo.fX, m_tInfo.fY, 0.f);
}
