#include <iostream>

using namespace std;

int main()
{
	// 연산자 수업 함(자료 참고)


	// 보수..
	// 뺄셈
	// A + (~A) + 1 == 0 (컴퓨터 동작방식)
	// A - A == 0

	//시프트 연산(으!) >> <<
	// >>오른쪽은 2의 배수만큼 나누기
	// = 2로 나눌 땐 그냥 >> 1 해버리는 것이 성능적으로 좋다 !!!

	// ++은 전위로는 연속 되지만 후위로는 연속 안됨 .. 

	// += -=.. 그리고 쉬프트연산자도 가능하다  >>= <<= 가 잇 다 .
	// 그러면 a /= 2  보다 a >>= 1 이 낫다는 거겠지? 

	// if 조건문에 대입연산자 들어가도 된다 왜 잊엇을까요? 그럴 수 있어요....
	// 변수에 대입된 값이 있기 때문에 true로 판단한건지?
	// 0을 대입했을 때 거짓으로 생각할지도(사실이다)

	// int tmpA(10), tmpB(20);

	// if ((tmpA = 0))
	// 	cout << tmpA << endl;

	// if문 안에 의외로 'break;'키워드가 적용이 안된다;;;;;;;;
	// 몰랏당
	// break가 되었던 경우는 보통 while이라던지.. 반복문 안에 if가 있었던 경우 


	// switch문은 상수조건문이다
	// case 뒤에 오는 숫자는 무조건 상수여야한다 case 변수: 같은건 안된다는 소리
	// 근데 심볼릭 상수도 된다..? const 로 지정한 애들.....
	// switch문 중괄호 내 case 이전에 변수선언이 안된다..
	// case 내에서는 중괄호를 사용하면 (= 지역을 구분해주면) 변수 선언 후 사용이 가능
	// 당연하지만 그렇게 지역을 구분해주면 다른 case에서 사용할 수 없음 !! 다른 지역의 지역변수니까



	// 평균 값을 기준으로 성적 등급을 매기자
	// 90~100 A
	// 80~89 B
	// 70~79 C
	// 60~69 D
	// F
	// 빨리하고밥먹어야지~



	int iKor(0), iEng(0), iMat(0), iSum(0), iGrade(0);
	float fAvg(0.0);

	cout << "국어 점수를 입력해주세요: ";
	cin >> iKor;
	cout << "영어 점수를 입력해주세요: ";
	cin >> iEng;
	cout << "수학 점수를 입력해주세요: ";
	cin >> iMat;
	iSum = iKor+iEng+iMat;
	fAvg = (float)iSum / 3.f;
	cout << "국어\t영어\t수학\t총점\t평균" << endl;
	cout << iKor << '\t' << iEng << '\t' << iMat << '\t' << iSum << '\t' << fAvg << endl;
	cout << "당신의 등급은 ";
	
	if (90.f <= fAvg && fAvg <= 100.f)
	{
		iGrade = 1;
		// cout << "A 입니다." << endl;
	}
	else if (80.f <= fAvg && fAvg < 90.f)
	{
		iGrade = 2;
		// cout << "B 입니다." << endl;
	}
	else if (70.f <= fAvg && fAvg < 80.f)
	{
		iGrade = 3;
		// cout << "C 입니다." << endl;
	}
	else if (60.f <= fAvg && fAvg < 70.f)
	{
		iGrade = 4;
		// cout << "D 입니다." << endl;
	}
	else if (0.f <= fAvg && fAvg < 60.f)
	{
		iGrade = 5;
		// cout << "F 입니다." << endl;
	}
	else
	{
		// cout << "\n!!성적의 평균은 0 이상 100 이하여야 합니다!!" << endl;
	}

	switch (iGrade)
	{
	case 1:
		cout << "A 입니다." << endl;
		break;
	case 2:
		cout << "B 입니다." << endl;
		break;
	case 3:
		cout << "C 입니다." << endl;
		break;
	case 4:
		cout << "D 입니다." << endl;
		break;
	case 5:
		cout << "F 입니다." << endl;
		break;
	
	default:
		cout << "\n!!성적의 평균은 0 이상 100 이하여야 합니다!!" << endl;
		break;
	}

	return 0;
}
