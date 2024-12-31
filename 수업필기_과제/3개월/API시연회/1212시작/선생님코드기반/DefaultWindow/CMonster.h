#pragma once
#include "CObj.h"
#include "CMonsterHP.h"
class CMonster :   public CObj
{
public:
    CMonster();
    virtual ~CMonster();
public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;
    void Find_Player();

    void        Jumping();
    bool        Can_Move();

protected:
    enum MONSTATE { MON_IDLE, MON_AGGRO, MON_ATTACK, MON_END };

    CMonsterHP  m_HP_UI;

    vector<CObj*>* m_pvecTile;
    int         m_iCurTileIdx;
    int         m_iHeadTileIdx;
    float       m_fJumpPower;
    float       m_fTime;
    bool        m_bMove;
    float       m_fShadowY;
    bool        m_bCanChangeDir;
};
