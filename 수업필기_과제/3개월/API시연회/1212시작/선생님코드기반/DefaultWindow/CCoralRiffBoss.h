#pragma once
#include "CMonster.h"
class CCoralRiffBoss : public CMonster
{
public:
    CCoralRiffBoss() {}
    virtual ~CCoralRiffBoss() { Release(); }
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

public:
    void        Set_Inst(CObj* _pInst) { m_vecInstrument.push_back(_pInst); }

private:
    enum ACTSTATE { BEFORE_ACT, AFTER_ACT, END_ACT };
    ACTSTATE    m_eCurState;
    bool        m_bAttacked;
    int         m_iBeforeAct;
    vector<CObj*>      m_vecInstrument;
};

