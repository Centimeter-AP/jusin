#include <iostream>

// 숙제
// 1. 성적표 만들기 구조체써서
// 3명의 학생의 성적 입출력 프로그램 만들기
// 이름, 국어, 영어, 수학 입력받기
// 총점 평균 구해서 출력하기

// 이름 검색해서 원하는 학생 찾는 기능 함수
// 입력받기 출력하기 함수는 당연

using namespace std;

typedef struct tagReport{
	char	sName[10];
	int		iKor;
	int		iEng;
	int		iMat;
	float	fAvg;
}REPORT;

// 오늘 숙제부터 예외처리로 코드를 너무 더럽히지 않기 위해 입력 값이 고정적인 것을 가정하고 작성함...

void	PrintStudentGrade(REPORT pRep);
void	GetStudentGrade(REPORT *pArr);
void	SearchStudentGrade(REPORT *pArr);

int main()
{
	REPORT	tStudent[3] = {};
	int		iInput(0);

	system("clear");
	while (1)
	{	
		cout << "\n1. 성적표 입력하기\n2. 성적표 검색하기\n3. 종료\n입력: ";
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			system("clear");
			GetStudentGrade(tStudent);
			break;

		case 2:
			system("clear");
			SearchStudentGrade(tStudent);
			break;
		
		case 3:
			return 0;

		default:
			system("clear");
			cout << "1 ~ 3 사이의 정수만 입력해주세요." << endl;
			if (cin.fail()){	
				cin.clear();
				while (cin.get() == '\n') continue;}
			break;
		}
	}

	return 0;
}

void	PrintStudentGrade(REPORT pRep)
{
	cout << "학생 이름: " << pRep.sName << "\n국어 점수: " << pRep.iKor <<
			"\n영어 점수: " << pRep.iEng << "\n수학 점수: " << pRep.iMat <<
			"\n  총 점  : " << (pRep.iKor + pRep.iEng + pRep.iMat) << "\n평균 점수: " << pRep.fAvg << endl;
}

void	GetStudentGrade(REPORT *pArr)
{	
	for (int i = 0; i < 3; ++i)
	{
		if (!(strcmp(pArr[i].sName,"")))
		{
			cout << "이름 입력: ";
			cin >> pArr[i].sName;
			cout << "국어 성적 입력: ";
			cin >> pArr[i].iKor;
			cout << "영어 성적 입력: ";
			cin >> pArr[i].iEng;
			cout << "수학 성적 입력: ";
			cin >> pArr[i].iMat;
			pArr[i].fAvg = (pArr[i].iKor + pArr[i].iEng + pArr[i].iMat) / 3.f;
			system("clear");
			return ;
		}
	}
	cout << "성적표는 총 3개만 저장할 수 있습니다." << endl;
}

void	SearchStudentGrade(REPORT *pArr)
{
	char sInput[10];
	cout << "찾으려는 학생 이름을 입력해주세요 : ";
	cin >> sInput;
	system("clear");
	for (int i = 0; i < 3; ++i)
	{
		if (!(strcmp(pArr[i].sName, sInput)))
		{
			PrintStudentGrade(pArr[i]);
			return ;
		}
	}
	cout << "입력되지 않은 학생입니다." << endl;
}
