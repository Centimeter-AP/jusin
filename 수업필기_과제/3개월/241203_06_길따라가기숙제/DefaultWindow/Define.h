#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define OBJ_NOEVENT			0
#define OBJ_DEAD			1	

extern HWND		g_hWnd;

enum DIRECTION { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN, DIR_LU, DIR_RU, DIR_END };

enum OBJID { OBJ_PLAYER, OBJ_BULLET, OBJ_MONSTER, OBJ_MOUSE, OBJ_SHIELD, OBJ_BUTTON, OBJ_END };

typedef struct tagInfo
{
	float		fX, fY;
	float		fCX, fCY;	// 가로, 세로 길이

}INFO;

typedef	struct tagLinePoint
{
	float	fX, fY;

	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }//우와~
	tagLinePoint(float _X, float _Y) : fX(_X), fY(_Y) {  }
}LINEPOINT;




template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}