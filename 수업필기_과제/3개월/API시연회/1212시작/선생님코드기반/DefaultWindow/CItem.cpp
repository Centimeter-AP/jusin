#include "pch.h"
#include "CItem.h"
#include "CPlayer.h"

void CItem::Find_TileIdx_OnMap()
{
	m_iTileIdx = ((int)m_tInfo.fY / TILECY) * TILEX + ((int)m_tInfo.fX / TILECX);
}

void CItem::Find_Player_OnSameTile()
{
	if (m_pTarget != nullptr)
	{
		if (static_cast<CPlayer*>(m_pTarget)->Get_CurTileIdx() == m_iTileIdx)
			m_bIsPlayerOnTile = true;
		else
			m_bIsPlayerOnTile = false;
	}
}