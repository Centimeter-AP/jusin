#include <iostream>
#include <unistd.h>
#include <curses.h>

using namespace std;

#define ESC "\033["
#define CLOSEBOX "\033[" << iPosX + 1 << "C" << "\033[" << _iW << "C│" << endl

#define YELLOW		"\033[1;43m"
#define GREEN		"\033[0;42m"
#define RED			"\033[0;41m"
#define PURPLE		"\033[0;45m"
#define WHITE		"\033[0;30;47m"
#define NOCOLOR		"\033[0m"

enum KEYIN{
	KUP = 72,
	KDOWN = 80,
	KLEFT = 75,
	KRIGHT = 77
};

void	PrintBox(int _iW, int _iH, int iPosX = 1, int iPosY = 1);
void	BoxTop(int _iW, int iPosX = 1, int iPosY = 1);
void	BoxBottom(int _iW, int iPosX = 1, int iPosY = 1);


void	PrintBox(int _iW, int _iH, int iPosX, int iPosY)
{
	BoxTop(_iW, iPosX, iPosY);
	// cout << "\033[H\033[" << iPosY << "B";
	// cout << "\033[" << iPosX << "C┌"; for(int i = 0; i < _iW; ++i) cout << "─"; cout << "┐" << endl;

	cout << ESC << iPosX << "C│" << "  " << "Hello World\r"	<< CLOSEBOX;
	cout << ESC << iPosX << "C│" << "  " << "\r"			<< CLOSEBOX;
	cout << ESC << iPosX << "C│" << "  " << "1. What?\r"	<< CLOSEBOX;
	cout << ESC << iPosX << "C│" << "  " << "2. Bye\r"		<< CLOSEBOX;
	cout << ESC << iPosX << "C│" << "  " << WHITE << "3." << NOCOLOR << " Here\r"		<< CLOSEBOX;
	// for(int i = 0; i < _iH; ++i) cout << "\033[" << iPosX << "C│\033[" << _iW << "C│" << endl;
	// cout << "\033[" << iPosX << "C└"; for(int i = 0; i < _iW; ++i) cout << "─"; cout << "┘" << endl;
	BoxBottom(_iW,iPosX,iPosY);
	
}

void	PrintText(int iPosX, int iPosY, char * sText)
{
	
}

void	BoxTop(int _iW, int iPosX, int iPosY)
{
	cout << "\033[H\033[" << iPosY << "B";
	cout << "\033[" << iPosX << "C┌"; for(int i = 0; i < _iW; ++i) cout << "─"; cout << "┐" << endl;
}
void	BoxBottom(int _iW, int iPosX, int iPosY)
{
	cout << "\033[" << iPosX << "C└"; for(int i = 0; i < _iW; ++i) cout << "─"; cout << "┘" << endl;
}

int main()
{
	int iInput(0), iKey(0);
	system("clear");
	// PrintBox(30, 5);
	
	// PrintBox(30, 5, 40, 8);
	while (1)
	{
		PrintBox(30, 5, 40);
		iInput = getch();
		if (iInput == 224)
		{
			iInput = getch();
			if (iInput == KUP || iInput == KDOWN || iInput == KLEFT || iInput == KRIGHT)
				iKey = iInput;
		}
	}


	return 0;
}
