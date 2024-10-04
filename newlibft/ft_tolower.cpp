#include <iostream>

using namespace std;

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A')); // c + 32
	else
		return c;
	return 0;
}
