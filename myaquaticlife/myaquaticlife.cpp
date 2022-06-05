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

typedef struct {
    DWORD val1; // dword 0
    DWORD val2; // dword 4
    DWORD val3; // dword 8
    DWORD val4; // dword 12
    DWORD val5; // dword 16
    DWORD val6; // dword 20
    DWORD val7; // dword 24
    HWND val8; // dword 28
    DWORD val9; // dword 32
    DWORD val10; // dword 36
    DWORD val11; // dword 40
    DWORD val12; // dword 44
    DWORD val13; // dword 48
    DWORD val14; // dword 52
    Aqua_Class2* val15; // dword 56

} Aqua_Class1, *PAqua_Class1;

typedef struct {
    DWORD val1; // dword 0
    DWORD val2; // dword 4
    DWORD val3; // dword 8
    DWORD val4; // dword 12
    DWORD val5; // dword 16
    DWORD val6; // dword 20
    DWORD val7; // dword 24
    DWORD val8; // dword 28
    DWORD val9; // dword 32
    DWORD val10; // dword 36
    DWORD val11; // dword 40
    DWORD val12; // dword 44
    DWORD val13; // dword 48
    DWORD val14; // dword 52
    DWORD val15; // dword 56
    DWORD val16; // dword 60
    DWORD val17; // dword 64
    DWORD val18; // dword 68
    DWORD val19; // dword 72
    DWORD val20; // dword 76
    DWORD val21; // dword 80
    DWORD val22; // dword 84
    DWORD val23; // dword 88
    DWORD val24; // dword 92
    DWORD val25; // dword 96
    DWORD val26; // dword 100
    DWORD val27; // dword 104
    DWORD val28; // dword 108
    int((*val29))(Aqua_Class2*); // dword 112

} Aqua_Class2, * PAqua_Class2;

// sub_4D7997 : Aqua_Class1_Method2
LONG Aqua_Class1_Method2(Aqua_Class1* _this)
{
    Aqua_Class2* v1; // eax

    v1 = _this->val15;
    if (v1)
        return v1->val29(_this->val15);
    else
        return GetWindowLongA(_this->val8, GWL_STYLE);
}

// sub_4D731F : Aqua_Class1_MessageLoop
DWORD Aqua_Class1_MessageLoop(Aqua_Class1* _this, char a2)
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
    if ((a2 & 4) == 0 || (v10 = 1, (Aqua_Class1_Method2(_this) & 0x10000000) != 0))
        v10 = 0;
    Parent = GetParent(_this->val8);
    _this->val10 = (_this->val10 | 0x18);
    hWnd = Parent;
    //v4 = (struct tagMSG*)(sub_4DA0DD() + 48);
LABEL_5:
    while (v12 && !PeekMessageA(v4, 0, 0, 0, 0))
    {
        if (v10)
        {
            //sub_4D7B2E(1);
            UpdateWindow(_this->val8);
            v10 = 0;
        }
        if ((a2 & 1) == 0 && hWnd && !lParam)
            SendMessageA(hWnd, WM_ENTERIDLE, MSGF_DIALOGBOX, (LPARAM)_this->val8);
        if ((a2 & 2) == 0)
        {
            v5 = lParam++;
            if (SendMessageA(_this->val8, 0x36Au, 0, v5))
                continue;
        }
        v12 = 0;
    }
    while (1)
    {
        //v6 = sub_4DA0DD();
        if (!(*(int(__thiscall**)(int))(*(DWORD*)v6 + 92))(v6))
        {
            //sub_4E22EB(0);
            //return HWND_MESSAGE | 0x2;
        }
        if (v10)
        {
            message = v4->message;
            if (message == 280 || message == 260)
            {
                //sub_4D7B2E(1);
                UpdateWindow(_this->val8);
                v10 = 0;
            }
        }
        //if (!(*((int(__thiscall**)(HWND*)) * _this + 28))(_this))
        //    break;
        //v8 = sub_4DA0DD();
        if ((*(int(__thiscall**)(int, struct tagMSG*))(*(DWORD*)v8 + 100))(v8, v4))
        {
            v12 = 1;
            lParam = 0;
        }
        if (!PeekMessageA(v4, 0, 0, 0, 0))
            goto LABEL_5;
    }
    _this->val10 = (_this->val10 & 0xFFFFFFE7);
    return _this->val12;
}

// sub_4D1C57 : wWinMain
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    return 0;
}
