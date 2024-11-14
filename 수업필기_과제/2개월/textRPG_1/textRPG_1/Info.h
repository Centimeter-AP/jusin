#pragma once

#define SAFEDELETE(P) if(P){ delete P; P = nullptr; }
#define CINEXCEPTION(P) if (cin.fail() || iInput > P || iInput < 1) {CSystem::CinFailException(cin.fail()); continue;}


struct INFO {
	int		iHP;
	int		iMaxHP;
	int		iAtk;
	int		iCritChance;
	int		iCritical;
	char	szName[32];
	int		iGold;
};

struct PLAYERINFO {
	int		iMaxExp;
	int		iExp;
	int		iLvl;
};

struct MONSTERINFO {
	int		iLvl;
	float	iInitHP;
	float	iInitAtk;
};


enum CLASS {
	WARRIOR = 1,
	MAGE,
	ROGUE
};

enum MENU {
	FIELD = 1,
	SHOP,
	SAVE,
	EXIT
};

enum FIELD {
	EASY = 1,
	NORMAL,
	HARD,
	BACK,
	HEAL
};

enum COMMENT {
	RAND1 = 0,
	RAND2,
	RAND3,
	RAND4,
	NEARHEAL = 10,
	NEARBOSS,
	NEARITEM,
	NEARGOLD
};

enum FFLAG {
	CALM = 0,
	TENSION,
	DANGER
};

enum MAXNUM {
	ARMORINVMAX = 5,
	ITEMINVMAX = 4
};

enum ARMORSLOT {
	ARMOR_HEAD = 0,
	ARMOR_BODY,
	ARMOR_GLOVE,
	ARMOR_FEET,
	ARMOR_WEAPON,
	ARMOR_ACC,
	ARMOR_END
};


#define YELLOW		"\033[1;43m"
#define GREEN		"\033[0;42m"
#define RED			"\033[0;41m"
#define PURPLE		"\033[0;45m"
#define WHITE		"\033[0;30;47m"
#define NOCOLOR		"\033[0m"


