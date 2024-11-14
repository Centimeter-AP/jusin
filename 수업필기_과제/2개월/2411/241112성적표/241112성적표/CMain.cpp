#include "pch.h"
#include "CMain.h"
#include "Info.h"

void CMain::Initialize()
{
	iter = vecStudent.begin();
	AddStudent();
}

void CMain::Update()
{
	int iInput(0);

	while (1)
	{
		system("cls");
		cout << "==============================================" << endl;
		cout << "1. 추가 2. 출력 3. 검색 4. 삭제 5. 종료" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(5);

		switch (iInput)
		{
		case ADD:
			AddStudent();
			break;

		case PRINT:
			PrintStudent();
			break;

		case SEARCH:
			SearchStudent();
			break;

		case DELETE:
			DeleteStudent();
			break;

		case END:
			return ;

		default:
			cout << "is something wrong?";
			break;
		}
	}
}

void CMain::AddStudent()
{
	int iInput(0);

	cout << "==============================================" << endl;
	cout << "입력 할 학생 수를 입력 해 주세요 : ";
	cin >> iInput;

	string sName;
	int iKor(0), iEng(0), iMat(0);
	for (int i = 0; i < iInput; ++i)
	{
		cout << "이름 입력 : ";
		cin >> sName;
		cout << "국어 : ";
		cin >> iKor;
		cout << "영어 : ";
		cin >> iEng;
		cout << "수학 : ";
		cin >> iMat;
		vecStudent.push_back(CReport(sName, iKor, iEng, iMat));
	}
}

void CMain::SearchStudent()
{
	string		sInput;
	int			iFound(0);


	system("cls");
	cout << "==============================================" << endl;
	cout << "검색 할 학생의 이름을 입력 해주세요.\n입력:";
	cin >> sInput;
	system("cls");
	cout << "==============================================" << endl;
	for (iter = vecStudent.begin(); iter != vecStudent.end(); ++iter)
	{
		if (iter->Get_Name() == sInput)
		{
			iter->Render();
			cout << "==============================================" << endl;
			iFound++;
		}
	}
	if (!iFound)
		cout << "찾는 학생이 없습니다." << endl;
	system("pause");
}

void CMain::DeleteStudent()
{
	vector<vector<CReport>::iterator> res;
	string		sInput;
	int			iFound(0);

	system("cls");
	cout << "==============================================" << endl;
	cout << "삭제 할 학생의 이름을 입력 해주세요.\n입력:";
	cin >> sInput;
	system("cls");
	for (iter = vecStudent.begin(); iter != vecStudent.end(); ++iter)
	{
		if (iter->Get_Name() == sInput)
		{
			res.push_back(iter);
			cout << "==============================================" << endl;
			iter->Render();
			iFound++;
		}
	}
	if (!iFound)
	{
		cout << "==============================================" << endl;
		cout << "찾는 학생이 없습니다." << endl;
		system("pause");
		return;
	}
	else if (iFound == 1)
	{
		cout << "==============================================" << endl;
		cout << sInput << " 학생의 정보를 삭제합니다." << endl;
		iter = *(res.begin());
		iter = vecStudent.erase(iter);
		system("pause");
	}
	else
	{
		while (1)
		{
			int iInput(0);
			cout << "==============================================" << endl;
			cout << "중복되는 학생이 있습니다. 어떤 학생의 정보를 삭제할까요?" << endl;
			cout << "전부 삭제하려면 0을 입력하세요." << endl;
			cout << "번호 입력 : ";
			cin >> iInput;
			if (cin.fail() || iInput > iFound || iInput < 0) { CinFailException(cin.fail()); continue; }


			if (iInput == 0)
			{
				vector<vector<CReport>::iterator>::iterator resIter = res.begin();
				for (vector<vector<CReport>::iterator>::iterator resIter = res.begin();
					resIter != res.end(); ++resIter)
				{
					(**(resIter)).Render();
					iter = vecStudent.erase(*resIter);  /******************************************************/
				}
				cout << "전부 삭제합니다." << endl;
				system("pause");
				break;
			}
			else
			{
				vector<vector<CReport>::iterator>::iterator resIter = res.begin() + iInput - 1;
				iter = vecStudent.erase(*resIter);
				cout << iInput << "번째 학생의 정보를 삭제합니다." << endl;
				system("pause");
				break;
			}
		}
	}
}

void CMain::PrintStudent()
{
	system("cls");
	cout << "==============================================" << endl;
	for (iter = vecStudent.begin(); iter != vecStudent.end(); ++iter)
	{
		iter->Render();
		cout << "==============================================" << endl;
	}
	system("pause");
}
