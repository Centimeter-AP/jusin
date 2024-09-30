#include <iostream>

using namespace std;

int main()
{

#pragma region 변수 이름 규칙

	// 1. 변수 이름은 알파벳과 숫자로 구성 할 수 있다. 단, 숫자가 맨 앞에 위치할 수 없다.
	// 2. 변수 이름은 대, 소문자를 확실히 구분한다.
	// 3. 프로그래밍 언어에서 제공하는 기본 키워드로 이름을 지을 수 없다.
	// ex)	int	namespace = 100; (x)
	// 4. 변수 이름에 공백 또는 특수 문자가 존재 할 수 없다. 단, _는 허용
	// ex) int Player_Hp = 100; (o)
	// 5. 같은 이름의 변수로 재 선언 또는 재 정의(초기화) 할 수 없다.

#pragma endregion

#pragma region 표기법

	// 1. 헝가리안 표기법 : 변수 이름 앞에 자료형을 뜻하는 문자를 삽입
	// ex) int iHp; float fTime; char cName;

	// 2. 카멜 표기법 : 단어와 단어 사이를 대문자로 구분하는 방법
	// ex) int playerHp

	// 3. 파스칼 표기법 : 단어의 시작 글자를 무조건 대문자료 표기하는 방법
	// ex) int PlayerHp

	// 4. 언더바 표기법 : 단어와 단어 사이에 _를 사용
	// ex) void	Set_Damage();
	// ex) void	Render(int _iHp);

#pragma endregion

#pragma region 숙제풀이

	int		iKorean(0), iEnglish(0), iMath(0), iTotal(0);
	float	fAver(0.f);

	cout << "국어 점수를 입력하세요 : ";
	cin >> iKorean;

	cout << "영어 점수를 입력하세요 : ";
	cin >> iEnglish;

	cout << "수학 점수를 입력하세요 : ";
	cin >> iMath;

	iTotal = iKorean + iEnglish + iMath;
	
	// 묵시적 형 변환(casting)
	// fAver = iTotal / 3.f;

	// 명시적 형 변환(casting)
	fAver = (float)iTotal / 3.f;
	// fAver = float(iTotal) / 3.f;

	// '\t' : 탭키를 누른 것 만큼 옆으로 띄어쓰기
	cout << "국어" << '\t' << "영어\t수학\t총점\t평균" << endl;
	cout << iKorean << '\t' << iEnglish << '\t' << iMath << '\t' << iTotal << '\t' << fAver << endl;

#pragma endregion

	return 0;
}