#pragma once
#include "CObj.h"
class CMonster :   public CObj
{
public:
    CMonster();
    virtual ~CMonster();
    
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    void Find_Player();
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

    void        Jumping();
protected:
    enum MONSTATE { MON_IDLE, MON_AGGRO, MON_ATTACK, MON_END };

    vector<CObj*>* m_pvecTile;
    int         m_iCurTileIdx;
    int         m_iHeadTileIdx;
    float       m_fJumpPower;
    float       m_fTime;
    bool        m_bMove;
    float       m_fShadowY;
};

