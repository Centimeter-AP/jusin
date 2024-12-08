#pragma once

#include "CScene.h"

class CStage_Hong : public CScene
{
public:
	CStage_Hong();
	~CStage_Hong();


	virtual void Initialize()override;  // 동적할당및초기화

	virtual void Update()override; // 실시간 정보

	virtual void LateUpdate()override;

	virtual void Release()override; // 동적할당해제

	virtual void Render(HDC _hDC)override;



private:


};

