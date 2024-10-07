#include "libft.hpp"

using namespace std;

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A')); // c - 32
	else
		return c;
	return 0;
}
