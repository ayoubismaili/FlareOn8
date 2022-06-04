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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MYAQUATICLIFE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MYAQUATICLIFE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



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

int sub_4DA0DD()
{
    int result; // eax

    result = *(_DWORD*)(sub_4DE62C() + 4);
    if (!result)
        return *(_DWORD*)(sub_4DE606() + 4);
    return result;
}

int sub_4DE606()
{
    int result; // eax

    result = *(_DWORD*)(sub_4DF5C7(sub_4DDF8E) + 4);
    if (!result)
        return sub_4DF689(sub_4DE68E);
    return result;
}

unsigned __int8* __cdecl sub_4C0678(unsigned __int8* a1)
{
    unsigned __int8* result; // eax

    result = a1 + 1;
    if ((*((_BYTE*)&dword_582748[374] + *a1 + 1) & 4) != 0)
        return a1 + 2;
    return result;
}

int __stdcall sub_4DFC02(char* a1, int a2, int a3)
{
    char* v3; // esi
    char* v4; // edi
    char v5; // al

    v3 = a1;
    v4 = a1;
    while (*v3)
    {
        v5 = *v3;
        if (*v3 == 92 || v5 == 47 || v5 == 58)
            v4 = (char*)sub_4C0678(v3);
        v3 = (char*)sub_4C0678(v3);
    }
    if (!a2)
        return lstrlen(v4) + 1;
    lstrcpyn(a2, v4, a3);
    return 0;
}

int __cdecl sub_4BE192(int a1)
{
    int v1; // eax
    int v2; // eax

    if (a1 && (v1 = sub_4BD360(a1), (v2 = sub_4BBC99(v1 + 1)) != 0))
        return sub_4BC9C0(v2);
    else
        return 0;
}

int __thiscall sub_4DFAE5(int this)
{
    _DWORD* v2; // edi
    _BYTE* v3; // eax
    int v4; // eax
    int result; // eax
    _BYTE* v6; // ebx
    CHAR v7[256]; // [esp+Ch] [ebp-30Ch] BYREF
    CHAR Filename[260]; // [esp+10Ch] [ebp-20Ch] BYREF
    char v9[260]; // [esp+210h] [ebp-108h] BYREF
    _BYTE* v10; // [esp+314h] [ebp-4h]

    v2 = (_DWORD*)sub_4DE606();
    v2[2] = *(_DWORD*)(this + 104);
    v2[3] = *(_DWORD*)(this + 104);
    GetModuleFileNameA(*(HMODULE*)(this + 104), Filename, 0x104u);
    v3 = (_BYTE*)sub_4C0705(Filename, 46);
    *v3 = 0;
    v10 = v3;
    sub_4DFC02(Filename, v9, 260);
    if (!*(_DWORD*)(this + 136))
        *(_DWORD*)(this + 136) = sub_4BE192(v9);
    if (!*(_DWORD*)(this + 120))
    {
        if (sub_4D951A(0xE000u, v7, 256))
            v4 = sub_4BE192(v7);
        else
            v4 = sub_4BE192(*(_DWORD*)(this + 136));
        *(_DWORD*)(this + 120) = v4;
    }
    result = *(_DWORD*)(this + 120);
    v2[4] = result;
    if (!*(_DWORD*)(this + 140))
    {
        v6 = v10;
        lstrcpy(v10, aHlp);
        result = sub_4BE192(Filename);
        *(_DWORD*)(this + 140) = result;
        *v6 = 0;
    }
    if (!*(_DWORD*)(this + 144))
    {
        lstrcat(v9, aIni);
        result = sub_4BE192(v9);
        *(_DWORD*)(this + 144) = result;
    }
    return result;
}

int __stdcall sub_4DFA82(int a1, int a2, int a3, int a4)
{
    UINT v4; // eax
    int v5; // eax
    _DWORD* v6; // eax

    v4 = SetErrorMode(0);
    LOWORD(v4) = v4 | 0x8001;
    SetErrorMode(v4);
    v5 = sub_4DE606();
    *(_DWORD*)(v5 + 8) = a1;
    *(_DWORD*)(v5 + 12) = a1;
    v6 = *(_DWORD**)(sub_4DE606() + 4);
    if (v6)
    {
        v6[26] = a1;
        v6[27] = a2;
        v6[28] = a3;
        v6[29] = a4;
        sub_4DFAE5(v6);
    }
    if (!*(_BYTE*)(sub_4DE606() + 20))
        sub_4DA1B8();
    return 1;
}

int __stdcall sub_4DB57B(int a1, int a2, int a3, int a4)
{
    int v4; // ebx
    _DWORD* v5; // esi
    int v6; // edi
    int v7; // ecx
    int v8; // eax

    v4 = -1;
    v5 = (_DWORD*)sub_4DA0DD();
    v6 = *(_DWORD*)(sub_4DE606() + 4);
    if (sub_4DFA82(a1, a2, a3, a4) && (!v6 || (*(int(__thiscall**)(int))(*(_DWORD*)v6 + 132))(v6)))
    {
        if ((*(int(__thiscall**)(_DWORD*))(*v5 + 80))(v5))
        {
            v8 = (*(int(__thiscall**)(_DWORD*))(*v5 + 84))(v5);
        }
        else
        {
            v7 = v5[7];
            if (v7)
                (*(void(__thiscall**)(int))(*(_DWORD*)v7 + 88))(v7);
            v8 = (*(int(__thiscall**)(_DWORD*))(*v5 + 104))(v5);
        }
        v4 = v8;
    }
    sub_4E23B5();
    return v4;
}

int __stdcall sub_4D1C57(int a1, int a2, int a3, int a4)
{
    return sub_4DB57B(a1, a2, a3, a4);
}


