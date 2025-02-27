#pragma once
#include "Obj.h"
class CMyMap :
    public CObj
{
public:
    CMyMap();
    virtual ~CMyMap();
public:
    HRESULT Initialize(void) override;
    int Update(void) override;
    void Late_Update(void) override;
    void Render(void) override;
    void Release(void) override;

private:
    wstring strMap;
};

