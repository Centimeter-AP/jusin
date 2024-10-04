#include <iostream>

using namespace std;

int	ft_isascii(int c)
{
	if (c >= CHAR_MIN && c <= CHAR_MAX)
		return 1;
	else
		return 0;
// 	isascii(int _c)
//	{
// 		return ((_c & ~0x7F) == 0);
//	}
//	헤더에 있는 함수 원형 패왕색패기 
}
