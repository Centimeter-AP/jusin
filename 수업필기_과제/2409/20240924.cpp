#include <iostream>

using namespace std;

int main()
{
#pragma region 생략
	// 단일주석
	/* 복수
		주석 */
//어쩌고저쩌고 생략해서 줄여놓는 방법이 또 있네요
#pragma endregion

#pragma region 수업내용
	// int iInput(0);

	// cout << "숫자를 입력하세요: ";
	// cin >> iInput;
	// cout << endl;

	// cout << "숫자" << iInput << endl;

	//숙제: 국어 영어 수학 점수를 입력받고 총점과 평균을 구해서 모두 출력하기
	//국어 영어 수학 총점 평균
	// ?  ?    ?  ?   ?
#pragma endregion 

	int iKor(0), iEng(0), iMat(0);
	// int iEng(0);
	// int iMat(0);

	cout << "국어 점수를 입력해주세요: ";
	cin >> iKor;
	cout << "영어 점수를 입력해주세요: ";
	cin >> iEng;
	cout << "수학 점수를 입력해주세요: ";
	cin >> iMat;
	cout << "국어\t영어\t수학\t총점\t평균" << endl;
	cout << iKor << '\t' << iEng << '\t' << iMat << '\t' << iKor+iEng+iMat << '\t' << (iKor+iEng+iMat)/3 << endl;

	//average = (float)total / 3.f(실수형으로 쓰자..?)

	//(float)total == float(total)이기는 하나 후자는 클래스 오버라이딩으로 동작한다는 것 같음(느리다.)(c는안됨?)

	//visual studio 소스파일에 파일 점점 .. 추가 되는데 
	//전부 다 빌드 시켜버릴 수 없으니까
	//우클 속성 빌드에서 제외 체크하게 된다
	//당연함..모든파일에 메인함수 있는데 전부 make해버리는꼴(충격!)

	return 0;
}