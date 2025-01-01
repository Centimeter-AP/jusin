#include "pch.h"
#include "CPlayerMoney.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"
#include "CBeatMgr.h"
#include "CObjMgr.h"

void CPlayerMoney::Initialize()
{

    m_tInfo = { (float)WINCX - 50.f, 50.f, 48.f, 44.f };
    m_pImgKey = L"Gold";
    m_iHP = CObjMgr::Get_Instance()->Get_Player()->Get_HP();
    m_iMaxHP = CObjMgr::Get_Instance()->Get_Player()->Get_MaxHP();

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/UI/Gold.bmp", L"Gold");
    m_eRender = RENDER_UI;
}

int CPlayerMoney::Update()
{
	return 0;
}

void CPlayerMoney::Late_Update()
{
}

void CPlayerMoney::Render(HDC hDC)
{
}

void CPlayerMoney::Release()
{
}
