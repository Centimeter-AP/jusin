#include "pch.h"
//#include "CTail.h"
//
//void CTail::Initialize()
//{
//
//}
//
//void CTail::Update()
//{
//
//	//D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);
//	//D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
//
//	m_tInfo.matWorld = matRotZ * matTrans;
//	for (int i = 0; i < m_vOriginPointvec.size(); ++i)
//	{
//		//D3DXVec3TransformCoord(&LT, &LT, &m_tInfo.matWorld);
//		D3DXVec3TransformCoord(&m_vPointvec[i], &m_vOriginPointvec[i], &m_tInfo.matWorld);
//		m_pRenderPoint[i].x = m_vPointvec[i].x;
//		m_pRenderPoint[i].y = m_vPointvec[i].y;
//	}
//}
//
//void CTail::Late_Update()
//{
//}
//
//void CTail::Render(HDC hDC)
//{
//	HBRUSH BlueBrush = CreateSolidBrush(RGB(0, 0, 220));
//	HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, BlueBrush);
//
//	Polygon(hDC, m_pRenderPoint, m_vOriginPointvec.size());
//	SelectObject(hDC, OldBrush); DeleteObject(BlueBrush);
//}
//
//void CTail::Release()
//{
//}
//
//void CTail::Set_Target(CObj* _Target)
//{
//	m_pTarget = _Target;
//}
