#include "pch.h"
#include "CLineMgr.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

bool CLineMgr::isClose(float _Dst, float _Src, float ep)
{
	return (abs(_Dst - _Src) <= ep);
}


bool CLineMgr::Collision_Line(float _fX, float* pY)
{
	if(m_Linelist.empty())
		return false;


	CLine* pTargetLine = nullptr;

	for (auto& pLine : m_Linelist)
	{
		if (_fX >= pLine->Get_Info().tLPoint.fX &&
			_fX < pLine->Get_Info().tRPoint.fX) // X좌표 구간만 확인해서 처리
		{
			pTargetLine = pLine;
		}
	}
	
	
	// 히어로 코드
	// X좌표가 걸치는 모든 선분을 저장하는 임시 List 생성
	// 거기서 다시 for문 돌려서 Y축 좌표가 제일 적은(api니까) 선 선택

	list<CLine*> temp;

	for (auto& pLine : m_Linelist)
	{
		if (_fX >= pLine->Get_Info().tLPoint.fX &&
			_fX < pLine->Get_Info().tRPoint.fX) // X좌표 구간만 확인해서 처리
		{
			temp.push_back(pLine);
			//pTargetLine = pLine;
		}
	}

	for (auto& pYLine : temp)
	{
		float	x1 = pTargetLine->Get_Info().tLPoint.fX;
		float	y1 = pTargetLine->Get_Info().tLPoint.fY;
		float	x2 = pTargetLine->Get_Info().tRPoint.fX;
		float	y2 = pTargetLine->Get_Info().tRPoint.fY;
		float	temp;
		if (*pY )
		*pY = ((y2 - y1) / (x2 - x1)) * (_fX - x1) + y1;
	}




	//for (auto iter = m_Linelist.begin(); iter != m_Linelist.end(); ++iter)
	//{

	//	if (isClose(_fX, (*iter)->Get_Info().tLPoint.fX) &&
	//		isClose(*pY, (*iter)->Get_Info().tLPoint.fY))
	//	{
	//		if (iter != m_Linelist.begin())
	//			pTargetLine = *(--iter);
	//	}
	//	else if(isClose(_fX, (*iter)->Get_Info().tRPoint.fX) &&
	//		  isClose(*pY, (*iter)->Get_Info().tRPoint.fY))
	//	{
	//		if (iter != --(m_Linelist.end()))
	//			pTargetLine = *(++iter);
	//	}
	//	//if (_fX >= pLine->Get_Info().tLPoint.fX &&
	//	//	_fX < pLine->Get_Info().tRPoint.fX) // X좌표 구간만 확인해서 처리
	//	//{
	//	//	pTargetLine = pLine;
	//	//}
	//}







	if (!pTargetLine)
		return false;

	float	x1 = pTargetLine->Get_Info().tLPoint.fX;
	float	y1 = pTargetLine->Get_Info().tLPoint.fY;
	float	x2 = pTargetLine->Get_Info().tRPoint.fX;
	float	y2 = pTargetLine->Get_Info().tRPoint.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (_fX - x1) + y1;

	return true;
}

void CLineMgr::Initialize()
{
	LINEPOINT	tLinePoint[6]{
		{ 100.f, 500.f },
		{ 300.f, 500.f },
		{ 500.f, 400.f },
		{ 700.f, 400.f },
		{ 600.f, 300.f },
		{ 400.f, 300.f }
	};

	m_Linelist.push_back(new CLine(tLinePoint[0], tLinePoint[1]));
	m_Linelist.push_back(new CLine(tLinePoint[1], tLinePoint[2]));
	m_Linelist.push_back(new CLine(tLinePoint[2], tLinePoint[3]));
	m_Linelist.push_back(new CLine(tLinePoint[4], tLinePoint[5]));
}

void CLineMgr::Render(HDC hDC)
{
	for (auto& pLine : m_Linelist)
		pLine->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_Linelist.begin(), m_Linelist.end(), Safe_Delete<CLine*>);
	m_Linelist.clear();
}
