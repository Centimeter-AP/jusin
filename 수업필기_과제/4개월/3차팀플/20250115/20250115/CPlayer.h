#pragma once
#include "CObj.h"

class CPlayer : public CObj
{
public:
    CPlayer();
    virtual ~CPlayer();

public:
    void Initialize() override;
    void Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    void        Key_Input();

private:
    D3DXMATRIX	matScale;
    D3DXMATRIX	matRotZ;
    D3DXMATRIX	matTrans;
    float       m_fAngle;
    float       m_fPosinAngle;
    vector<CObj*> m_pTailvec;
};

