#pragma once
#include "CObj.h"
class CHeartbeat : public CObj
{
public:
	CHeartbeat(): m_iBeat(0) {}
	~CHeartbeat() {}

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	int m_iBeat;
	ULONGLONG m_ullTimeTick;
	ULONGLONG m_ullBPM;

	chrono::system_clock::time_point m_tBGMStart;
	chrono::system_clock::time_point m_tTimeStart;
	chrono::duration<double> m_llTimeChecker;

};

