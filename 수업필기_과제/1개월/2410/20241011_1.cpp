#include <iostream>
//strlen
using namespace std;

size_t	Fstrlen(const char *s);
void	Freverse(const char *s);

int main()
{
	char szInput[2048] = {};

	cout << "문자열을 입력해주세요. : ";
	cin >> szInput;

	cout << "문자열의 길이: " << Fstrlen(szInput) << endl;
	cout << "(strlen)문자열의 길이: " << strlen(szInput) << endl;
	
	Freverse(szInput);

	return 0;
}

size_t Fstrlen(const char *s)
{
	size_t	i(0);
	while (*(s + i))
		i++;
	return i;
}

void	Freverse(const char *s)
{
	for (int i = Fstrlen(s); i > 0; --i)
	{
		cout << s[i - 1];
	}
	cout << endl;
}
