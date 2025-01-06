#pragma once
#include "CObj.h"
class CBossCutscene : public CObj
{
public:
	CBossCutscene() {}
	virtual ~CBossCutscene() {}
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

