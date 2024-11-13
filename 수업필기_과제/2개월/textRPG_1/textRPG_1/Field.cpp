#include "pch.h"
#include "Field.h"
#include "Info.h"
#include "System.h"
#include "Player.h"
#include "Monster.h"

CField::CField() : iStep(0), iMaxStep(0), iEncounterFlag(0)
{
	Player = nullptr;
	Monster = nullptr;
	cout << GREEN << "CField" << NOCOLOR << " 생성자 호출" << endl;
}
CField::~CField()
{
	Release();
	cout << RED << "CField" << NOCOLOR << " 소멸자 호출" << endl;
}

void	CField::Initialize()
{
	iMaxStep = 30;
}

void	CField::Release()
{
	delete Monster;
}

void	CField::Update()
{
	int iInput(0);
	int iFlag(0);
	int iCount(0);

	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		if (iMaxStep - iStep > 0)
		{
			cout << Text(iFlag) << endl;
			cout << "======================================================" << endl;
			cout << "필드 보스까지 남은 걸음 수 : " << iMaxStep - iStep << endl;
			cout << "======================================================" << endl;
		}
		else
		{
			// if (Boss_Encounter())
			// {

			// }
			void;
		}

		cout << "1. 왼쪽으로  2. 직진한다  3. 레벨업  4. 돌아나온다" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case 1:
			cout << "왼쪽으로 가봅니다." << endl;
			 
			break;

		case 2:
			cout << "앞으로 나아갑니다." << endl;
			
			break;

		case 3:
			cout << "플레이어 레벨 업" << endl;
			dynamic_cast<CPlayer*>(Player)->Level_Up();
			
			break;

		case 4:
			while (1)
			{
				system("pause"); system("cls");
				Player->Print_Info();
				cout << "돌아나가게 되면 이번 진행에서의 절반의 걸음 수를 잃습니다. 돌아가시겠습니까?" << endl;
				cout << "1. 돌아나간다  2. 취소한다" << endl;
				cout << "입력 : ";
				cin >> iInput;
				CINEXCEPTION(2);
				break;
			}
			if (iInput == 1)
			{
				iStep -= iCount / 2;
				if (iStep < 0)
					iStep = 0;
				return;
			}

			else
				continue;

		default:
			break;
		}
		Random_Encounter();
		iStep++;
		iCount++;
	}
}


void	CField::Random_Encounter()
{
	int iInput(0);
	if (!Monster)
		Monster = new CMonster("몬스터", dynamic_cast<CPlayer*>(Player)->Get_PInfo()->iLvl + rand() % 3);
	// 으악 끔찍해
	while (1)
	{
		system("pause"); system("cls");
		Player->Print_Info();
		Monster->Print_Info();
		cout << "1. 공격  2. 도망" << endl;
		cin >> iInput;
		if (iInput == 2)
			break;
		else if (iInput == 1)
		{
			if (Battle())
				break;
		}

	}
	delete Monster;
	Monster = nullptr;
}

const char* CField::Text(int _iFlag)
{
	int iRand(0);
	iRand = rand() % 4;
	(void)_iFlag;
	// if (_iFlag)
	switch (iRand)
	{
	case RAND1:
		return "조용한 숲속에서 느닷없이 쥐어짜는 듯한 소리가 들린다. \n발 밑에서 느껴지는 뭔가의 움직임에 고개를 돌리면, 바람에 흔들리는 나뭇가지가 마치 누군가의 손처럼 보인다.";

	case RAND2:
		return "숲 속의 길이 자꾸만 변하는 듯하다. \n당신이 지나온 길이 사라지고, 익숙했던 나무들이 낯설게 느껴진다. \n마치 이 숲이 당신을 가두려 하는 것 같은 두려움이 엄습한다.";

	case RAND3:
		return "짙은 그늘이 드리운 길은 마치 당신을 감싸는 듯한 압박감을 준다. \n뒤를 돌아보면, 나무들 사이에 어떤 존재가 숨어 있을 것만 같은 불안한 기분이 스멀스멀 느껴진다.";

	case RAND4:
		return "머리 위의 나뭇가지들이 기괴하게 일렁이며, 마치 누군가의 \n속삭임이 들리는 듯한 착각을 일으킨다.";

	default:
		return "Did something went wrong?";
	}
	return "switch is not working";
}

int		CField::Battle()
{
	Player->Attack(Monster);
	if (Monster->Get_Info()->iHP < 1)
	{
		cout << "플레이어 승리!" << endl;
		
		dynamic_cast<CPlayer*>(Player)->Player_Win();
		return 1;
	}
	Monster->Attack(Player);
	if (Player->Get_Info()->iHP < 1)
	{
		cout << "플레이어 패배..." << endl;
		
		dynamic_cast<CPlayer*>(Player)->Player_Lose();
		return 1;
	}
	return 0;
}