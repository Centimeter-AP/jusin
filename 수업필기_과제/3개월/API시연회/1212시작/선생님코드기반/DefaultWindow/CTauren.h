#pragma once
#include "CMonster.h"
class CTauren : public CMonster
{
public:
    CTauren()
    : m_eCurState(IDLE_ACT), m_bPlayerFound(false)
    , m_bBumped(false)
    {}
	virtual ~CTauren();

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
    bool        m_bBumped;
    int         m_iActMotionOffset;
    int         m_iBeforeAct;
    DIRECTION   m_ePrevDir;
};

