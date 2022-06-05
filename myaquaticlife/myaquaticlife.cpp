// myaquaticlife.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "myaquaticlife.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYAQUATICLIFE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MYAQUATICLIFE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
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

// Message handler for about box.
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

HWND __thiscall sub_4D731F(HWND* this, char a2)
{
    HWND Parent; // eax
    struct tagMSG* v4; // ebp
    LPARAM v5; // eax
    int v6; // eax
    UINT message; // eax
    int v8; // eax
    int v10; // [esp+10h] [ebp-10h]
    LPARAM lParam; // [esp+14h] [ebp-Ch]
    int v12; // [esp+18h] [ebp-8h]
    HWND hWnd; // [esp+1Ch] [ebp-4h]

    v12 = 1;
    lParam = 0;
    if ((a2 & 4) == 0 || (v10 = 1, (sub_4D7997(this) & 0x10000000) != 0))
        v10 = 0;
    Parent = GetParent(this[7]);
    this[9] = (HWND)((unsigned int)this[9] | 0x18);
    hWnd = Parent;
    v4 = (struct tagMSG*)(sub_4DA0DD() + 48);
LABEL_5:
    while (v12 && !PeekMessageA(v4, 0, 0, 0, 0))
    {
        if (v10)
        {
            sub_4D7B2E(1);
            UpdateWindow(this[7]);
            v10 = 0;
        }
        if ((a2 & 1) == 0 && hWnd && !lParam)
            SendMessageA(hWnd, 0x121u, 0, (LPARAM)this[7]);
        if ((a2 & 2) == 0)
        {
            v5 = lParam++;
            if (SendMessageA(this[7], 0x36Au, 0, v5))
                continue;
        }
        v12 = 0;
    }
    while (1)
    {
        v6 = sub_4DA0DD();
        if (!(*(int(__thiscall**)(int))(*(_DWORD*)v6 + 92))(v6))
        {
            sub_4E22EB(0);
            return HWND_MESSAGE | 0x2;
        }
        if (v10)
        {
            message = v4->message;
            if (message == 280 || message == 260)
            {
                sub_4D7B2E(1);
                UpdateWindow(this[7]);
                v10 = 0;
            }
        }
        if (!(*((int(__thiscall**)(HWND*)) * this + 28))(this))
            break;
        v8 = sub_4DA0DD();
        if ((*(int(__thiscall**)(int, struct tagMSG*))(*(_DWORD*)v8 + 100))(v8, v4))
        {
            v12 = 1;
            lParam = 0;
        }
        if (!PeekMessageA(v4, 0, 0, 0, 0))
            goto LABEL_5;
    }
    this[9] = (HWND)((unsigned int)this[9] & 0xFFFFFFE7);
    return this[11];
}

// sub_4D1C57 : wWinMain
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    return 0;
}
