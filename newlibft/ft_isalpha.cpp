#include <iostream>

using namespace std;

int ft_isalpha(int c)
{
	if ('A' <= c && 'Z' >= c)
		return 1;
	else if ('a' <= c && 'z' >= c)
		return 2;
	else
		return 0;
}
