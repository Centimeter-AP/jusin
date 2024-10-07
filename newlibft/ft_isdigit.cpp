#include "libft.hpp"

using namespace std;

int	ft_isdigit(int c)
{
	if ('0' <= c && '9' >= c)
		return 1;
	return 0;
}
