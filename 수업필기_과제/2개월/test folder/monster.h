#pragma once
#ifndef MONSTER_CPP
# define MONSTER_CPP

# include <iostream>
# include "player.h"

using namespace std;

class Cmonster
{
	private:
		int i;
	public:
		Cmonster():i(100){};
		~Cmonster(){};
		void Render(Cplayer &obj)
		{
			cout << obj.A << endl;
		}
};

#endif
