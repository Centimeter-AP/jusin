#pragma once
#include "Obj.h"
class CRotBullet : public CObj
{
public:
	CRotBullet() : m_fBulletAngle(0.f) { ZeroMemory(&m_MyRect, sizeof(RECT)); ZeroMemory(&m_MyPos, sizeof(POINT)); }
	virtual ~CRotBullet() {};
public:
	int	 Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Initialize() override;
	void Release() override;

private:
	POINT	m_MyPos;
	RECT	m_MyRect;
	float	m_fBulletAngle;
	void	Set_MyRect();
};

