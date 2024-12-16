#include "pch.h"
#include "CWall.h"

CWall::CWall()
    : m_iHP(0), m_iPowerNeeded(0)
{
    ZeroMemory(&m_iWallNumber, sizeof(m_iWallNumber));
}

CWall::~CWall()
{
}

void CWall::Initialize()
{
}

int CWall::Update()
{
    return 0;
}

void CWall::Late_Update()
{
}

void CWall::Render(HDC hDC)
{
}

void CWall::Release()
{
}
