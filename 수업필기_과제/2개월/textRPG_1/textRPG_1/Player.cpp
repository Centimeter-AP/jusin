#pragma once
#include "pch.h"
#include "Player.h"
#include "Info.h"
#include "System.h"
#include "Item.h"
#include "Armor.h"

CPlayer::CPlayer()
{
	cout << GREEN << "CPLAYER" << NOCOLOR << " 생성자 호출" << endl;
	mInfo.sName = "";
	mInfo.iMaxHP = 0;
	mInfo.iHP = 0;
	mInfo.iAtk = 0;
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100;
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
	vecArmorInv.reserve(ARMORINVMAX);
	vecItemInv.reserve(ITEMINVMAX);
	for (int i = 0; i < ARMOR_END; ++i)
		mArmorSlot[i] = nullptr;
}

CPlayer::CPlayer(string sName, int _iHP, int _iAtk)
{
	mInfo.sName = sName;
	mInfo.iMaxHP = _iHP;
	mInfo.iHP = mInfo.iMaxHP;
	mInfo.iAtk = _iAtk;
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100;
	mPInfo.iMaxExp = 100;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
	vecArmorInv.reserve(ARMORINVMAX);
	vecItemInv.reserve(ITEMINVMAX);
	for (int i = 0; i < ARMOR_END; ++i)
		mArmorSlot[i] = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
	cout << RED << "CPLAYER " << mInfo.sName << NOCOLOR << " 소멸자 호출" << endl;
}

void	CPlayer::Initialize()
{
	int iInput(0);
	while (1)
	{
		// system("pause"); system("cls");
		cout << "직업을 선택하세요" << endl;
		cout << "1. 전사  2. 마법사  3. 도적" << endl;
		cout << "입력 : ";
		cin >> iInput;
		CINEXCEPTION(3);
		switch (iInput)
		{
		case CLASS::WARRIOR:
			mInfo.sName = (string)"전사";
			mInfo.iMaxHP = 100;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 9;
			break;

		case CLASS::MAGE:
			mInfo.sName = (string)"마법사";
			mInfo.iMaxHP = 100;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 10;
			break;

		case CLASS::ROGUE:
			mInfo.sName = (string)"도적";
			mInfo.iMaxHP = 90;
			mInfo.iHP = mInfo.iMaxHP;
			mInfo.iAtk = 12;
			break;

		default:
			return;
		}
		break;
	}
	mInfo.iCritChance = 10;
	mInfo.iCritical = 1;
	mInfo.iGold = 100000;
	mPInfo.iMaxExp = 30;
	mPInfo.iLvl = 1;
	mPInfo.iExp = 0;
}

void	CPlayer::Release()
{
	for_each(vecArmorInv.begin(), vecArmorInv.end(), Safe_Delete<CItem*>);
	for (int i = 0; i < size(mArmorSlot); ++i)
	{
		if (mArmorSlot[i])
			delete mArmorSlot[i];
	}
	return;
}

void	CPlayer::Print_Info()
{
	cout << "======================================================" << endl;
	cout << "\t\t\t\t  소지 골드: " << mInfo.iGold << endl;
	cout << left << "직업 : " << mInfo.sName << "\t   레벨 : " << mPInfo.iLvl
		 <<  "\t    경험치 : " << mPInfo.iExp << " / " << mPInfo.iMaxExp << endl;
	cout << "체력 : " << mInfo.iHP << "\t 공격력 : " << mInfo.iAtk << endl;
	cout << "======================================================" << endl;
}

void CPlayer::Equip_Armor(CItem* pArmor)
{
	ARMORSLOT eType = dynamic_cast<CArmor*>(pArmor)->Get_Type();

	if (mArmorSlot[eType])
	{
		CItem* temp = mArmorSlot[eType];
		mInfo.iAtk -= dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_Atk();
		mInfo.iMaxHP -= dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		if (mInfo.iHP > mInfo.iMaxHP)
			mInfo.iHP = mInfo.iMaxHP;
		mArmorSlot[eType] = pArmor;
		mInfo.iAtk += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_Atk();
		mInfo.iMaxHP += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		mInfo.iHP += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		auto iter = find(vecArmorInv.begin(), vecArmorInv.end(), pArmor);
		*iter = temp;
		
	}
	else
	{
		mArmorSlot[eType] = pArmor;
		mInfo.iAtk += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_Atk();
		mInfo.iMaxHP += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		mInfo.iHP += dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		auto iter = find(vecArmorInv.begin(), vecArmorInv.end(), pArmor);
		iter = vecArmorInv.erase(iter);
	}
	cout << mArmorSlot[eType]->Get_Name() << " 장착 성공" << endl;
}

void CPlayer::Unequip_Armor(CItem* pArmor)
{
	ARMORSLOT eType = dynamic_cast<CArmor*>(pArmor)->Get_Type();

	if (vecArmorInv.size() < ARMORINVMAX)
	{
		vecArmorInv.push_back(pArmor);
		mInfo.iAtk -= dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_Atk();
		mInfo.iMaxHP -= dynamic_cast<CArmor*>(mArmorSlot[eType])->Get_HP();
		if (mInfo.iHP > mInfo.iMaxHP)
			mInfo.iHP = mInfo.iMaxHP;

		mArmorSlot[eType] = nullptr;
	}
	else
	{
		cout << "인벤토리가 부족합니다." << endl;
	}
}

void CPlayer::Buy_Armor(CItem* pArmor)
{
	if (mInfo.iGold >= pArmor->Get_Price())
	{
		if (vecArmorInv.size() < ARMORINVMAX)
		{
			mInfo.iGold -= pArmor->Get_Price();
			vecArmorInv.push_back(pArmor->Clone());
		}
		else
			cout << "인벤토리가 가득 찼습니다. " << endl;
	}
	else
		cout << "소지금이 부족합니다. " << endl;
}

void CPlayer::Sell_Armor(CItem* pArmor)
{

}

void CPlayer::Buy_Item(CItem* pItem)
{
	if (mInfo.iGold >= pItem->Get_Price())
	{
		auto iter = find_if(vecItemInv.begin(), vecItemInv.end(), [&pItem](CItem* p) { return p->Get_Name() == pItem->Get_Name(); });
		if (iter == vecItemInv.end())
		{
			if (vecItemInv.size() < ITEMINVMAX)
			{
				mInfo.iGold -= pItem->Get_Price();
				vecItemInv.push_back(pItem->Clone());
				cout << "구매했습니다." << endl;
			}
			else
				cout << "인벤토리가 가득 찼습니다. " << endl;
			system("pause");
		}
		else
		{
			mInfo.iGold -= pItem->Get_Price();
			cout << "구매했습니다." << endl;
			(*iter)->Set_Count(1);
			cout << (*iter)->Get_Count() << " 개 있습니다." << endl;
			system("pause");
		}
	}
	else
		cout << "소지금이 부족합니다. " << endl;
}

void CPlayer::Sell_Item(CItem* pItem)
{
}

void	CPlayer::Level_Up()
{
	mPInfo.iLvl++;
	mInfo.iAtk += 2;
	mInfo.iMaxHP += 10;
	mInfo.iHP = mInfo.iMaxHP;
	system("pause"); system("cls");
	Print_Info();
	cout << "플레이어 레벨 업!" << endl;
}

void	CPlayer::Player_Lose()
{
	mPInfo.iExp -= mPInfo.iMaxExp / 3;
	if (mPInfo.iExp < 0)
		mPInfo.iExp = 0;
	mInfo.iHP = mInfo.iMaxHP;
}

void	CPlayer::Player_Win()
{
	mPInfo.iExp += 15;
	if (mPInfo.iExp >= mPInfo.iMaxExp)
	{
		mPInfo.iExp = 0;
		mPInfo.iMaxExp += 10;
		Level_Up();
	}
}