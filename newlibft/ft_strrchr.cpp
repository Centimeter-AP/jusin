#include "libft.hpp"

using namespace std;

char	*ft_strrchr(const char *s, int c)
{
	const char *res(NULL);

	while (*s)
	{
		if (*s == c)
			res = s;
	}
	return (char *)res;
}
