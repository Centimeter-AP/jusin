#pragma once
#include "CObj.h"
class CBoss_GutsMan : public CObj
{
public:
	CBoss_GutsMan();
	~CBoss_GutsMan() { Release(); }

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;


    void     Key_Input();

    float Get_Hp() { return MAX_Hp - Hp_Count; }
    void Set_HP(float _type) { Hp_Count = _type; }
    void Set_Player(CObj* pPlayer) { m_Boss_pPlayer = pPlayer; } // 플레이어 객체 설정

    void Set_Ground(bool _bisGround)
    {
        m_bisGround = _bisGround;
    }
    bool Get_Ground()
    {
        return m_bisGround;
    }
    void SetJump(bool _isjump) { m_bJump = _isjump; }//동완,점프상태설정
    bool GetJump() { return m_bJump; }//동완, 점프상태반환


    CObj* Create_Bullet();
    void Jumping();


private:
    ////////////////////////////////////////////

    /// <summary>
    /// //////////////////////////////////////////
    /// </summary>
    list<CObj*>* m_p_Boss_Bullet;
    unsigned long long m_ullLast_Fire;
    INFO HP_INFO;
    CObj* m_Boss_pPlayer; // 플레이어 객체를 저장할 멤버 변수

private:
    int Bullet_X;
    float MAX_Hp; // 기본 체력
    float Hp_Count; // 보스에 충돌할때마다 체크

    bool                m_bJump; // 점프체크
    float               m_fJumpPower;//점프속도
    float               m_fTime; // 시간
    bool                m_bisGround; 

        ////////////////////////


        bool m_Boss_Ground;

    ////////
    enum GUTSTATE{ STATE_IDLE, STATE_MOVE, STATE_HOLD, STATE_ATTACK, STATE_JUMP, STATE_END};
    GUTSTATE    m_enState;
    UINT         m_iStateCooldown;
    bool        m_bHoldBullet;
    void        Attack();
    void        Jump();
    DIRECTION   m_enMovingDir;
public:
    bool    Get_HoldBullet() { return m_bHoldBullet; }
    DIRECTION Get_Direction() { return m_eDir; }

};

