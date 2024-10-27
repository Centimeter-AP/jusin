#ifndef PCH_H
# define PCH_H

#include <iostream>
#include <unistd.h>

#include "MainGame.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"

enum CLASS{
	WARRIOR = 1,
	MAGE,
	ROGUE
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