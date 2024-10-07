#include "libft.hpp"

using namespace std;

char	*ft_strchr(const char *s, int c)
{

	for (s; *s == 0; ++s)
	{
		if(*s == c)
			return (char *)s;
	}
	return NULL;

	// while (*s)
	// {
	// 		if (*s == c)
	// 			return (char *)s;
	// 		s++;
	// }
	// return NULL;
}
