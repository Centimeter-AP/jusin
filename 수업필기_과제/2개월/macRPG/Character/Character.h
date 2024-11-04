#pragma once
#ifndef CHARACTER_H
# define CHARACTER_H

# include "../Info.h"

class CItem;

class CCharacter
{
	protected:
		INFO	mInfo;
		CItem*	pItem[4];

	public:
		CCharacter();
		virtual ~CCharacter();
		
		virtual void	Initialize() = 0;
		virtual void	Release() = 0;
	public:
		INFO*	Get_Info(){ return &mInfo; }
		int		Get_CritDamage();

	public:
		virtual void	Print_Info() = 0;
		void	Attack(CCharacter &obj);
		
};

#endif

