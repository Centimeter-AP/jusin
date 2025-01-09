#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CLineMgr.h"
#include "CKeyMgr.h"
#include "CScrollMgr.h"
#include "CSceneMgr.h"
#include "CBmpMgr.h"
#include "CSoundMgr.h"
#include "CTileMgr.h"
#include "CNormalShovel.h"
#include "CTitaniumShovel.h"
#include "CBedrock.h"
#include "CDagger.h"
#include "CBeatMgr.h"
#include "CSplash.h"
#include "CWaterTile.h"
#include "CDaggerEffect.h"
#include "CHitRed.h"
#include "CHealing.h"


CPlayer::CPlayer()
	: m_fTime(0.f), m_dwTempTick(0), m_fJumpX(0.f), m_fJumpY(0.f), m_fJumpPower(0.f),
	m_iHeadTileIdx(0), m_bMove(false), m_ePrevDir(DIR_LEFT), m_fShadowY(0.f),
	m_bTemp(false), m_eCurState(IDLE), m_ePreState(IDLE),
	m_pvecTile(nullptr), m_qltskrka(false), m_iMoney(0), m_iWaterTileOffset(0), m_bInWater(false),
	m_bDebugMovable(false), m_bHit(false), m_bHasKey(false), m_iArmorIdx(0)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	//m_tInfo = { WINCX * 0.5f + 24.f, WINCY * 0.5f + 24.f, PLAYERCX, PLAYERCY };
	m_tInfo = { 840, 337, PLAYERCX, PLAYERCY };
	m_pvecTile = CTileMgr::Get_Instance()->Get_TileVec();

	m_iTileIdx = Find_MyTileIdx();
	m_tInfo.fX = (*m_pvecTile)[m_iTileIdx]->Get_Info().fX;
	m_tInfo.fY = (*m_pvecTile)[m_iTileIdx]->Get_Info().fY - 24.f;
	m_fShadowY = m_tInfo.fY - (m_tInfo.fCY * 0.5f) + 4.f;
	
	m_fSpeed = 6.f;
	m_fDistance = 100.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Character/Player_head_left_.bmp", L"Player_Head_L");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Character/Player_head_right.bmp", L"Player_Head_R");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Character/Player_armor_left_.bmp", L"Player_Armor_L");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Character/Player_armor_right.bmp", L"Player_Armor_R");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Character/Player_Shadow.bmp", L"Player_Shadow");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Text/game_beatskipped_1.bmp", L"beatskipped1");
	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../content/texture/Text/game_beatskipped.bmp", L"beatskipped");

	m_pImgKey = L"Player_Head_L";
	m_eCurState = IDLE;
	m_ePreState = IDLE;
	m_eDir = DIR_UP;
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 100;
	m_tFrame.dwTime = GetTickCount64();
	m_dwTempTick = GetTickCount64();

	m_eRender = RENDER_GAMEOBJECT;
	m_fJumpPower = 9.5f;
	m_iHeadTileIdx = m_iTileIdx;

	m_iMaxHP = 6;
	m_iHP = 6;

	// ���� �÷��̾� init�� �� �ʼ��� ����־�� �ϴ� �����۵� ���⼭ ���� �� �����۸���Ʈ�� ������ ����?
	// �� ��ȿ������ �� ���� �ѵ� ����ϴ��� �ϴ� �����..
	// �÷��̾�� ������Ʈ�Ŵ������� �����ϹǷ� release���� ���� �ʿ�xxxx
	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CNormalShovel>::Create_Item(false));
	m_Itemlist[ITEM_SHOVEL].push_back(CObjMgr::Get_Instance()->Get_LastItem());
	m_Itemlist[ITEM_SHOVEL].back()->Set_Target(this);

	CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CDagger>::Create_Item(false));
	m_Itemlist[ITEM_WEAPON].push_back(CObjMgr::Get_Instance()->Get_LastItem());
	m_Itemlist[ITEM_WEAPON].back()->Set_Target(this);
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	Key_Input();
	Jumping();
	Get_TileX();
	Get_TileY();
	if (m_bHit)
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CHitRed>::Create(0));
		m_bHit = false;
	}

	//if (CKeyMgr::Get_Instance()->Key_Down('Q'))
	//{
	//	CObjMgr::Get_Instance()->Add_Object(OBJ_UI, CAbstractFactory<CSplash>::Create(m_iTileIdx));
	//	CObjMgr::Get_Instance()->Add_Object(OBJ_STAIR, CAbstractFactory<CWaterTile>::Create(m_iTileIdx));
	//}

	if (m_Itemlist[ITEM_ARMOR].empty() == false)
	{
		m_iArmorIdx = 5;
	}
	// 0�� �⺻(�ʾ���), 1�� ����, 2�� ü��, 3�� �÷���Ʈ
	// 5�� ����


	__super::Update_Rect();
	return OBJ_NOEVENT;
}
void CPlayer::Late_Update()
{
	Offset();
	__super::Move_Frame();
}

void CPlayer::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	HDC		hMemDChead = CBmpMgr::Get_Instance()->Find_Image(L"Player_Head_R");
	HDC		hMemDCarmor = CBmpMgr::Get_Instance()->Find_Image(L"Player_Armor_R");
	HDC		hMemDCshadow = CBmpMgr::Get_Instance()->Find_Image(L"Player_Shadow");	// �׸��� �� xy ��ǥ ����?
	HDC		hMemDCskiptext = CBmpMgr::Get_Instance()->Find_Image(L"beatskipped1");	// �׸��� �� xy ��ǥ ����?

	if (m_ePrevDir == DIR_LEFT)
	{
		hMemDChead = CBmpMgr::Get_Instance()->Find_Image(L"Player_Head_L");
		hMemDCarmor = CBmpMgr::Get_Instance()->Find_Image(L"Player_Armor_L");
	}
	if (m_eDir == DIR_UP || m_eDir == DIR_DOWN)
	{
		GdiTransparentBlt(hDC,
			m_tRect.left + iScrollX,
			(int)m_fShadowY + iScrollY, // �׸��� ���� ������ ����
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDCshadow,
			0,
			0,
			PLAYERCX,
			PLAYERCY,
			RGB(255, 0, 255));
	}
	else
	{// �¿� �̵� �� �׸��� y�� �̵� ���� 
		GdiTransparentBlt(hDC,
			m_tRect.left + iScrollX,
			(int)m_fShadowY + iScrollY, // �׸��� ���� ������ ����
			(int)m_tInfo.fCX,
			(int)m_tInfo.fCY,
			hMemDCshadow,
			0,
			0,
			PLAYERCX,
			PLAYERCY,
			RGB(255, 0, 255));
	}
	if (m_bInWater == true && m_iHeadTileIdx == m_iTileIdx)
	{
		m_iWaterTileOffset = 10;
	}
	else if (m_bInWater == false)
	{
		m_iWaterTileOffset -= 4;
		if (m_iWaterTileOffset < 0)
		{
			m_iWaterTileOffset = 0;
		}
	}

	GdiTransparentBlt(hDC,							//����
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY + m_iWaterTileOffset,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY - m_iWaterTileOffset,	// ���� ����
		hMemDCarmor,													
		(int)m_tInfo.fCX * m_tFrame.iFrameStart,
		(int)m_tInfo.fCY * m_iArmorIdx,
		PLAYERCX,
		PLAYERCY - m_iWaterTileOffset,			// ���⵵ ����
		RGB(255, 0, 255));

	GdiTransparentBlt(hDC,							// �Ӹ�
		m_tRect.left + iScrollX,			
		m_tRect.top + iScrollY + m_iWaterTileOffset,
		PLAYERCX,							
		PLAYERCY - m_iWaterTileOffset,
		hMemDChead,							
		PLAYERCX * m_tFrame.iFrameStart,	
		PLAYERCY * m_tFrame.iMotion,		
		PLAYERCX,							
		PLAYERCY - m_iWaterTileOffset,
		RGB(255, 0, 255));					

	//if (m_qltskrka == true)
	//{
	//	TCHAR szText[32];
	//	wsprintf(szText, L"������");
	//	TextOut(hDC, WINCX / 2 - 20, WINCY - 150 - 75, szText, lstrlen(szText));
	//}



	if (CBeatMgr::Get_Instance()->Get_BeatMissed())
	{
		GdiTransparentBlt(hDC,
			m_tRect.left + iScrollX - 14,
			m_tRect.top + iScrollY - 20,
			77,
			15,
			hMemDCskiptext,
			0,
			0,
			77,
			15,
			RGB(255, 0, 255));
	}

}

void CPlayer::Release()
{
}

bool CPlayer::Can_Move()
{
	float	fHeadX(0.f), fHeadY(0.f);
	fHeadX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
	fHeadY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY;

	if (m_bInWater == true)
		return false;

	return CTileMgr::Get_Instance()->Check_TileObject(m_iHeadTileIdx);

	CObj* pHeadWall = CTileMgr::Get_Instance()->Is_Wall_Exist(fHeadX, fHeadY);
 	CObj* pHeadItem = CObjMgr::Get_Instance()->Is_Item_Exist(m_iHeadTileIdx);
	CObj* pHeadMonster = CObjMgr::Get_Instance()->Is_Monster_Exist(m_iHeadTileIdx);

	if (pHeadWall != nullptr)		// �� �˻�
	{
		CTileMgr::Get_Instance()->Break_Wall(pHeadWall, static_cast<CShovel*>(m_Itemlist[ITEM_SHOVEL].front()));
		return false;
	}
	else if (pHeadMonster != nullptr)
	{
		//Attack
		{
			//pHeadMonster->Set_HP(static_cast<CWeapon*>(m_Itemlist[ITEM_WEAPON].front())->Get_Damage());
			CSoundMgr::Get_Instance()->StopSound(SOUND_EFFECT);
			CSoundMgr::Get_Instance()->PlaySound(L"sfx_general_hit.wav", SOUND_EFFECT, g_fVolume);
			CSoundMgr::Get_Instance()->PlaySound_AttackVoice();
		}
		return false;
	}
	else if (pHeadItem != nullptr) // ������ �˻�
	{
		Get_Item(pHeadItem);
		return true;
	}
	else
		return true;
	return true;
}

void CPlayer::Get_Item(CObj* _pItem)
{
	ITEMLIST	eItemType = dynamic_cast<CItem*>(_pItem)->Get_ItemType();
	switch (eItemType)
	{
	case ITEM_WEAPON:
		break;
	case ITEM_SHOVEL:
		if (!m_Itemlist[ITEM_SHOVEL].empty())
		{
			static_cast<CItem*>(m_Itemlist[ITEM_SHOVEL].back())->Set_OnMap(true);
			m_Itemlist[ITEM_SHOVEL].back()->Set_TileIdx(m_iHeadTileIdx);
			m_Itemlist[ITEM_SHOVEL].back()->Initialize();
			dynamic_cast<CItem*>(_pItem)->Set_OnMap(false);
			_pItem->Set_TileIdx(0);
			//_pItem->Set_Pos(0, 0);
			swap(m_Itemlist[ITEM_SHOVEL].back(), _pItem);

			/*m_Itemlist[ITEM_SHOVEL].pop_back();
			m_Itemlist[ITEM_SHOVEL].push_back(_pItem);*/
			
			CSoundMgr::Get_Instance()->StopSound(SOUND_EFFECT);
			CSoundMgr::Get_Instance()->PlaySound(L"sfx_pickup_weapon.wav", SOUND_EFFECT, g_fVolume);
		}
		else
		{
			m_Itemlist[ITEM_SHOVEL].push_back(_pItem);
			dynamic_cast<CItem*>(_pItem)->Set_OnMap(false);
		}
		break;
	case ITEM_ARMOR:
		break;
	case ITEM_HEAL:
		break;
	case ITEM_GOLD:
		break;
	case ITEM_END:
		break;
	default:
		break;
	}
}


void CPlayer::Jumping()		// �׳� �����ϴ� ��Ǹ� ����ϴ°�
{
	if (m_bMove) // ������ Ÿ���� �̵��ߴ°�
	{
		float fHeadX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
		float fHeadY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;
		float fCurX = (*m_pvecTile)[m_iTileIdx]->Get_Info().fX;
		float fCurY = (*m_pvecTile)[m_iTileIdx]->Get_Info().fY - 24.f;

		switch (m_eDir)
		{
		case DIR_LEFT:
			m_fJumpPower = 9.5f;

			if (fCurY < m_tInfo.fY)
			{
				m_tInfo.fY = fCurY;
				m_bMove = false;
				m_fTime = 0.f;
				m_iTileIdx = m_iHeadTileIdx;
			}
			else
			{
				m_tInfo.fX -= (m_fSpeed * cosf(45.f * PI / 180) * m_fTime);
				if (fHeadX > m_tInfo.fX)
					m_tInfo.fX = fHeadX;
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
			}
			break;
		case DIR_RIGHT:
			m_fJumpPower = 9.5f;
			if (fCurY < m_tInfo.fY)
			{
				m_tInfo.fY = fCurY;
				m_bMove = false;
				m_fTime = 0.f;
				m_iTileIdx = m_iHeadTileIdx;
			}
			else
			{
				m_tInfo.fX += (m_fSpeed * cosf(45.f * PI / 180) * m_fTime);
				if (fHeadX < m_tInfo.fX)
					m_tInfo.fX = fHeadX;
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.5f;
			}
			break;
		case DIR_UP:
			m_fJumpPower = 20.f;

			if (fHeadY > m_tInfo.fY)
			{
				m_tInfo.fY = fHeadY;
				m_fShadowY = fHeadY - 20.f;
				m_bMove = false;
				m_iTileIdx = m_iHeadTileIdx;
				m_fTime = 0.f;
			}
			else
			{
				m_tInfo.fY -= (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.1f;
				if ((m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) * 0.2f < 0)
				{
					m_tInfo.fY = fHeadY - 5.f;
					m_iTileIdx = m_iHeadTileIdx;
					m_fTime = 0.f;
				}
			}

			m_fShadowY += -2.f * m_fTime - (9.8f * m_fTime * m_fTime) * 0.45f;

			break;
		case DIR_DOWN:
			m_fJumpPower = 20.f;

			m_tInfo.fY += (m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime);
			if ((m_fJumpPower * sinf(45.f * PI / 180) * m_fTime) - (9.8f * m_fTime * m_fTime) < 0)
			{
				m_tInfo.fY = fHeadY;
				m_bMove = false;
				m_fShadowY = fHeadY - 20.f;
				m_iTileIdx = m_iHeadTileIdx;
				m_fTime = 0.f;
			}
			m_fShadowY -= -6.f * m_fTime - (9.8f * m_fTime * m_fTime);
			if (m_fShadowY > fHeadY - 20.f)
				m_fShadowY = fHeadY - 20.f;

			break;
		default:
			break;
		}
		m_fTime += 0.15f;

	}
	else
	{
		m_fTime = 0.f;
	}

}

void CPlayer::Offset()
{
	int		iOffSetminX = (WINCX >> 1) - 10;
	int		iOffSetmaxX = (WINCX >> 1) + 10;

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	//if (m_eDir == DIR_RIGHT || m_eDir == DIR_LEFT)
	{
		if (iOffSetminX > m_tInfo.fX + iScrollX)
			CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

		if (iOffSetmaxX < m_tInfo.fX + iScrollX)
			CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
	}

	int		iOffSetminY = (WINCY >> 1) - 10;
	int		iOffSetmaxY = (WINCY >> 1) + 10;
	
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	//if (m_eDir == DIR_UP || m_eDir == DIR_DOWN)
	//{
		if (iOffSetminY > m_fShadowY - 20.f + iScrollY)
			CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

		if (iOffSetmaxY < m_fShadowY - 20.f + iScrollY)
			CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);
	//}



	//int		iOffSetX = WINCX >> 1;

	//int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();

	//if (iOffSetX > m_tInfo.fX + iScrollX)
	//	CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	//if (iOffSetX < m_tInfo.fX + iScrollX)
	//	CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);
}

CObj* CPlayer::Create_Shield()
{
	return nullptr;
}

void CPlayer::Change_Motion()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case CPlayer::IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 100;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case CPlayer::WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 100;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case CPlayer::ATTACK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 2;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;

		case CPlayer::HIT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iMotion = 3;
			m_tFrame.dwSpeed = 200;
			m_tFrame.dwTime = GetTickCount64();
			break;

		}

		m_ePreState = m_eCurState;
	}

}


void CPlayer::Attack_Effect()
{
	if (static_cast<CWeapon*>(m_Itemlist[ITEM_WEAPON].front())->Get_WeaponType() == CWeapon::DAGGER_TYPE)
	{
		//CObjMgr::Get_Instance()->Add_Object(OBJ_ITEM, CAbstractFactory<CNormalShovel>::Create_Item(false));
		CObjMgr::Get_Instance()->Add_Object(OBJ_EFFECT, CAbstractFactory<CDaggerEffect>::Create(m_iHeadTileIdx));
	}
}

void CPlayer::Key_Input()
{
	float	fY(0.f);

	// ���⿡ ����Mgr->�ٹ���? ��..Ʈ��?

	//if (m_bBeatCorrect)
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))			// ����
		{
			if (BEATMGR->Get_AbleBeatInterval() == true || CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY || m_bDebugMovable)		// Ű �Է��� ������ �������� (�ݹ��� �� ~ �ݹ��� ��)
			{
				CBeatMgr::Get_Instance()->Set_PlayerActed(true);// �÷��̾� �ൿ ���� true
				CBeatMgr::Get_Instance()->Delete_Bar_Act();		// ���� �� ��Ʈ�� ����
				CBeatMgr::Get_Instance()->Set_ObjectAbleToMove(true);

				//if (BEATMGR->Get_BeatMissed() == true)
				//{
				//	BEATMGR->Set_BeatMissed(false);
				//}

				m_qltskrka = false;	// �Ⱥ�����
				m_eDir = DIR_LEFT;	// ����
				m_ePrevDir = DIR_LEFT;	// ����������
				m_fShadowY = m_tRect.top + 4.f; // �׸��� top ��ġ ����

				if (m_bMove == true) // lobby���� Ȯ���ϴ� �ڵ� �ʿ�? ������ �۵�x
				{
					m_tInfo.fX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;			// �ǵ��� �� : �̹� �����̰� �ִ� ���¿��� �ٽ� �Է½� ������ Ÿ�Ϸ� ��� �̵�
					m_tInfo.fY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;	// �ٵ� ���� ��: �ʵ�
					m_iTileIdx = m_iHeadTileIdx;
				}
				--m_iHeadTileIdx;	// ������ �ϴ� Ÿ��(����)
				if (Can_Move())		// �̵��� ������ �� 
				{
					m_bMove = true;	// jumping ���� (���� �̸��� �ٲٱ�?)
					m_tFrame.iFrameStart = 0; // �ִϸ��̼� ������ ����
				}
				else
					m_iHeadTileIdx = m_iTileIdx;	// �̵��� �ȵǸ� ������ Ÿ���� ����ϰ� ���� Ÿ�Ϸ� ����
			}
			else
			{
				CBeatMgr::Get_Instance()->Lose_BeatCombo();
				BEATMGR->Set_InputBeatMissed(true);
				m_qltskrka = true;		// !!������
			}
			if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY)
				CTileMgr::Get_Instance()->Tile_Shine();

#ifdef  _DEBUG

			cout << "�÷��̾� ��ġ : " << m_tInfo.fX << '\t' << m_tInfo.fY << endl;
			cout << "�÷��̾� ��ġ Ÿ�� : " << m_iTileIdx << endl;

#endif //  _DEBUG
		}

		else if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT))
		{
			if (BEATMGR->Get_AbleBeatInterval() == true || CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY || m_bDebugMovable)
			{
				CBeatMgr::Get_Instance()->Set_PlayerActed(true);
				CBeatMgr::Get_Instance()->Delete_Bar_Act();
				CBeatMgr::Get_Instance()->Set_ObjectAbleToMove(true);

				m_qltskrka = false;
				m_eDir = DIR_RIGHT;
				m_ePrevDir = DIR_RIGHT;
				m_fShadowY = m_tRect.top + 4.f;

				if (m_bMove == true)
				{
					m_tInfo.fX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
					m_tInfo.fY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;
					m_iTileIdx = m_iHeadTileIdx;
				}
				++m_iHeadTileIdx;
				if (Can_Move())
				{
					m_bMove = true;
					m_tFrame.iFrameStart = 0;
				}
				else
					m_iHeadTileIdx = m_iTileIdx;
			}
			else
			{
				CBeatMgr::Get_Instance()->Lose_BeatCombo();
				BEATMGR->Set_InputBeatMissed(true);
				m_qltskrka = true;
			}
			if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY)
				CTileMgr::Get_Instance()->Tile_Shine();

#ifdef  _DEBUG

			cout << "�÷��̾� ��ġ : " << m_tInfo.fX << '\t' << m_tInfo.fY << endl;
			cout << "�÷��̾� ��ġ Ÿ�� : " << m_iTileIdx << endl;

#endif //  _DEBUG
		}

		else if (CKeyMgr::Get_Instance()->Key_Down(VK_UP))
		{
			if (BEATMGR->Get_AbleBeatInterval() == true || CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY || m_bDebugMovable)
			{
				m_qltskrka = false;
				CBeatMgr::Get_Instance()->Set_PlayerActed(true);
				CBeatMgr::Get_Instance()->Delete_Bar_Act();
				CBeatMgr::Get_Instance()->Set_ObjectAbleToMove(true);
				//m_tInfo.fY -= m_fSpeed;
				m_eDir = DIR_UP;
				m_fShadowY = m_tRect.top + 4.f;


				if (m_bMove == true)
				{
					m_tInfo.fX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
					m_tInfo.fY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;
					m_iTileIdx = m_iHeadTileIdx;
				}
				m_iHeadTileIdx -= TILEX;
				if (Can_Move())
				{
					m_bMove = true;
					m_tFrame.iFrameStart = 0;
				}
				else
					m_iHeadTileIdx = m_iTileIdx;
			}
			else
			{
				CBeatMgr::Get_Instance()->Lose_BeatCombo();
				BEATMGR->Set_InputBeatMissed(true);
				m_qltskrka = true;
			}

			if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY)
				CTileMgr::Get_Instance()->Tile_Shine();

#ifdef  _DEBUG

			cout << "�÷��̾� ��ġ : " << m_tInfo.fX << '\t' << m_tInfo.fY << endl;
			cout << "�÷��̾� ��ġ Ÿ�� : " << m_iTileIdx << endl;

#endif //  _DEBUG
		}

		else if (CKeyMgr::Get_Instance()->Key_Down(VK_DOWN))
		{
			if (BEATMGR->Get_AbleBeatInterval() == true || CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY || m_bDebugMovable)
			{
				m_qltskrka = false;
				CBeatMgr::Get_Instance()->Delete_Bar_Act();
				//m_tInfo.fY += m_fSpeed;
				m_eDir = DIR_DOWN;
				m_fShadowY = m_tRect.top + 4.f;
				CBeatMgr::Get_Instance()->Set_PlayerActed(true);
				CBeatMgr::Get_Instance()->Set_ObjectAbleToMove(true);

				if (m_bMove == true)
				{
					m_tInfo.fX = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fX;
					m_tInfo.fY = (*m_pvecTile)[m_iHeadTileIdx]->Get_Info().fY - 24.f;
					m_iTileIdx = m_iHeadTileIdx;
				}
				m_iHeadTileIdx += TILEX;
				if (Can_Move())
				{
					m_bMove = true;
					m_tFrame.iFrameStart = 0;
				}
				else
					m_iHeadTileIdx = m_iTileIdx;
			}
			else
			{
				CBeatMgr::Get_Instance()->Lose_BeatCombo();
				BEATMGR->Set_InputBeatMissed(true);
				m_qltskrka = true;
			}

			if (CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY)
				CTileMgr::Get_Instance()->Tile_Shine();
#ifdef  _DEBUG

			cout << "�÷��̾� ��ġ : " << m_tInfo.fX << '\t' << m_tInfo.fY << endl;
			cout << "�÷��̾� ��ġ Ÿ�� : " << m_iTileIdx << endl;

#endif //  _DEBUG
		}
		//m_bBeatCorrect = false;

	}
	if (CKeyMgr::Get_Instance()->Key_Down('E'))
	{
		if (m_Itemlist[ITEM_HEAL].empty() == false)
		{
			if (BEATMGR->Get_AbleBeatInterval() == true || CSceneMgr::Get_Instance()->Get_CurSceneID() == SC_LOBBY || m_bDebugMovable)
			{
				static_cast<CHealing*>(m_Itemlist[ITEM_HEAL].front())->Use_Item();
				m_Itemlist[ITEM_HEAL].pop_front();
				m_qltskrka = false;
				CBeatMgr::Get_Instance()->Delete_Bar_Act();
				CBeatMgr::Get_Instance()->Set_PlayerActed(true);
				CBeatMgr::Get_Instance()->Set_ObjectAbleToMove(true);
			}
		}
		else
		{
			CBeatMgr::Get_Instance()->Lose_BeatCombo();
			BEATMGR->Set_InputBeatMissed(true);
			m_qltskrka = true;
		}
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		CBeatMgr::Get_Instance()->Plus_BeatCombo();
 		//m_iMoney += 100; 
		//m_bHit = true;
		m_bDebugMovable = !m_bDebugMovable;
		//m_bHasKey = !m_bHasKey;
	}
	if (CKeyMgr::Get_Instance()->Key_Down('F'))
	{
		m_iMoney += 100;
		m_iHP = m_iMaxHP;
	}

}