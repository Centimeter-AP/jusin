#pragma once
#ifndef PLAYER_CPP
# define PLAYER_CPP

# include <iostream>
// class Cmonster;
class Cplayer
{
	private:
		int A;
		friend class Cmonster;
	public:
		Cplayer():A(10){};
		~Cplayer(){};
		// void Play(Cmonster &obj);

};

#endif

