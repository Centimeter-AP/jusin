#pragma once
#include "CArmor.h"
class CArmorGi :
    public CArmor
{
    // CArmor��(��) ���� ��ӵ�
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
};

