/*	별찍기	*/
// *
// **
// ***
// ****
// *****

// *****
// ****
// ***
// **
// *

//     *
//    **
//   ***
//  ****
// *****

// *****
//  ****
//   ***
//    **
//     *

#include <iostream>

using namespace std;

int main()
{
	int iInput(0);
	cin >> iInput;
	for (int i = 1; i < iInput + 1; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
	for (int i = iInput; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;
	for (int i = iInput; i > 0; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			cout << " ";
		}
		for (int j = iInput + 1; j > i; --j)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "---------------------------------" << endl;

	for (int i = iInput; i > 0; --i)
	{
		for (int j = 0; j < iInput - i; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	
	return 0;
}
