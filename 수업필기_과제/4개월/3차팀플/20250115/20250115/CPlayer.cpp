#include "pch.h"
#include "CPlayer.h"
#include "CTail.h"

CPlayer::CPlayer(): m_fAngle(0.f), m_fPosinAngle(0.f)
{
	
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_fSpeed = 5.f;
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	__super::Initialize_OriginPoint(15, 40);

	//HBRUSH PinkBrush = CreateSolidBrush(RGB(255, 220, 220));
	//HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, PinkBrush);

	//POINT pPos[12]{ {400,150}, {320, 80},  {250, 50}, {150, 80}, {100, 200}, {150, 300}, {400, 500},
	//					   {650, 300}, {700, 200},{650, 80}, {550, 50},  {480, 80} };
	//Polygon(hdc, pPos, 12);

}

void CPlayer::Update()
{
	Key_Input(); 

	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));

	m_tInfo.matWorld = matRotZ * matTrans;
	for (int i = 0; i < m_vOriginPointvec.size(); ++i)
	{
		//D3DXVec3TransformCoord(&LT, &LT, &m_tInfo.matWorld);
		D3DXVec3TransformCoord(&m_vPointvec[i], &m_vOriginPointvec[i], &m_tInfo.matWorld);
		m_pRenderPoint[i].x = m_vPointvec[i].x;
		m_pRenderPoint[i].y = m_vPointvec[i].y;
	}


}

void CPlayer::Late_Update()
{

}



void CPlayer::Render(HDC hDC)
{
	HBRUSH PinkBrush = CreateSolidBrush(RGB(255, 220, 220));
	HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, PinkBrush);
	
	Polygon(hDC, m_pRenderPoint, m_vOriginPointvec.size());
	SelectObject(hDC, OldBrush); DeleteObject(PinkBrush);
}

void CPlayer::Release()
{
	for (auto& temp : m_pTailvec)
		delete temp;
}

void CPlayer::Key_Input()
{

	if (GetAsyncKeyState(VK_LEFT))
	{

	}
	if (GetAsyncKeyState(VK_RIGHT))
	{

	}

	if (GetAsyncKeyState('A'))
	{
		m_fAngle -= 5;
	}
	if (GetAsyncKeyState('D'))
	{
		m_fAngle += 5;
	}
	if (GetAsyncKeyState('W'))
	{
		m_tInfo.vDir = { 0.f, -m_fSpeed, 0.f };

		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
		//대은성은 신이다
		m_tInfo.vPos += m_tInfo.vDir;
	}
	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vDir = { 0.f, +m_fSpeed, 0.f };

		D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
		m_tInfo.vPos += m_tInfo.vDir;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{

		//CObj* pTemp = new CTail;
		//pTemp->Initialize();
		//if (m_pTailvec.empty())
		//{
		//	static_cast<CTail*>(pTemp)->Set_Target(this);
		//}
		//else
		//{
		//	static_cast<CTail*>(pTemp)->Set_Target(m_pTailvec.back());
		//}
		//m_pTailvec.push_back(pTemp);
	}
}
