#include <iostream>
#include <unistd.h>

int main()
{
	while(1)
	{
		system("leaks 17305");
		usleep(100000);
	}
	return 0;
}
