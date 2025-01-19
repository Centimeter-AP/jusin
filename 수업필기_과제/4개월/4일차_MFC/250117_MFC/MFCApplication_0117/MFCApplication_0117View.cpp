
// MFCApplication_0117View.cpp: CMFCApplication0117View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication_0117.h"
#endif

#include "MFCApplication_0117Doc.h"
#include "MFCApplication_0117View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication0117View

IMPLEMENT_DYNCREATE(CMFCApplication0117View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication0117View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCApplication0117View 생성/소멸

CMFCApplication0117View::CMFCApplication0117View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCApplication0117View::~CMFCApplication0117View()
{
}

BOOL CMFCApplication0117View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication0117View 그리기

void CMFCApplication0117View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication0117Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCApplication0117View 인쇄

BOOL CMFCApplication0117View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication0117View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication0117View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication0117View 진단

#ifdef _DEBUG
void CMFCApplication0117View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication0117View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication0117Doc* CMFCApplication0117View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication0117Doc)));
	return (CMFCApplication0117Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication0117View 메시지 처리기


void CMFCApplication0117View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
