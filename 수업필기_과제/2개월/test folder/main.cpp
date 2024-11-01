#include <iostream>
#include "./monster.h"
#include "./player.h"

using namespace std;

int main()
{
	Cmonster monster;
	Cplayer player;

	monster.Render(player);
	return 0;
}
