#pragma once
#ifndef FIELD_H
# define FIELD_H

# include <iostream>

class CField
{
	private:
		int iStep;
	public:
		CField();
		~CField();

		void	Initialize();
		void	Update();
		void	Release();

		void		Search();
		void		Find();
		const char*	Text(int _iFlag);
};

#endif
