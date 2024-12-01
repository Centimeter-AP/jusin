#include "pch.h"
#include "Stage2.h"
#include "BMonster.h"

void Stage2::SpawnMonster()
{
	if (m_dwTime + 700 < GetTickCount64()) {
		m_dwTime = GetTickCount64();
		switch (rand() % 2)
		{
		case 0:
			m_ObjList[OBJ_MONSTER].push_back(new Monster());
			m_ObjList[OBJ_MONSTER].back()->Initialize();
			m_ObjList[OBJ_MONSTER].back()->Set_Target(m_ObjList[OBJ_PLAYER].front());
		case 1:
			m_ObjList[OBJ_MONSTER].push_back(new BMonster());
			m_ObjList[OBJ_MONSTER].back()->Initialize();
			m_ObjList[OBJ_MONSTER].back()->Set_Target(m_ObjList[OBJ_PLAYER].front());
			dynamic_cast<BMonster*>(m_ObjList[OBJ_MONSTER].back())->Set_BulletMon(&m_ObjList[OBJ_MONBULLET]);
		}
	}
}
