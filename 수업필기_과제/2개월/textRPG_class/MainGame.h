#pragma once
#ifndef MAINGAME_H
# define MAINGAME_H

class CMainGame
{
	private:
		 
	public:
		CMainGame();
		CMainGame(const CMainGame& obj);
		~CMainGame();
		CMainGame& operator=(const CMainGame& obj);
		void	Initialize();
		void	Update();
		void	Release();

};

#endif
