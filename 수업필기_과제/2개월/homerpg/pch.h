#ifndef PCH_H
# define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <unistd.h>
#include <Windows.h>
#include "CMainGame.h"
#include "CPlayer.h"
#include "CMonster.h"

#ifdef _DEBUG            // 메모리 누수 체크 매크로

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )  
#define new DBG_NEW 

#endif
#endif
    // 메모리 누수 체크 명령어


enum CLASS {
	WARRIOR = 1,
	MAGE,
	ROGUE
};

enum FIELD {
	EASY = 1,
	NORMAL,
	HARD,
	BACK,
	HEAL
};


using namespace std;

#define YELLOW		"\033[1;43m"
#define GREEN		"\033[0;42m"
#define RED			"\033[0;41m"
#define PURPLE		"\033[0;45m"
#define WHITE		"\033[0;30;47m"
#define NOCOLOR		"\033[0m"

#define CINEXCEPTION(P) if (cin.fail() || iInput > P || iInput < 1) {CinFailException(cin.fail()); continue;}
#define SAFE_DELETE(P) if(P){delete P; P = nullptr;}

#endif