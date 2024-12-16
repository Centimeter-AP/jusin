#pragma once
#include "CObj.h"
class CWall : public CObj
{
public:
	CWall();
	~CWall();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	enum WALLTYPE { WALL_ONE, WALL_TWO, WALL_THREE_FIRE, WALL_FOUR_ICE, WALL_FOUR, WALL_FIVE, WALL_MISC, WALL_END};
	enum WALLMISCNUMBER {SHOP_WALL = 0, SHOP_WALLX, BEDROCK = 4, DOOR_DOWN = 12, DOOR_LEFT, WALL_ONE_ROCK = 29, WALL_ONE_ROCKX = 30, MISC_END };
	int		m_iHP;				// ������ (HP)
	int		m_iPowerNeeded;		// �μ��� ���� �ʿ��� �� (�� ���� �ּ���)
	
	int		m_iWallNumber[WALL_END][MISC_END];
};

