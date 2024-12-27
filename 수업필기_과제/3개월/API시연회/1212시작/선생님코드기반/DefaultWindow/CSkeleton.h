#pragma once
#include "CMonster.h"
class CSkeleton : public CMonster
{
public:
    CSkeleton(): m_eCurState(BEFORE_ACT), m_bAttacked(true) {}
    virtual ~CSkeleton() { Release(); }
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    enum ACTSTATE{BEFORE_ACT, AFTER_ACT, END_ACT};
    ACTSTATE    m_eCurState;
    bool        m_bAttacked;
};

