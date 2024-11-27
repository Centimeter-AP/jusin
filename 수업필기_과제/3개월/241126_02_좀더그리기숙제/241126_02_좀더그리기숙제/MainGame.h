#pragma once
#include "pch.h"
// 1. W, A, S, D Ű�� ���� ��� �� ������ ���ϴ� �̻��� �߻��ϱ�
// 2. ��ü ȭ�麸�� ���� 100, ���� 100 ���� �簢���� �׸��� �� ������ ��� �̻��� �Ҹ��Ű��
// 3. ���� �簢�� �ȿ��� �·� �Ǵ� ��� ���ϴ� ���͸� �����ϱ�
// 4. �߻��� �Ѿ˰� ���Ͱ� �浹�� ��� �����ض�

// BOOL IntersectRect(�浹�� ��Ʈ�� ���� �߻��� ��Ʈ�� ������ ������ �ּ�, ��Ʈ �ּ�1, ��Ʈ �ּ�2)

class CObj;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void	Update();
	void	Render();
	void	Initialize();
	void	Release();

public:

private:
	HDC			 m_hdc;
	CObj*		 m_pPlayer;
	CObj*		 m_pMonster;
	list<CObj*>	 m_BulletList;
	RECT		 m_temp;
};
