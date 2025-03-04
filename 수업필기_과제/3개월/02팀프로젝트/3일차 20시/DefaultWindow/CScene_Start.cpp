#include "pch.h"
#include "CScene_Start.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CLineMgr.h"
#include "CObjMgr.h"
#include "CAbstractFactory.h"
#include "CSceneMgr.h"
#include "BlockMgr.h"
#include "CBmpMgr.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Initialize(CObj* _pPlayer)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Rock_Man/Start_1.bmp", L"Start_1");
}

void CScene_Start::Update() // 스테이지
{
	//case STAGE_HONG: // 1번 홍동완
//    filePath = L"../Data/Line_Hong.dat";
//    break;
//case STAGE_SILVER:// 2번 최은성
//    filePath = L"../Data/Line_Silver.dat";
//    break;
//case STAGE_HERO://3번 한영웅
//    filePath = L"../Data/Line_Hero.dat";
//    break;
//case STAGE_CHAE://4번 박채영
//    filePath = L"../Data/Line_Chae.dat";
//    break;
//case STAGE_MOO://5번 임무결
//    filePath = L"../Data/Line_Moo.dat";
//    break;

	if (GetAsyncKeyState('1'))
	{
		//g_CurrentStage =(int)SCENE_TYPE::STAGE_Hong;

		CSceneMgr::Get_Instance()->Set_Scene(SCENE_TYPE::STAGE_Hong); // 동완 스테이지로 전환
		//CLineMgr::Get_Instance()->Load_Line(L"../Data/Line_Hong.dat");
		CBlockMgr::Get_Instance()->Load_Block(L"../Data/Block_Hong.dat");
	}
	if (GetAsyncKeyState('2'))
	{
		//g_CurrentStage = (int)SCENE_TYPE::STAGE_Silver;
		CSceneMgr::Get_Instance()->Set_Scene(SCENE_TYPE::STAGE_Silver); // 은성 스테이지로 전환		
		//CLineMgr::Get_Instance()->Load_Line(L"../Data/Line_Silver.dat");
		CBlockMgr::Get_Instance()->Load_Block(L"../Data/Block_Silver.dat");


	}
	if (GetAsyncKeyState('3'))
	{
		//g_CurrentStage = (int)SCENE_TYPE::STAGE_Hero;
		CSceneMgr::Get_Instance()->Set_Scene(SCENE_TYPE::STAGE_Hero); // 영웅 스테이지로 전환	
		//CLineMgr::Get_Instance()->Load_Line(L"../Data/Line_Hero.dat");
		CBlockMgr::Get_Instance()->Load_Block(L"../Data/Block_Hero.dat");

	}
	if (GetAsyncKeyState('4'))
	{
		//g_CurrentStage = (int)SCENE_TYPE::STAGE_Chae;
		CSceneMgr::Get_Instance()->Set_Scene(SCENE_TYPE::STAGE_Chae); // 채영 스테이지로 전환
		//CLineMgr::Get_Instance()->Load_Line(L"../Data/Line_Chae.dat");
		CBlockMgr::Get_Instance()->Load_Block(L"../Data/Block_Chae.dat");

	}
	if (GetAsyncKeyState('5'))
	{
		//g_CurrentStage = (int)SCENE_TYPE::STAGE_Moo;
		CSceneMgr::Get_Instance()->Set_Scene(SCENE_TYPE::STAGE_Moo); // 무결 스테이지로 전환
		//CLineMgr::Get_Instance()->Load_Line(L"../Data/Line_Moo.dat");
		CBlockMgr::Get_Instance()->Load_Block(L"../Data/Block_Moo.dat");

	}

}

void CScene_Start::Late_Update()
{


}
	
void CScene_Start::Render(HDC _hDC)
{

	HDC		hBckDC = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	HDC		hStartDC = CBmpMgr::Get_Instance()->Find_Image(L"Start_1");

	BitBlt(hStartDC, 0, 0, WINCX, WINCY, hBckDC, 0, 0, SRCCOPY);

	BitBlt(_hDC,
		0, 0, WINCX, WINCY,
		hStartDC,
		0,
		0,
		SRCCOPY);
}

void CScene_Start::Release()
{
}

void CScene_Start::Initialize()
{
}

void CScene_Start::LateUpdate()
{
}



