#pragma once
#include "Bullet.h"
class BulletCY : public Bullet
{
public:
	BulletCY(): m_enType(PATEND), m_bStart(false), m_fRotAngle(0), m_fRotSpeed(0), m_tCenter({}) {}
	BulletCY(int _Type):m_bStart(false), m_fRotAngle(0), m_fRotSpeed(0), m_tCenter({}) { m_enType = (PATTYPE)_Type; }
	virtual ~BulletCY() {}
public:
	void Initialize() override;
	int  Update() override;

public:
	void	Set_Type(int _Type) { m_enType = (PATTYPE)_Type; }

private:
	enum PATTYPE {PATCIRCLE, PATSIDE, PATROTATE, PATSCREW, PATEND};
	PATTYPE			m_enType;
	POINT			m_tCenter;

	float			m_fRotAngle;
	float			m_fRotSpeed;

	bool			m_bStart;

private:
	void	CirclePattern();
	void	SidePattern();
	void	RotatePattern();
	void	ScrewPattern();
};

