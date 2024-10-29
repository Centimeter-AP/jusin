#ifndef INFO_H
# define INFO_H

#define SAFEDELETE(P) if(P){ delete P; P = nullptr; }


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



#endif