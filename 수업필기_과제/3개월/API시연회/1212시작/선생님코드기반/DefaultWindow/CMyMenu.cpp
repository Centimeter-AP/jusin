#include "pch.h"
#include "CMyMenu.h"
#include "CBmpMgr.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"

CMyMenu::CMyMenu()
{
}

CMyMenu::~CMyMenu()
{
    Release();
}

void CMyMenu::Initialize()
{

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Start.bmp", L"Start");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Edit.bmp", L"Edit");


    CObj* pButton = CAbstractFactory<CMyButton>::Create(450.f, 500.f);
    pButton->Set_ImgKey(L"Start");
    CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);

    pButton = CAbstractFactory<CMyButton>::Create(650.f, 500.f);
    pButton->Set_ImgKey(L"Edit");
    CObjMgr::Get_Instance()->Add_Object(OBJ_BUTTON, pButton);
}

int CMyMenu::Update()
{
    CObjMgr::Get_Instance()->Update();

    return 0;
}

void CMyMenu::Late_Update()
{
    CObjMgr::Get_Instance()->Late_Update();
}

void CMyMenu::Render(HDC hDC)
{
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Logo");

    GdiTransparentBlt(hDC,			// ���� ���� DC
        0,	// ���� ���� ��ġ ��ǥ X, Y	
        WINCY / 2 - 453 / 2,
        WINCX,			// ���� ���� �̹����� ����, ����
        453,
        hMemDC,						// ������ �̹��� DC	
        0,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
        0,
        800,			// ������ �̹����� ����, ����
        453,			// ������ �̹����� ����, ����
        RGB(255, 0, 255));		// ������ ����

    CObjMgr::Get_Instance()->Render(hDC);
}

void CMyMenu::Release()
{
    CObjMgr::Get_Instance()->Delete_ID(OBJ_BUTTON);
}
