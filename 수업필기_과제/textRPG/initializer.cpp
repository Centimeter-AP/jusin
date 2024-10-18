#include "textrpg.hpp"

void	Init_info(INFO *tInfo, const char *_sName, int _iHp, int _iAtk, bool _isMob)
{
	strcpy(tInfo->sName, _sName);
	tInfo->iMaxHp = _iHp;
	tInfo->iHp = tInfo->iMaxHp;
	tInfo->iAtk = _iAtk;
	tInfo->iCritChance = 10;
	if (!_isMob)
	{
		tInfo->tPlayerInfo = new PLAYER;
		tInfo->tPlayerInfo->iExp = 0;
		tInfo->tPlayerInfo->iLvl = 1;
		tInfo->tPlayerInfo->iMaxExp = 100;
		tInfo->tPlayerInfo->iEquip = 0;
	}
	else
		tInfo->tPlayerInfo = nullptr;
}

INFO	*Make_Class()
{
	INFO	*tTmp = new INFO;
	int		iInput(0);

	while (1)
	{
		system("cls");
		cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
		cin >> iInput;
		if (cin.fail() || iInput > 3 || iInput < 1) {
			CinFailException(cin.fail()); continue;
		}
		break;
	}

	switch (iInput)
	{
	case WARRIOR:
		Init_info(tTmp, "전사", 100, 10);
		break;

	case MAGE:
		Init_info(tTmp, "마법사", 90, 12);
		break;

	case ROGUE:
		// Init_info(tTmp, "도적", 115, 9);
		Load_Game(tTmp);
		break;
	
	default:
		return nullptr;
	}
	return tTmp;
}

INFO	*Make_Enemy(int _iInput)
{
	INFO	*tTmp = new INFO;

	switch (_iInput)
	{
	case EASY:
		Init_info(tTmp, "초급 몬스터", 30, 5, true);
		break;

	case NORMAL:
		Init_info(tTmp, "중급 몬스터", 50, 7, true);
		break;

	case HARD:
		Init_info(tTmp, "상급 몬스터", 90, 9, true);
		break;
	
	default:
		return nullptr;
	}
	return tTmp;
}
