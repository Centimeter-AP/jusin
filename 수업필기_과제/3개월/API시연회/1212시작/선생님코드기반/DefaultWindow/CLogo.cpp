#include "pch.h"
#include "CLogo.h"
#include "CBmpMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Title/Title_Screen_Button.bmp", L"Logo");
}

int CLogo::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Set_Scene(SC_MENU);
		return 0;
	}


	return 0;
}

void CLogo::Late_Update()
{
}

void CLogo::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Logo");

	GdiTransparentBlt(hDC,			// ���� ���� DC
		0,	// ���� ���� ��ġ ��ǥ X, Y	
		0,
		WINCX,			// ���� ���� �̹����� ����, ����
		WINCY,
		hMemDC,						// ������ �̹��� DC	
		0,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		0,
		480,			// ������ �̹����� ����, ����
		272,			// ������ �̹����� ����, ����
		RGB(255, 0, 255));		// ������ ����
}

void CLogo::Release()
{
}
