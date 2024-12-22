#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1	

#define VK_MAX				0xff

#define TILEX				51
#define TILEY				50
#define	TILECX				48
#define	TILECY				48

#define PLAYERCX			TILECX
#define PLAYERCY			TILECY

#define G_FORCE                9.80665f
#define SQUARE(X)            (X)*(X)
#define RADIAN(Degree)        (Degree)*PI/180.f
#define DEGREE(Radian)        (Radian)*180.f/PI

#define KEY_DOWN(X)        CKeyMgr::Get_Instance()->Key_Down(X)
#define KEY_PRESSING(X)        CKeyMgr::Get_Instance()->Key_Pressing(X)
#define KEY_UP(X)        CKeyMgr::Get_Instance()->Key_Up(X)

#define GET_IMAGE(X) CBmpMgr::Get_Instance()->Find_Image(X)
#define INSERT_BMP CBmpMgr::Get_Instance()->Insert_Bmp

#define SCROLLX CScrollMgr::Get_Instance()->Get_ScrollX()
#define SCROLLY CScrollMgr::Get_Instance()->Get_ScrollY()

#define ADD_OBJ CObjMgr::Get_Instance()->Add_Object
#define CREATE_OBJ(X) CAbstractFactory< X >::Create_Obj
#define GET_PLAYER CObjMgr::Get_Instance()->Get_Player()

#define	STAGE1BPM		115;

extern HWND		g_hWnd;
extern float	g_fVolume;

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum OBJID { OBJ_PLAYER, OBJ_BULLET, OBJ_MONSTER, OBJ_ITEM, OBJ_WALL, OBJ_BUTTON, OBJ_EFFECT, OBJ_UI, OBJ_END };

enum RENDERID { RENDER_BACKGROUND, RENDER_MAPITEM, RENDER_GAMEOBJECT, RENDER_UI, RENDER_EFFECT, RENDER_END };

enum SCENEID { SC_LOGO, SC_MENU, SC_EDIT, SC_STAGE, SC_END };

enum CHANNELID { SOUND_EFFECT, SOUND_VOCAL, SOUND_BGM, SOUND_END };

enum TILEOPTIONID { OPT_TILE, OPT_WALL, OPT_ITEM, OPT_ENTITY, OPT_TRAP, OPT_END };

enum WALLTYPE { DIRT_WALL, STONE_WALL, SHOP_WALL, BEDROCK, WALL_END };

enum WALLPOWER { POWER_ONE = 1, POWER_TWO, POWER_THREE, POWER_BOMB = 10, POWER_NOEXCEPTION = 999, POWER_END };

enum ITEMLIST {ITEM_WEAPON, ITEM_SHOVEL, ITEM_ARMOR, ITEM_HEAL, ITEM_BOMB, ITEM_END};
//enum WALLTYPET { WALL_ONE, WALL_TWO, WALL_THREE_FIRE, WALL_FOUR_ICE, WALL_FOUR, WALL_FIVE, WALL_MISC, WALL_END };
//
//enum WALLMISCNUMBER { SHOP_WALL = 0, BEDROCK = 4, DOOR_DOWN = 12, DOOR_LEFT, WALL_ONE_ROCK = 29, WALL_ONE_ROCKX = 30, MISC_END };

enum TILEOBJECT {TOBJ_ENTITY, TOBJ_ITEM, TOBJ_WALL, TOBJ_TRAP, TOBJ_END};

enum DrawID {   };

typedef struct tagInfo
{
	float		fX, fY;
	float		fCX, fCY;	// 가로, 세로 길이

}INFO;

typedef struct tagLinePoint
{
	float		fX, fY;

	tagLinePoint()	{ZeroMemory(this, sizeof(tagLinePoint));}
		tagLinePoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{	}

}LINEPOINT;

typedef struct tagLine
{
	LINEPOINT	tLPoint;
	LINEPOINT	tRPoint;

	tagLine() { 	ZeroMemory(this, sizeof(tagLine));	}
	tagLine(LINEPOINT& _tLPoint, LINEPOINT& _tRPoint)
		: tLPoint(_tLPoint), tRPoint(_tRPoint) {	}

}LINE;

typedef struct tagFrame
{
	int		iFrameStart;
	int		iFrameEnd;
	int		iMotion;
	ULONGLONG	dwSpeed;
	ULONGLONG	dwTime;

}FRAME;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

struct tagFinder
{
public:
	tagFinder(const TCHAR* pString) : m_pString(pString) {}

public:
	template<typename T>
	bool	operator()(T& rObj)
	{
		return !lstrcmp(m_pString, rObj.first);
	}

private:
	const TCHAR* m_pString;
};

struct DeleteMap
{
public:
	template<typename T>
	void	operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};