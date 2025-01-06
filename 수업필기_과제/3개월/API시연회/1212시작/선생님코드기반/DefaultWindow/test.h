#pragma once
#include "CMonster.h"
class test : public CMonster
{
public:
    test()
        : m_eCurState(IDLE_ACT), m_bPlayerFound(false)
        , m_iBumped(0)
    {}
    virtual ~test() { Release(); }

public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    enum ACTSTATE { IDLE_ACT, DASH_ACT, FAINT_ACT, END_ACT };
    ACTSTATE    m_eCurState;
    bool        m_bPlayerFound;
    int         m_iBumped;
    int         m_iActMotionOffset;
    int         m_iBeforeAct;
    DIRECTION   m_ePrevDir;
};

