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
		cout << "1. �߰� 2. ��� 3. �˻� 4. ���� 5. ����" << endl;
		cout << "�Է� : ";
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

void CMain::Release()
{
	
}

void CMain::AddStudent()
{
	int iInput(0);

	cout << "==============================================" << endl;
	cout << "�Է� �� �л� ���� �Է� �� �ּ��� : ";
	cin >> iInput;

	string sName;
	int iKor(0), iEng(0), iMat(0);
	for (int i = 0; i < iInput; ++i)
	{
		cout << "�̸� �Է� : ";
		cin >> sName;
		cout << "���� : ";
		cin >> iKor;
		cout << "���� : ";
		cin >> iEng;
		cout << "���� : ";
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
	cout << "�˻� �� �л��� �̸��� �Է� ���ּ���.\n�Է�:";
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
		cout << "ã�� �л��� �����ϴ�." << endl;
	system("pause");
}

void CMain::DeleteStudent()
{
	//vector<vector<CReport>::iterator> res;
	vector<int> res;
	string		sInput;
	int			iFound(0);

	system("cls");
	cout << "==============================================" << endl;
	cout << "���� �� �л��� �̸��� �Է� ���ּ���.\n�Է�:";
	cin >> sInput;
	int i(0);
	system("cls");
	for (iter = vecStudent.begin(); iter != vecStudent.end(); ++iter)
	{
		if (iter->Get_Name() == sInput)
		{
			//res.push_back(iter);
			cout << "==============================================" << endl;
			res.push_back(i);
			iter->Render();
			iFound++;
		}
		i++;
	}
	if (!iFound)
	{
		cout << "==============================================" << endl;
		cout << "ã�� �л��� �����ϴ�." << endl;
		system("pause");
		return;
	}
	else if (iFound == 1)
	{
		cout << "==============================================" << endl;
		cout << sInput << " �л��� ������ �����մϴ�." << endl;
		iter = vecStudent.begin() + *(res.begin());
		iter = vecStudent.erase(iter);
		system("pause");
	}
	else
	{
		while (1)
		{
			int iInput(0);
			cout << "==============================================" << endl;
			cout << "�ߺ��Ǵ� �л��� �ֽ��ϴ�. � �л��� ������ �����ұ��?" << endl;
			cout << "��ȣ �Է� : ";
			cin >> iInput;
			CINEXCEPTION(iFound);
			//vector<vector<CReport>::iterator>::iterator resIter = res.begin() + iInput - 1;
			//vecStudent.erase(*resIter);
			iter = vecStudent.begin() + *(res.begin() + iInput - 1);
			iter = vecStudent.erase(iter);
			cout << iInput << "��° �л��� ������ �����մϴ�." << endl;
			system("pause");
			break;
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
