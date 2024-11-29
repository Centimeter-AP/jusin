#pragma once
#include "Obj.h"
class CPlayer : public CObj
{
public:
    CPlayer() : m_pBullet(nullptr) {};
    virtual ~CPlayer() {};

public:
    void    Update() override;
    void    Render(HDC _hdc) override;
    void    Initialize() override;
    void    Release() override;

public:
    void    Get_KeyInput();
    CObj*   Make_Bullet();
    void    Set_Bullet(list<CObj*>* _Bullet) { m_pBullet = _Bullet; };

private:
    list<CObj*>* m_pBullet;

    // CObj을(를) 통해 상속됨
    void Late_Update() override;
};

