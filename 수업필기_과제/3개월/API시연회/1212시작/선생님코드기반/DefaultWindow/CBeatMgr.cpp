#include "pch.h"
#include "CBeatMgr.h"

CBeatMgr* CBeatMgr::m_pInstance = nullptr;


CBeatMgr::CBeatMgr()
	: m_ullTimeChecker(GetTickCount64()), m_ullTimeTicker(GetTickCount64())
	, m_bIsBeatMissed(true), m_bIsPlayerActed(false)
{
}

CBeatMgr::~CBeatMgr()
{
}

int CBeatMgr::Update()
{
	// �ᱹ ���ڴ� �ð�üũ ���� ��Ʈ�浹ó����..
	return 0;
}

void CBeatMgr::Late_Update()
{
}

void CBeatMgr::Render(HDC hDC)
{
	m_bIsBeatMissed = false;
	m_bIsPlayerActed = false;
}

void CBeatMgr::Release()
{
}
