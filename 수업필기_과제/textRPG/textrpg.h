#ifndef TEXTRPG_HPP
# define TEXTRPG_HPP

# define _CRT_SECURE_NO_WARNINGS

# include <iostream>
# include <unistd.h>
# include <stdlib.h>

# define		STR_MIN		32
# define		STR_MAX		256

# define		DELETE_INFO(POINTER)		if(POINTER){delete POINTER; POINTER = nullptr;}

using namespace std;


// typedef struct s_lvlpoints{
// 	int		iAtkPoint;
// 	int		iHpPoint;
// 	int		iEquipPoint;
// }POINTS;

typedef struct s_player{
	int		iLvl;
	int		iExp;
	int		iMaxExp;
	int		iEquip;
	// POINTS	tPoints;
}PLAYER;

struct INFO{
	char	sName[STR_MIN];
	int		iHp;
	int		iMaxHp;
	int		iAtk;
	int		iCritChance;
	bool	isMob;
	PLAYER	tPlayerInfo;
};

enum HPVALUE{
	HPMAX = 1,
	HPEIGHTYP,
	HPHALF,
	HPFOURTYP,
	HPTWENTYP,
	HPZEROP
};

enum CLASS{
	WARRIOR = 1,
	MAGE,
	ROGUE,
	LOAD
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

enum EQUIP{
	NOEQUIP = 0
};

//	gamesystem.cpp
void	CinFailException(bool i);
void	Exit_Game();
void	Save_Game(INFO *tInfo);
void	Load_Game(INFO *tInfo);

//	initializer.cpp
INFO	*Make_Class();
INFO	*Make_Enemy(int _iInput);
void	Init_info(INFO *tInfo, const char *_sName, int _iHp, int _iAtk, bool _isMob = false);

//	function.cpp
void	Print_Info(INFO	*_tInfo);
void	Attack(INFO *_tClass, INFO *_tEnemy);
void	Heal_Hp(INFO *_tClass, int _iValue);
void	Healing_Station(INFO *_tClass);
void	imsi();

//	textrpg.cpp
void	Main_Game_Loop();
int		Field(INFO *_tClass);
void	Enter_Dungeon(INFO *_tClass);
void	Battle(INFO *_tClass, int _iEnemyNum, bool _isForced = false);

#endif