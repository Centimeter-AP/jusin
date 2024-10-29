#include <iostream>

using namespace std;

class Test
{
public:
	Test() { Render();  };
	void Render(){ cout << "hi" << endl;a = 10; cout << a << endl;};
private:
	int a;
};


int main()
{
	Test* t = new Test;

	return 0;
}
