#pragma once

#define WINCX      800
#define WINCY      600

#define GAME_WINCX      600
#define GAME_WINCY      550

#define GAME_WIN_LEFT      (WINCX - GAME_WINCX) * 0.5f
#define GAME_WIN_TOP      (WINCY - GAME_WINCY) * 0.5f
#define GAME_WIN_RIGHT      (WINCX - GAME_WINCX) * 0.5f + GAME_WINCX
#define GAME_WIN_BOTTOM      (WINCY - GAME_WINCY) * 0.5f + GAME_WINCY

#define PURE	=0
#define	PI		3.141592f
#define	SQUARE(N)	((N) * (N))

extern HWND	g_hWnd;

template<typename T>
void	Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX, fY;
	float	fCX, fCY;
}INFO;

enum KDIRECTION
{
	KUP,
	KDOWN,
	KLEFT,
	KRIGHT,
	KEND
};

enum OBJLIST
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_BULLET,
	OBJ_ROTBULLET,
	OBJ_SUBPLAYER,
	OBJ_END
};

enum OBJSTATUS
{
	STAT_DEAD,
	STAT_NOEVENT
};