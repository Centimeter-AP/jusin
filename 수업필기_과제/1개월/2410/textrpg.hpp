#ifndef TEXTRPG_HPP
# define TEXTRPG_HPP

# include <iostream>
# include <unistd.h>

using namespace std;

typedef struct s_info{
	char	sName[32];
	int		iHp;
	int		iMaxHp;
	int		iAtk;
	int		iCritChance;
}INFO;

typedef struct s_player{
	INFO	tInfo;	
	int		iLvl;
	int		iExp;
	int		iMaxExp;
}PLAYER;

enum CLASS{
	WARRIOR = 1,
	MAGE,
	ROGUE
};

enum MONSTER{
	EASY = 1,
	NORMAL,
	HARD,
	HEAL,
	BACK
};

enum BATTLE{
	ATTACK = 1,
	FLEE
};

enum FIELD{
	DUNGEON = 1,
	EXITGAME
};

//	gamesystem.cpp
void	CinFailException(bool i);
void	Exit_Game();

//	initializer.cpp
INFO	*Make_Class();
INFO	*Make_Enemy(int _iInput);

void	Print_Info(INFO	*_tInfo);
void	Attack(INFO *_tClass, INFO *_tEnemy);
void	Make_Hp_Full(INFO *_tClass);


void	Main_Game_Loop();
int		Field(INFO *_tClass);
void	Enter_Dungeon(INFO *_tClass);
void	Battle(INFO *_tClass, int _iEnemyNum);

#endif