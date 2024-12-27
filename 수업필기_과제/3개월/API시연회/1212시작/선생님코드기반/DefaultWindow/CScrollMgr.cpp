#include "pch.h"
#include "CScrollMgr.h"

CScrollMgr* CScrollMgr::m_pInstance = nullptr;

CScrollMgr::CScrollMgr() : m_fScrollX(0.f), m_fScrollY(0.f)
{
}

CScrollMgr::~CScrollMgr()
{
}

void CScrollMgr::Scroll_Lock()				// �ʿ� ���� ������ ��?
{
	if (0.f < m_fScrollX)
		m_fScrollX = 0.f;

	if (WINCX - 1920.f > m_fScrollX)
		m_fScrollX = WINCX - 1920.f;

	if (0.f < m_fScrollY)
		m_fScrollY = 0.f;

	if (WINCY - 1280.f > m_fScrollY)
		m_fScrollY = WINCY - 1280.f;
}

//void CScrollMgr::Scroll_Shake03()
//{
//
//    if (m_bShake03) // UI ��鸮�� ����
//    {
//        m_iShakeTime03--;
//        if (m_iShakeTime03 <= 0)
//        {
//            m_bShake03 = false;
//            m_iShakeTime03 = 10;
//            m_fScrollX = Get_ScrollX(); // ��ũ���� ��Ȯ�� �ʱ� ��ġ�� ����
//            m_fScrollY = Get_ScrollY();
//            m_fShakeTimeElapsed = 1.0f; // ��鸲 �ð� �ʱ�ȭ
//            return;
//        }
//
//        // ���� ��ũ�� ��ġ ��������
//        float CurrentScrollX = Get_ScrollX();
//        float CurrentScrollY = Get_ScrollY();
//
//        float attenuation = float(m_iShakeTime03) / 60.0f; // �ʱ� ��鸲 ���� ���� (60�� �ʱⰪ���� ����)
//        if (attenuation < 0.3f)
//            attenuation = 0.3f; // �ּ� ���� �� ���� (�ʹ� �������� �ʵ���)
//
//        // ��鸲 �ֱ� 15 = �ʹ� , 10 = �Ĺ�
//        float frequencyMultiplier = 15.0f - (10.0f * attenuation);
//
//        // ��鸲 ���� (20.f)
//        float offsetX = attenuation * 30.0f * sinf(m_fShakeTimeElapsed * frequencyMultiplier); // X�� ��鸲
//        float offsetY = attenuation * 30.0f * sinf(m_fShakeTimeElapsed * (frequencyMultiplier + 1.0f)); // Y�� ��鸲
//        // ��鸲 �ð� ����
//        m_fShakeTimeElapsed += 0.3f; // �ð� �帧�� ���� ������ ����
//
//        // ��鸲 ����
//        m_fScrollX = CurrentScrollX + offsetX;
//        m_fScrollY = CurrentScrollY + offsetY;
//    }
//
//}