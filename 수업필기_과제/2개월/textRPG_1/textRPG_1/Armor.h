#pragma once

#include "Item.h"

class CArmor : public CItem
{
	// CItem을(를) 통해 상속됨
	void Use(CCharacter* obj) override;
	CItem* Clone() override;
	void Explain() override;
};

