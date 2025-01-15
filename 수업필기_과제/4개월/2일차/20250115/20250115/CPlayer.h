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
    D3DXVECTOR3 LT;
    D3DXVECTOR3 RT;
    D3DXVECTOR3 LD;
    D3DXVECTOR3 RD;
    D3DXVECTOR3 Posin;
    D3DXMATRIX	matScale;
    D3DXMATRIX	matRotZ;
    D3DXMATRIX	matTrans;
    float       m_fAngle;
    float       m_fPosinAngle;
};

