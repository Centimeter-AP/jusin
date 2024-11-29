#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
    CBullet() : m_ldX(0), m_ldY(0) {};
    virtual ~CBullet() {};
public:
    void Update() override;
    void Render(HDC _hdc) override;
    void Initialize() override;
    void Release() override;

public:
    
private:
    LONG    m_ldX, m_ldY;



    // CObj을(를) 통해 상속됨
    void Late_Update() override;

};

