﻿
// MFCApplication_0117View.h: CMFCApplication0117View 클래스의 인터페이스
//

#pragma once


class CMFCApplication0117View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication0117View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication0117View)

// 특성입니다.
public:
	CMFCApplication0117Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCApplication0117View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // MFCApplication_0117View.cpp의 디버그 버전
inline CMFCApplication0117Doc* CMFCApplication0117View::GetDocument() const
   { return reinterpret_cast<CMFCApplication0117Doc*>(m_pDocument); }
#endif

