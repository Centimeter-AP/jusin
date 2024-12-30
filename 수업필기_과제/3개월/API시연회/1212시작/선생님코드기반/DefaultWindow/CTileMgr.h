#pragma once

#include "CTile.h"

class CShovel;
class CTileMgr
{
private:
	CTileMgr();
	~CTileMgr();

public:
	void Initialize() ;
	int Update() ;
	void Late_Update() ;
	void Render(HDC hDC) ;
	void Release() ;

	void		Picking_Tile(POINT pt, int iDrawID, int iOption);
	void		Tile_Shine();
	void		Remove_TileObject(int _TileIdx, TILEOBJECT _OBJID);
	void		Set_TileObject(int _TileIdx, TILEOBJECT _OBJID, CObj* _Obj);
	CObj*		Is_Wall_Exist(float fx, float fy);
	void		Break_Wall(CObj* _pTargetWall, CShovel* _pShovel);
	vector<CObj*>* Get_TileVec() { return &m_vecTile; }
	vector<CObj*>& Get_WallVec() { return m_vecWall; }

	bool		Check_TileObject(int _tileIdx);


	void		Make_Object(POINT pt, int iDrawID, int iOption);
	void		Delete_Object(POINT pt, int iOption);

	void		Save_Tile();
	void		Save_Wall();
	void		Load_Wall();
	void		Load_Tile();

public:
	static CTileMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CTileMgr;

		return m_pInstance;
	}

	static void	Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CTileMgr* m_pInstance;

	vector<CObj*>	m_vecTile;
	vector<CObj*>	m_vecWall;
	vector<CObj*>	m_vecItem;

private:
	//vector<CObj*>* m_pvecWall;

};

