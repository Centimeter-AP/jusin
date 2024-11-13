// 241106숙제-string.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
using namespace std;
namespace MyStd
{
	class MyString
	{
	public:
		MyString() { str = nullptr; };
		MyString(const char* _str)
		{
			Render();
			if (str)
				delete[] str;
			str = new char[strlen(_str) + 1];
			strcpy_s(str, strlen(_str) + 1, _str);

		}
		MyString(const MyString& rhs)
		{
			//this->str = new char[strlen(rhs.str) + 1];
			//strcpy_s(this->str, strlen(rhs.str) + 1, rhs.str);
			*this = rhs;
		}
		~MyString() { if (str) delete[] str; };

		MyString& operator =(const MyString& rhs)
		{
			if (this->str)
				delete[] this->str;
			this->str = new char[strlen(rhs.str) + 1];
			strcpy_s(this->str, strlen(rhs.str) + 1, rhs.str);
			return *this;
		}

		MyString& operator =(const char* src)
		{
			if (str)
				delete[] str;
			str = new char[strlen(src) + 1];
			strcpy_s(str, strlen(src) + 1, src);
			return *this;
		}

		MyString operator +(MyString& rhs)
		{
			MyString result;
			result.str = new char[strlen(str) + strlen(rhs.str) + 1];
			strcpy_s(result.str, strlen(str) + 1, str);
			strcat_s(result.str, strlen(str) + strlen(rhs.str) + 1, rhs.str);
			return result;
		}

		bool	operator ==(MyString& rhs)
		{
			if (!strcmp(str, rhs.str))
				return true;
			else
				return false;
		}
		void	Render()
		{
			cout << "왜 되냐?" << endl;
		}

	public:
		const char* Get_Str() { return str; }

	private:
		char* str;
	};
	
}

using namespace MyStd;


static std::ostream& operator<<(std::ostream& lhs, MyString& STRING)
{
	lhs << STRING.Get_Str();
	return (lhs);
};


int main()
{
	MyString STRING = "hello";
	MyString STRING2 = " world";
	cout << STRING << endl;
	cout << STRING2 << endl;
	cout << endl;
	STRING = STRING + STRING2;
	cout << STRING << endl;
	cout << endl;

	MyString STRINGCPY = STRING;  // 선언과 동시에 초기화는 매개변수로 받는걸로 취급함 !! = 같은 타입 객체라면 복사생성자가 됨
	MyString DOES;
	DOES = STRING;  // 이쪽이 진짜 대입연산자
	cout << STRINGCPY << endl;
	cout << ((STRING == STRING2) ? "true" : "false") << endl;
	cout << ((STRING == STRINGCPY) ? "true" : "false") << endl;
	cout << endl;

	//MyString CONCATENATE = STRING + STRING2;
	//cout << CONCATENATE << endl;

}