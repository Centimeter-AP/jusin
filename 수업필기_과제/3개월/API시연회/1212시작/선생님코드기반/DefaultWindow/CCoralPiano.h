#pragma once
#include "CMonster.h"
class CCoralPiano :
    public CMonster
{
public:
    CCoralPiano() {}
    virtual ~CCoralPiano() { Release(); }
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    enum ACTSTATE { BEFORE_ACT, AFTER_ACT, END_ACT };
    ACTSTATE    m_eCurState;
    bool        m_bAttacked;
    int         m_iBeforeAct;
};

