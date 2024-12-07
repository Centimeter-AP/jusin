#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1
#define OBJ_IGNORE			2

#define G_FORCE                9.80665f
#define SQUARE(X)            (X)*(X)
#define RADIAN(Degree)        (Degree)*PI/180.f
#define DEGREE(Radian)        (Radian)*180.f/PI

#define VK_MAX				0xff

#define PL_CX		42.f
#define PL_CY		48.f
#define TILE_CXY	32.f

extern HWND		g_hWnd;

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum OBJID { OBJ_PLAYER, OBJ_BULLET, OBJ_MONSTER, OBJ_MOUSE, OBJ_SHIELD, OBJ_BUTTON, OBJ_OBSTACLE, OBJ_END };

typedef struct tagInfo
{
	float		fX, fY;
	float		fCX, fCY;	// 가로, 세로 길이

}INFO;

typedef struct tagFloatPoint
{
	float		fX, fY;

	tagFloatPoint()	{ZeroMemory(this, sizeof(tagFloatPoint));}
	tagFloatPoint(float _fX, float _fY)
		: fX(_fX), fY(_fY)
	{	}
	tagFloatPoint operator +(tagFloatPoint& rhs)
	{
		return (tagFloatPoint(fX + rhs.fX, fY + rhs.fY));
	}
	tagFloatPoint operator +(int i)
	{
		return (tagFloatPoint(fX + (float)i, fY + (float)i));
	}

}FPOINT;


typedef struct tagAniInfo
{
	FPOINT	tLT;
	FPOINT	tSize;
	INFO	tTargetInfo;
	float	fDuration;
	int		iFrameCount;
}ANINFO;

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