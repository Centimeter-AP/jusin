#include "pch.h"
#include "CPlayer.h"

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
	LT = { 350.f, 250.f, 0.f };
	RT = { 450.f, 250.f, 0.f };
	LD = { 350.f, 350.f, 0.f };
	RD = { 450.f, 350.f, 0.f };
	Posin = { 400.f, 200.f, 0.f };

	//HBRUSH PinkBrush = CreateSolidBrush(RGB(255, 220, 220));
	//HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, PinkBrush);

	//POINT pPos[12]{ {400,150}, {320, 80},  {250, 50}, {150, 80}, {100, 200}, {150, 300}, {400, 500},
	//					   {650, 300}, {700, 200},{650, 80}, {550, 50},  {480, 80} };
	//Polygon(hdc, pPos, 12);

}

void CPlayer::Update()
{
	Key_Input();
	{
		LT.x = m_tInfo.vPos.x - 50.f;
		LT.y = m_tInfo.vPos.y - 50.f;
		RT.x = m_tInfo.vPos.x + 50.f;
		RT.y = m_tInfo.vPos.y - 50.f;
		RD.x = m_tInfo.vPos.x + 50.f;
		RD.y = m_tInfo.vPos.y + 50.f;
		LD.x = m_tInfo.vPos.x - 50.f;
		LD.y = m_tInfo.vPos.y + 50.f;
		Posin.x = m_tInfo.vPos.x;
		Posin.y = m_tInfo.vPos.y - 100.f;
	}



}

void CPlayer::Late_Update()
{
	//D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(angle));
	//D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x + m_tInfo.vDir.x * m_fSpeed, m_tInfo.vPos.y + m_tInfo.vDir.y * m_fSpeed, 0.f);
	
	//D3DXMatrixTranslation(&matTrans, m_tInfo.vDir.x * m_fSpeed,  m_tInfo.vDir.y * m_fSpeed, 0.f);

	LT -= m_tInfo.vPos;
	RT -= m_tInfo.vPos;
	LD -= m_tInfo.vPos;
	RD -= m_tInfo.vPos;
	Posin -= m_tInfo.vPos;





	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x,  m_tInfo.vPos.y, 0.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));

	m_tInfo.matWorld = matRotZ * matTrans;
	D3DXVec3TransformCoord(&LT, &LT, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&LD, &LD, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&RT, &RT, &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&RD, &RD, &m_tInfo.matWorld);
	//D3DXVec3TransformCoord(&Posin, &Posin, &m_tInfo.matWorld);
	D3DXMATRIX matRotZPosin;
	D3DXMATRIX matPosinWorld;
	D3DXMatrixRotationZ(&matRotZPosin, D3DXToRadian(m_fPosinAngle + m_fAngle));
	matPosinWorld = matRotZPosin * matTrans;
	D3DXVec3TransformCoord(&Posin, &Posin, &matPosinWorld);

}



void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, LT.x, LT.y, 0);
	LineTo(hDC, RT.x, RT.y);
	LineTo(hDC, RD.x, RD.y);
	LineTo(hDC, LD.x, LD.y);
	LineTo(hDC, LT.x, LT.y);
	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, 0);
	LineTo(hDC, Posin.x, Posin.y);
	Ellipse(hDC, RT.x - 5, RT.y - 5, RT.x + 5, RT.y + 5);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	//D3DXMatrixIdentity(&matRotZ);

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_fPosinAngle -= 5;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fPosinAngle += 5;

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

}
