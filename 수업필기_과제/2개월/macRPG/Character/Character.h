#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include "../Info.h"

class CCharacter
{
	protected:
		INFO	mInfo;

	public:
		CCharacter();
		virtual ~CCharacter();
		
		virtual void	Initialize();
		virtual void	Release();
	public:
		INFO*	Get_Info(){ return &mInfo; }
		int		Get_CritDamage();

	public:
		virtual void	Attack(CCharacter &obj) = 0;
		
};

#endif

