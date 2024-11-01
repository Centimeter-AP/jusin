#ifndef INFO_H
# define INFO_H

#define SAFEDELETE(P) if(P){ delete P; P = nullptr; }
#define CINEXCEPTION(P) if (cin.fail() || iInput > P || iInput < 1) {CSystem::CinFailException(cin.fail()); continue;}


struct INFO{
	int		iHP;
	int		iMaxHP;
	int		iAtk;
	int		iCritChance;
	int		iCritical;
	char	szName[32];
};

struct PLAYERINFO{
	int		iMaxExp;
	int		iExp;
	int		iLvl;
};

struct MONSTERINFO{
	int		iGiveExp;
};


enum CLASS {
	WARRIOR = 1,
	MAGE,
	ROGUE
};

enum MENU{
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

#define YELLOW		"\033[1;43m"
#define GREEN		"\033[0;42m"
#define RED			"\033[0;41m"
#define PURPLE		"\033[0;45m"
#define WHITE		"\033[0;30;47m"
#define NOCOLOR		"\033[0m"



#endif