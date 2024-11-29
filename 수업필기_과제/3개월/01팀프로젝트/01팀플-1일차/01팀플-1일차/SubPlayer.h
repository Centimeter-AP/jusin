#pragma once
#include "Obj.h"
class CSubPlayer : public CObj
{
public:
	CSubPlayer() { ZeroMemory(&m_MyRect, sizeof(RECT)); ZeroMemory(&m_MyPos, sizeof(POINT)); };
	~CSubPlayer() {};

public:
	int		Update() override;
	void	Late_Update() override;
	void	Render(HDC _hdc) override;
	void	Initialize() override;
	void	Release() override;

private:
	void    Get_KeyInput();
	RECT	m_MyRect;
	POINT	m_MyPos;
	void	Set_MyRect();
};

