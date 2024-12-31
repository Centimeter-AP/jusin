#pragma once
#include "CMonster.h"
class CBlueSlime : public CMonster
{
public:
    CBlueSlime()
    : m_iSelectedIndex{0,0}
    {}
    virtual ~CBlueSlime() { Release(); }
public:
    virtual void Initialize() override;
    virtual int  Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    enum ACTSTATE { BEFORE_ACT, AFTER_ACT, END_ACT };
    ACTSTATE    m_eCurState;
    int         m_iSelectedIndex[2];
};

