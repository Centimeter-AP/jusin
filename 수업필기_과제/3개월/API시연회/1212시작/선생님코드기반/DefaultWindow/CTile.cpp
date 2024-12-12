#include "pch.h"
#include "CTile.h"
#include "CBmpMgr.h"
#include "CScrollMgr.h"

CTile::CTile() : m_iDrawID(0), m_iOption(0)
{
}

CTile::~CTile()
{
	Release();
}

void CTile::Initialize()
{
	m_tInfo.fCX = TILECX;
	m_tInfo.fCY = TILECY;

	m_pImgKey = L"Tile";

}

int CTile::Update()
{

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTile::Late_Update()
{
}

void CTile::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pImgKey);

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	GdiTransparentBlt(hDC,			// ���� ���� DC
		m_tRect.left + iScrollX,	// ���� ���� ��ġ ��ǥ X, Y	
		m_tRect.top + iScrollY,
		TILECX,			// ���� ���� �̹����� ����, ����
		TILECY ,
		hMemDC,						// ������ �̹��� DC	
		52 * m_iDrawID + 2,			// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		52 * 2+2,					// Ÿ�� ũ�Ⱑ �����¿� 2�ȼ��� �� ��
		TILECX,			// ������ �̹����� ����, ����
		TILECY,
		RGB(255, 0, 255));		// ������ ����
}

void CTile::Release()
{
}
