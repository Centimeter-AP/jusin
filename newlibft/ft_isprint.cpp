#include <iostream>

using namespace std;

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return 1;
	else
		return 0;
}
