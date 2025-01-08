#pragma once

#include "Define.h"

class CSoundMgr
{
public:
    static CSoundMgr* Get_Instance()
    {
        if (nullptr == m_pInstance)
            m_pInstance = new CSoundMgr; 

        return m_pInstance; 
    }
    static void Destroy_Instance()
    {
        if (m_pInstance)
        {
            delete m_pInstance; 
            m_pInstance = nullptr; 
        }
    }

private:
    CSoundMgr();
    ~CSoundMgr();

public:
    void Initialize(); 
    void Release(); 

public:
    void PlaySound(const TCHAR* pSoundKey, CHANNELID eID, float fVolume);
    void PlayBGM(const TCHAR* pSoundKey, float fVolume, CHANNELID eID = SOUND_BGM);
    void StopSound(CHANNELID eID);
    void StopAll();
    void ChangeChannelVolume(CHANNELID eID, float fVolume);
    void SetChannelVolume(CHANNELID eID, float fVolume);

    void PlaySoundFaster(CHANNELID eID, float fFrequency);

    // ���ο� �Լ� ����
    bool IsChannelPeakLevelAboveThreshold(CHANNELID eID);

private:
    void LoadSoundFile(); 

private:
    static CSoundMgr* m_pInstance; 

    // ���� ���ҽ� ������ ���� ��ü 
    map<TCHAR*, FMOD_SOUND*> m_mapSound; 
    
    // FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
    FMOD_CHANNEL* m_pChannelArr[SOUND_END];

    // ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
    FMOD_SYSTEM* m_pSystem; 

public:
    void    PlaySound_DigVoice();
    void    PlaySound_AttackVoice();
};
