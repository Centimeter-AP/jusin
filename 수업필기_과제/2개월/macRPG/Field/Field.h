#pragma once
#ifndef FIELD_H
# define FIELD_H

# include <iostream>

class CCharacter;

class CField
{
	private:
		int		iStep;
		int		iMaxStep;
		int		iEncounterFlag;
		CCharacter *Player;
		CCharacter *Monster;

	public:
		CField();
		~CField();

		void	Initialize();
		void	Update();
		void	Release();

		void	Set_Player(CCharacter *pPlayer) { Player = pPlayer; }
		void	Set_Step(int src) { iStep = src; };

		void	Random_Encounter();
		int		Battle();

		void		Search();
		void		Find();
		const char*	Text(int _iFlag);
};

#endif
