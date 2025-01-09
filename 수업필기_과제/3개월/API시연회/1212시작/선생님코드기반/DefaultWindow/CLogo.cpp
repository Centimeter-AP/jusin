#include "pch.h"
#include "CLogo.h"
#include "CBmpMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CSoundMgr.h"

CLogo::CLogo() :m_bStartBGM(false)
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{ 
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Title/Title_Screen_Button.bmp", L"Logo");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile.bmp", L"Tile");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile_Boss.bmp", L"Tile_Boss");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Walls.bmp", L"Wall");


}

int CLogo::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Set_Scene(SC_LOBBY);
		return 0;
	}
	if (m_bStartBGM == false)
	{
		CSoundMgr::Get_Instance()->StopAll();
		CSoundMgr::Get_Instance()->PlayBGM(L"zone1_3.ogg", 0.18f);
		m_bStartBGM = true;
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
		WINCY / 2 - 453 / 2,
		WINCX,			// ���� ���� �̹����� ����, ����
		453,
		hMemDC,						// ������ �̹��� DC	
		0,							// ��Ʈ�� ��� ���� ��ǥ(Left, top)
		0,
		800,			// ������ �̹����� ����, ����
		453,			// ������ �̹����� ����, ����
		RGB(255, 0, 255));		// ������ ����
}

void CLogo::Release()
{
}
