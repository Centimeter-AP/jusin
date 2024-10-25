// 241024성적표.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"


void	InputStudent(Manager* Report)
{
	int iAddInput(0), iKorInput(0), iEngInput(0), iMathInput(0);
	char szNameInput[32];

	cout << "몇 명을 입력하시겠습니까? : ";
	cin >> iAddInput; // 0이하예외처리

	Report->Set_iAddNum(iAddInput);
	Report->Init_StudentList();

	for (int i = Report->Get_iIndex(); i < Report->Get_iMax(); ++i)
	{
		cout << "이름을 입력해주세요 : ";
		cin >> szNameInput;
		Report->Get_Student(i)->Set_szName(szNameInput);
		cout << "국어 점수 : ";
		cin >> iKorInput;
		Report->Get_Student(i)->Set_iKor(iKorInput);
		cout << "영어 점수 : ";
		cin >> iEngInput;
		Report->Get_Student(i)->Set_iEng(iEngInput);
		cout << "수학 점수 : ";
		cin >> iMathInput;
		Report->Get_Student(i)->Set_iMath(iMathInput);
	}
}

void	PrintStudent(Student* _Student)
{
	cout << "\n====================================" << endl;
	cout << _Student->Get_szName() << "의 성적" << endl;
	cout << "국어 : " << _Student->Get_iKor()\
		<< "\t영어 : " << _Student->Get_iEng()\
		<< "\t수학 : " << _Student->Get_iMath() << endl;
	cout << "총점 : " << _Student->Get_iTotal()\
		<< "\t평균 : " << _Student->Get_fAvg() << endl;
}

void	PrintAll(Manager* Report)
{
	for (int i = 0; i < Report->Get_iMax(); ++i)
	{
		PrintStudent(Report->Get_Student(i));
	}
}

void	SearchStudent(Manager* Report)
{

}




int main()
{
	Manager* Report = new Manager;
	int iInput(0), iFlag(1);

	while (iFlag)
	{
		cout << "\n================================" << endl;
		cout << "iIndex : " << Report->Get_iIndex() << "  iMax : " << Report->Get_iMax() << endl;
		cout << "================================\n" << endl;



		cout << "1. 입력 2. 모두 출력 3. 검색 4. 종료" << endl;
		cout << "선택 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			InputStudent(Report);
			break;
		case 2:
			PrintAll(Report);
			break;
		case 3:
			break;
		case 4:
			iFlag = 0;
			break;

		default:
			iFlag = 0;
			break;
		}
	}


	Report->Delete_StudentList();
	delete Report;
	Report = nullptr;
	return 0;
}

// 성적표_최종_진짜_마지막_final 만들기
// 1. 입력 2. 모두 출력 3. 검색 4. 종료
// - 성적표 프로그램을 클래스로 만들고 동적 배열을 구현?하자
//   어라 동적배열... 분명 어제 얘기 하지 않았나요??..
// - 입력을 누르면 몇 명을 입력 받을지 묻고 그 숫자만큼 학생들의 성적 정보를 입력 으윽 뭐지 뭔가 수상할 정도로 익숙한 Phonebook의 기억이
// - 모두 출력을 하면 입력된 데이터 모두를 출력한다
// - 만약 기존의 데이터가 있는 상태에서 또 다시 입력을 선택하면 몇 명을 추가할 지 묻고 새로 입력받은 추가 데이터를 기존의 데이터와 합친다
