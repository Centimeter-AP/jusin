#include "./Field.h"
#include "../precom.h"
#include "../Info.h"
#include "../System/System.h"

CField::CField() : iStep(0)
{
	cout << GREEN << "CField" << NOCOLOR << " 생성자 호출"  << endl;
}
CField::~CField()
{
	cout << RED << "CField" << NOCOLOR << " 소멸자 호출" << endl;
}

void	CField::Initialize()
{

}

void	CField::Update()
{
	int iInput(0);
	int iFlag(0);
	int iStep(0);
	while (1)
	{
		cout << Text(iFlag);
		cout << "1. 왼쪽  2. 직진  3. 오른쪽  4. 빠져나온다" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(4);
		switch (iInput)
		{
		case 1:
			
			break;
		
		default:
			break;
		}
		iStep++;

	}
}
void	CField::Release()
{}

const char*	CField::Text(int _iFlag)
{
	int iRand(0);
	iRand = rand() % 4;
	if (_iFlag)
	switch (iRand)
	{
	case RAND1:
		return "조용한 숲속에서 느닷없이 쥐어짜는 듯한 소리가 들린다. 발 밑에서 느껴지는 뭔가의 움직임에 고개를 돌리면, 바람에 흔들리는 나뭇가지가 마치 누군가의 손처럼 보인다.";
	
	case RAND2:
		return "숲 속의 길이 자꾸만 변하는 듯하다. 당신이 지나온 길이 사라지고, 익숙했던 나무들이 낯설게 느껴진다. 마치 이 숲이 당신을 가두려 하는 것 같은 두려움이 엄습한다.";
	
	case RAND3:
		return "짙은 그늘이 드리운 길은 마치 당신을 감싸는 듯한 압박감을 준다. 뒤를 돌아보면, 나무들 사이에 어떤 존재가 숨어 있을 것만 같은 불안한 기분이 스멀스멀 느껴진다.";
	
	case RAND4:
		return "머리 위의 나뭇가지들이 기괴하게 일렁이며, 마치 누군가의 속삭임이 들리는 듯한 착각을 일으킨다.";
	
	default:
		return "Did something went wrong?";
	}
}
