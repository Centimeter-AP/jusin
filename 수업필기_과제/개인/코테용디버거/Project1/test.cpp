#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	vector<int> inputvec;
	while (--N)
	{
		int inputk(0), inputn(0);
		cin >> inputk >> inputn;
		inputvec.push_back(inputk);
		inputvec.push_back(inputn);
	}



	return 0;
}