#include <iostream>

// 숙제 풀이 보면 좋다 

using namespace std;

int main()
{
	FILE	*fOrigin = nullptr;
	FILE	*fCopy = nullptr;
	int		*sCopy = new int[128];

	fOrigin = fopen("./Image.jpg", "rb");
	fCopy = fopen("./Copied.jpg", "wb");

	if (fOrigin && fCopy)
	{
		while (!feof(fOrigin))
		{
			fread(sCopy, sizeof(sCopy), 100, fOrigin);
			fwrite(sCopy, sizeof(sCopy), 100, fCopy);
		}
	}
	else
	{
		cout << "something went wrong" << endl;
	}
	delete[] sCopy;
	fclose(fOrigin);
	fclose(fCopy);
	return 0;
}
