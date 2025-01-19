#pragma once
class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;
	virtual void Key_Input() PURE;
	virtual void Create_MapObj() PURE;
	virtual void Offset() PURE;
protected:
	float m_fMapXSize;
	float m_fMapYSize;
};

