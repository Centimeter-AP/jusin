#pragma once
#include "CStage.h"
class CBossStage : public CStage
{
public:
	CBossStage();
	virtual ~CBossStage();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};