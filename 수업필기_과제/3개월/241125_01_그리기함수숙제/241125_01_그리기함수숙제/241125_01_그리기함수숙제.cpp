// 241125_01_그리기함수숙제.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "241125_01_그리기함수숙제.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY24112501, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY24112501));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (true)/*(GetMessage(&msg, nullptr, 0, 0))*/           // GetMessage 대신 PeekMessage사용(메세지엿보기)
    {

        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY24112501));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 800,600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

RECT    plrc{ 200,200,250,250 };

struct BULLETINFO
{
    RECT   rc;
    int     dx;
    int     dy;
};


list<BULLETINFO> BulletLst1;
list<BULLETINFO> BulletLst2;
list<BULLETINFO> BulletLst3;

enum KDIRECTION
{
    KUP,
    KDOWN,
    KLEFT,
    KRIGHT,
    KEND
};

KDIRECTION  enDir = KUP;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 0, 10, 0);
        break;
    case WM_TIMER:
        InvalidateRect(hWnd, 0, TRUE);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }   
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            HBRUSH BlueBrush = CreateSolidBrush(RGB(150, 190, 255));
            HBRUSH GrayBrush = CreateSolidBrush(RGB(200, 200, 200));
            HBRUSH WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
            HBRUSH PinkBrush = CreateSolidBrush(RGB(255, 220, 220));
            HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 40));
            HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, PinkBrush);

            /***********************************************************************************************/
            POINT pPos[12]{ {400,150}, {320, 80},  {250, 50}, {150, 80}, {100, 200}, {150, 300}, {400, 500}, 
                                       {650, 300}, {700, 200},{650, 80}, {550, 50},  {480, 80}};
            Polygon(hdc, pPos, 12);
            /***********************************************************************************************/
            OldBrush = (HBRUSH)SelectObject(hdc, GrayBrush);
            Rectangle(hdc, 625, 120, 680, 130);
            Rectangle(hdc, 625, 115, 675, 135);
            OldBrush = (HBRUSH)SelectObject(hdc, RedBrush);
            Ellipse(hdc, 600, 100, 650, 150);
            /***********************************************************************************************/
            OldBrush = (HBRUSH)SelectObject(hdc, GrayBrush);
            Rectangle(hdc, 155, 420, 195, 510);
            OldBrush = (HBRUSH)SelectObject(hdc, RedBrush);
            Ellipse(hdc, 150, 450, 200, 500);
            /***********************************************************************************************/




            OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);

            for (auto& iter : BulletLst1)
            {
                Ellipse(hdc, iter.rc.left + 15, iter.rc.top + 15, iter.rc.right - 15, iter.rc.bottom - 15);
                iter.rc.top += iter.dy;
                iter.rc.bottom += iter.dy;
                iter.rc.left += iter.dx;
                iter.rc.right += iter.dx;
            }
            for (auto& iter : BulletLst2)
            {
                Ellipse(hdc, iter.rc.left + 15, iter.rc.top + 15, iter.rc.right - 15, iter.rc.bottom - 15);
                iter.rc.top += iter.dy;
                iter.rc.bottom += iter.dy;
                iter.rc.left += iter.dx;
                iter.rc.right += iter.dx;
            }
            for (auto& iter : BulletLst3)
            {
                Ellipse(hdc, iter.rc.left + 15, iter.rc.top + 15, iter.rc.right - 15, iter.rc.bottom - 15);
                iter.rc.top += iter.dy;
                iter.rc.bottom += iter.dy;
                iter.rc.left += iter.dx;
                iter.rc.right += iter.dx;
            }
            
            OldBrush = (HBRUSH)SelectObject(hdc, GrayBrush);
            switch (enDir)
            {
            case KUP:
                Rectangle(hdc, plrc.left + 15, plrc.top - 25, plrc.right - 15, plrc.bottom - 25);
                break;
            case KDOWN:
                Rectangle(hdc, plrc.left + 15, plrc.top + 25, plrc.right - 15, plrc.bottom + 25);
                break;
            case KLEFT:
                Rectangle(hdc, plrc.left - 25, plrc.top + 15, plrc.right - 25, plrc.bottom - 15);
                break;
            case KRIGHT:
                Rectangle(hdc, plrc.left + 25, plrc.top + 15, plrc.right + 25, plrc.bottom - 15);
                break;
            default:
                break;
            }
            OldBrush = (HBRUSH)SelectObject(hdc, BlueBrush);
            Ellipse(hdc, plrc.left, plrc.top, plrc.right, plrc.bottom);
            OldBrush = (HBRUSH)SelectObject(hdc, WhiteBrush);
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_UP:
            plrc.top -= 10;
            plrc.bottom -= 10;
            enDir = KUP;
            break;
        case VK_DOWN:
            plrc.top += 10;
            plrc.bottom += 10;
            enDir = KDOWN;
            break;
        case VK_LEFT:
            plrc.left -= 10;
            plrc.right -= 10;
            enDir = KLEFT;
            break;
        case VK_RIGHT:
            plrc.left += 10;
            plrc.right += 10;
            enDir = KRIGHT;
            break;
        case VK_SPACE:
            BulletLst1.push_back(BULLETINFO{ plrc, 0, 0 });
            BulletLst2.push_back(BULLETINFO{ plrc, 0, 0 });
            BulletLst3.push_back(BULLETINFO{ plrc, 0, 0 });

            switch (enDir)
            {
            case KUP:
                BulletLst1.back().dy = -10;
                BulletLst2.back().dy = -10;
                BulletLst2.back().dx = -10;
                BulletLst3.back().dy = -10;
                BulletLst3.back().dx = 10;
                break;
            case KDOWN:
                BulletLst1.back().dy = 10;
                BulletLst2.back().dy = 10;
                BulletLst2.back().dx = 10;
                BulletLst3.back().dy = 10;
                BulletLst3.back().dx = -10;
                break;
            case KLEFT:
                BulletLst1.back().dx = -10;
                BulletLst2.back().dy = 10;
                BulletLst2.back().dx = -10;
                BulletLst3.back().dy = -10;
                BulletLst3.back().dx = -10;
                break;
            case KRIGHT:
                BulletLst1.back().dx = 10;
                BulletLst2.back().dy = -10;
                BulletLst2.back().dx = 10;
                BulletLst3.back().dy = 10;
                BulletLst3.back().dx = 10;
                break;
            }

            if (BulletLst1.begin()->rc.left < 0 || BulletLst1.begin()->rc.top < 0 || BulletLst1.begin()->rc.right > 800 || BulletLst1.begin()->rc.bottom > 600)
                BulletLst1.pop_front();
            if (BulletLst2.begin()->rc.left < 0 || BulletLst2.begin()->rc.top < 0 || BulletLst2.begin()->rc.right > 800 || BulletLst2.begin()->rc.bottom > 600)
                BulletLst2.pop_front();
            if (BulletLst3.begin()->rc.left < 0 || BulletLst3.begin()->rc.top < 0 || BulletLst3.begin()->rc.right > 800 || BulletLst3.begin()->rc.bottom > 600)
                BulletLst3.pop_front();
            break;
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
