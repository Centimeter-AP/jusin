#pragma once

#include "Item.h"

class CArmor : public CItem
{
	// CItem��(��) ���� ��ӵ�
	void Use(CCharacter* obj) override;
	CItem* Clone() override;
	void Explain() override;
};

