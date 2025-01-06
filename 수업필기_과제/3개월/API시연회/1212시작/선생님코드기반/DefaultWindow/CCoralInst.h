#pragma once
#include "CMonster.h"
class CCoralInst : public CMonster
{
public:
    CCoralInst() : m_iOrigTileIdx(0), m_eCurState(END_ACT)
                , m_iBeatPassed(0), m_iShakeAnimation(3), m_iMovingPos(0), m_bWaterIn(false)
    {}
    virtual ~CCoralInst() {  }

public:
    virtual void Initialize() PURE;
    virtual int Update() PURE;
    virtual void Late_Update() PURE;
    virtual void Render(HDC hDC) PURE;
    virtual void Release() PURE;

public:
    enum ACTSTATE { SHAKE_ACT, DIVEDOWN_ACT, DIVEUP_ACT, ATTACKREADY_ACT, IDLE_ACT, END_ACT };
    void        Goto_Player(int _Pos);
    void        Set_HeadPositionIdx();
    void        Set_ActState(ACTSTATE _state) { m_eCurState = _state; }
    void        Set_TilePos();

protected:
    ACTSTATE    m_eCurState;
    bool        m_bAttacked;
    int         m_iBeforeAct;
    int         m_iOrigTileIdx;
    bool        m_bMoveStart;
    int         m_iBeatPassed;
    int         m_iShakeAnimation;
    int         m_iMovingPos;
    bool        m_bWaterIn;
};

