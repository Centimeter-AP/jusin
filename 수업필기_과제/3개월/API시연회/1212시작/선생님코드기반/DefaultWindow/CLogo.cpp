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
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile.bmp", L"Tile");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Walls.bmp", L"Wall");


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

	GdiTransparentBlt(hDC,			// 복사 받을 DC
		0,	// 복사 받을 위치 좌표 X, Y	
		WINCY / 2 - 453 / 2,
		WINCX,			// 복사 받을 이미지의 가로, 세로
		453,
		hMemDC,						// 복사할 이미지 DC	
		0,							// 비트맵 출력 시작 좌표(Left, top)
		0,
		800,			// 복사할 이미지의 가로, 세로
		453,			// 복사할 이미지의 가로, 세로
		RGB(255, 0, 255));		// 제거할 색상
}

void CLogo::Release()
{
}
