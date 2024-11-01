#include "../precom.h"
#include "Character.h"

CCharacter::CCharacter()
{
	cout << "CCHARACTER 생성자 호출" << endl;
}
CCharacter::~CCharacter()
{
	cout << "CCHARACTER 소멸자 호출" << endl;
}

void	CCharacter::Initialize()
{}
void	CCharacter::Release()
{}

int	CCharacter::Get_CritDamage()
{
	rand() % 100 >= mInfo.iCritical ? mInfo.iCritical = 1 : mInfo.iCritical = 2;

	return(mInfo.iAtk * mInfo.iCritical);
}