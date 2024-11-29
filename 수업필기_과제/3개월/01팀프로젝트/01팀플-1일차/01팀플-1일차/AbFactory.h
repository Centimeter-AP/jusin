#pragma once
#include "Obj.h"

template<typename T>
class CAbFactory
{
public:
	static CObj*	Create()
	{
		CObj* temp = new T;
		temp->Initialize();

		return temp;
	}
	static CObj*	Create(float _fX, float _fY, KDIRECTION enDir)
	{
		CObj* temp = new T;
		temp->Initialize();
		temp->Set_Pos(_fX, _fY);
		temp->Set_Dir(enDir);

		return temp;
	}
};

