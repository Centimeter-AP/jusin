#pragma once
#include "CObj.h"
class CLetterbox : public CObj
{
public:
	CLetterbox() {}
	virtual ~CLetterbox() {}

	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

