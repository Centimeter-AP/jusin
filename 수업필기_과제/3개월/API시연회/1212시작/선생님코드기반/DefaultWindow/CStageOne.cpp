#include "pch.h"
#include "CStageOne.h"
#include "CObjMgr.h"
#include "CLineMgr.h"
#include "CBmpMgr.h"
#include "CAbstractFactory.h"
#include "CScrollMgr.h"
#include "CTileMgr.h"
#include "CBeatMgr.h"
#include "CNormalShovel.h"
#include "CTitaniumShovel.h"
#include "CDagger.h"
#include "CSoundMgr.h"
#include "CHeartbeat.h"
#include "CPlayerHP.h"
#include "CLeftBar.h"
#include "CPlayerShovelUI.h"
#include "CPlayerWeaponUI.h"
#include "CSkeleton.h"
#include "CTauren.h"
#include "CBlueSlime.h"
#include "CStair.h"

CStageOne::CStageOne() :m_pBoss(nullptr)
{
}

CStageOne::~CStageOne()
{
	Release();
}

void CStageOne::Initialize()
{
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Tile/Tile.bmp", L"Tile");

	//CLineMgr::Get_Instance()->Initialize();
	for (int i = OBJ_BEAT; i < OBJ_END; ++i)
	{
		CObjMgr::Get_Instance()->Delete_ID((OBJID)i);
	}
	CTileMgr::Get_Instance()->Load_Tile(STAGE_ONE);
	CTileMgr::Get_Instance()->Load_Wall(STAGE_ONE);
	//CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	GET_PLAYER->Set_Pos(300, 300);
	static_cast<CPlayer*>(GET_PLAYER)->Set_PositionCorrect();
	static_cast<CPlayer*>(GET_PLAYER)->Set_FirstTileIdx();
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CTitaniumShovel>::Create_Item(true, 404, 385));
	CObjMgr::Get_Instance()->Get_LastItem()->Set_Target(CObjMgr::Get_Instance()->Get_Player());
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CDagger>::Create_Item(true, 452, 385));
	CObjMgr::Get_Instance()->Get_LastItem()->Set_Target(CObjMgr::Get_Instance()->Get_Player());

	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CHeartbeat>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CPlayerHP>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CPlayerShovelUI>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CPlayerWeaponUI>::Create());
	CObjMgr::Get_Instance()->Add_Object(OBJ_STAIR, CAbstractFactory<CStair>::Create(1320, 934));
	static_cast<CStair*>(CObjMgr::Get_Instance()->Get_LastStair())->Set_NextScene(SC_BOSS);
	static_cast<CStair*>(CObjMgr::Get_Instance()->Get_LastStair())->Set_IsClosed(true);

	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CTauren>::Create_Monster(1272, 912));
	m_pBoss = CObjMgr::Get_Instance()->Get_FirstMonster();
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSkeleton>::Create_Monster(312, 816));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSkeleton>::Create_Monster(696, 816));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSkeleton>::Create_Monster(936, 480));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSkeleton>::Create_Monster(1176, 768));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CBlueSlime>::Create_Monster(504, 720));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CBlueSlime>::Create_Monster(792, 480));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CBlueSlime>::Create_Monster(744, 192));
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CBlueSlime>::Create_Monster(1320, 768));
	//CObjMgr::Get_Instance()->Get_LastMonster()->Set_Target(CObjMgr::Get_Instance()->Get_Player());
	CScrollMgr::Get_Instance()->Set_Scroll(0, 0);

	BEATMGR->Set_BPMSTAGE1();
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
	CSoundMgr::Get_Instance()->PlayBGM(L"BGM_1-1.ogg", 0.2f);
	CBeatMgr::Get_Instance()->Set_MusicStart();
	//CObjMgr::Get_Instance()->
	
	//for (int i = 0; i < 3; ++i)
	//{
	//	//CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CSkeleton>::Create(float(rand() % WINCX), float(rand() % WINCY), 0.f));
	//}
}

int CStageOne::Update()
{
	//CBeatMgr::Get_Instance()->Update();
	CTileMgr::Get_Instance()->Update();

	if (CBeatMgr::Get_Instance()->Get_RightTimeBeat())
	{
		if (m_bBeatOne == true)
		{
			CTileMgr::Get_Instance()->Tile_Shine();

			CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CLeftBar>::Create_Bar(true));
			CBeatMgr::Get_Instance()->Set_Bar(CObjMgr::Get_Instance()->Get_LastBar());
			CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CLeftBar>::Create_Bar(false));
			CBeatMgr::Get_Instance()->Set_Bar(CObjMgr::Get_Instance()->Get_LastBar());
		}
		m_bBeatOne = false;
	}
	else
	{
		m_bBeatOne = true;
	}

	CObjMgr::Get_Instance()->Update();

	++m_iFrameCount;

	return 0;
}

void CStageOne::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	CTileMgr::Get_Instance()->Late_Update();
	CBeatMgr::Get_Instance()->Late_Update();
}


void CStageOne::Render(HDC hDC)
{
	HDC		hGroundDC = CBmpMgr::Get_Instance()->Find_Image(L"Ground");

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	//BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundDC, 0, 0, SRCCOPY);
	//CLineMgr::Get_Instance()->Render(hDC);

	CTileMgr::Get_Instance()->Render(hDC);

	CObjMgr::Get_Instance()->Render(hDC);
	CBeatMgr::Get_Instance()->Render(hDC);
}

void CStageOne::Release()
{
	//CObjMgr::Get_Instance()->Delete_ID(OBJ_PLAYER);
}
