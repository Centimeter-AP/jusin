#include "pch.h"
#include "CMyEdit.h"
#include "CTileMgr.h"
#include "CBmpMgr.h"
#include "CKeyMgr.h"
#include "CScrollMgr.h"

CMyEdit::CMyEdit() : m_enType(OPT_TILE), m_iNum(0)
{
}

CMyEdit::~CMyEdit()
{
	Release();
}

void CMyEdit::Initialize()
{
	CTileMgr::Get_Instance()->Initialize();

	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile.bmp", L"Tile");
}

int CMyEdit::Update()
{
	CTileMgr::Get_Instance()->Update();

	return 0;
}

void CMyEdit::Late_Update()
{
	Key_Input();
	CTileMgr::Get_Instance()->Late_Update();

}

void CMyEdit::Render_InfoText(HDC hDC)
{
	TCHAR szText[32];
	wsprintf(szText, L"Ÿ��: X");
	TCHAR szNum[32];
	wsprintf(szNum, L"��ȣ: X");
	switch (m_enType)
	{
	case OPT_TILE:
		wsprintf(szText, L"Ÿ��: Ÿ��");
		if (m_iNum == 0)
			wsprintf(szNum, L"��ȣ: 0");
		else if (m_iNum == 1)
			wsprintf(szNum, L"��ȣ: X");
		break;
	case OPT_WALL:
		wsprintf(szText, L"Ÿ��: ��");
		if (m_iNum == 0)
			wsprintf(szNum, L"��ȣ: �뺮");
		else if (m_iNum == 1)
			wsprintf(szNum, L"��ȣ: ����");
		else if (m_iNum == 2)
			wsprintf(szNum, L"��ȣ: ������");
		else if (m_iNum == 3)
			wsprintf(szNum, L"��ȣ: �����");
		else if (m_iNum == 4)
			wsprintf(szNum, L"��ȣ: ���ι�");
		else if (m_iNum == 5)
			wsprintf(szNum, L"��ȣ: ���ι�");
		else
			wsprintf(szNum, L"��ȣ: X");
		break;
	case OPT_ITEM:
		wsprintf(szText, L"Ÿ��: ������");
		if (m_iNum == 0)
			wsprintf(szNum, L"��ȣ: �ܰ�");
		else if (m_iNum == 1)
			wsprintf(szNum, L"��ȣ: �⺻��");
		break;
	case OPT_ENTITY	:
		wsprintf(szText, L"Ÿ��: ��ƼƼ");
		break;
	case OPT_TRAP:
		wsprintf(szText, L"Ÿ��: Ʈ��");
		break;
	default:
		break;
	}
	TextOut(hDC, 0, 0, szText, lstrlen(szText));
	TextOut(hDC, 0, 15, szNum, lstrlen(szNum));
}

void CMyEdit::Render(HDC hDC)
{
	CTileMgr::Get_Instance()->Render(hDC);

	Render_InfoText(hDC);
}

void CMyEdit::Release()
{
}

void CMyEdit::Key_Input()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
	{
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
	{
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		POINT	ptMouse{};
		GetCursorPos(&ptMouse);
		ScreenToClient(g_hWnd, &ptMouse);

		ptMouse.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
		ptMouse.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

		CTileMgr::Get_Instance()->Make_Object(ptMouse, m_iNum, m_enType);

		//CTileMgr::Get_Instance()->Picking_Tile(ptMouse, 1, 1);
	}
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RBUTTON))
	{
		POINT	ptMouse{};
		GetCursorPos(&ptMouse);
		ScreenToClient(g_hWnd, &ptMouse);

		ptMouse.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
		ptMouse.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

		CTileMgr::Get_Instance()->Delete_Object(ptMouse, m_enType);

		//CTileMgr::Get_Instance()->Picking_Tile(ptMouse, 0, 0);
	}
	if (CKeyMgr::Get_Instance()->Key_Down('S'))
	{
		CTileMgr::Get_Instance()->Save_Tile();
		CTileMgr::Get_Instance()->Save_Wall();
		return;
	}

	if (CKeyMgr::Get_Instance()->Key_Down('L'))
	{
		CTileMgr::Get_Instance()->Load_Tile();
		CTileMgr::Get_Instance()->Load_Wall();
		return;
	}
	if (CKeyMgr::Get_Instance()->Key_Down('1'))
	{
		m_enType = OPT_TILE;
	}
	if (CKeyMgr::Get_Instance()->Key_Down('2'))
	{
		m_enType = OPT_WALL;
	}
	if (CKeyMgr::Get_Instance()->Key_Down('3'))
	{
		m_enType = OPT_ITEM;
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_OEM_MINUS))
	{
		if (m_iNum == 0)
			return;
		--m_iNum;
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_OEM_PLUS))
	{
		if (m_iNum == 6)
			return;
		++m_iNum;
	}
}
