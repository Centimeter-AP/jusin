// #include <iostream>

// using namespace std;

// class CBase
// {
// public:
// 	CBase(){};
// 	~CBase(){};
// public:
// 	void	Attack(const char *name)
// 	{
// 		cout << "CBASE가 " << name << "을 공격" << endl;
// 	}
// };

// class CDerived : public CBase
// {
// public:
// 	CDerived(){};
// 	~CDerived(){};
// public:
// 	void	Attack(const char *name)
// 	{
// 		cout << "CDERIVED가 " << name << "을 공격" << endl;
// 	}
// };

// int main()
// {
// 	CBase *Base = new CBase;
// 	Base->Attack("쥬신");

// 	CBase *Derived = new CDerived;
// 	Derived->Attack("선생님");
// 	return 0;
// }


#include <iostream>
#include <string>
using namespace std;

class Friend1 
{
private :
	string name;

	friend class Friend2;
};

class Friend2
{
public :
	void set_name(Friend1& f, string s) 
	{
		f.name = s;
	}
	void show_name(Friend1& f)
	{
		cout << f.name << "\n";
	}
};

int main(void)
{
	Friend1 f1;
	Friend2 f2;
	f2.set_name(f1, "열코");
	f2.show_name(f1);
	return 0;
}