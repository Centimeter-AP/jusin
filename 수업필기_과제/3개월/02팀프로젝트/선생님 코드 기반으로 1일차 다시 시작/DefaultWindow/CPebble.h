#pragma once
#include "CObstacle.h"
class CPebble : public CObstacle
{
public:
	CPebble();
	~CPebble();
public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	bool	Is_Hold();
	void	Throw();

private:
	bool	m_bGround;
};

