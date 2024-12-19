#pragma once
#include "CMonster.h"
class CSkeleton :
    public CMonster
{
public:
    CSkeleton(): m_eCurState(BEFORE_JUMP) {}
    virtual ~CSkeleton() { Release(); }
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    enum ACTSTATE{BEFORE_JUMP, AFTER_JUMP, END_ACT};
    ACTSTATE    m_eCurState;
};

