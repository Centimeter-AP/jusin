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

};

#endif

