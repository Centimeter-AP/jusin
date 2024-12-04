#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
public:
	CPlayer() : m_iFireRate(0), m_iDelay(0), m_RotBullet(nullptr), m_Bullet(nullptr), m_SubPlayer(nullptr) { ZeroMemory(&m_Posin, sizeof(POINT)); ZeroMemory(&m_Mouse, sizeof(POINT)); };
	virtual ~CPlayer() {};

public:
	int	 Update() override;
	void Late_Update() override;
	void Render(HDC _hdc) override;
	void Initialize() override;
	void Release() override;

public:
	void	Set_Bullet(list<CObj*>* _Bullet) { m_Bullet = _Bullet; }
	void	Set_SubPlayer(list<CObj*>* _SP)  { m_SubPlayer = _SP; }
	void	Set_RotBullet(list<CObj*>* _Rot) { m_RotBullet = _Rot; }
	void    Get_KeyInput();
	void	Set_Posin();
	int		Get_FireRate() { return m_iFireRate; }

private:
	list<CObj*>*	m_SubPlayer;
	list<CObj*>*	m_Bullet;
	list<CObj*>*	m_RotBullet;
	POINT			m_Posin;
	POINT			m_Mouse;
	int				m_iDelay;
	int				m_iFireRate;
};

