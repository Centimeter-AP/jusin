#pragma once

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

typedef struct tagInfo
{
	char	szName[32];
	int		iHp, iAttack;

}INFO;