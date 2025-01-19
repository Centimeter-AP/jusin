#pragma once
#include "CObj.h"
class CTail :
    public CObj
{
public:
    CTail() {}
    virtual ~CTail() {}

public:
    void Initialize() override;
    void Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

    void Set_Target(CObj*_Target);
private:
    CObj* m_pTarget;
};

