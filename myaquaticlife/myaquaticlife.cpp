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

void sub_4BB144() {
    //TODO: Add code
}

void sub_4DDF8E() {
    //TODO: Add code
}

void sub_4DE68E() {
    //TODO: Add code
}

void sub_4D5554() {
    //TODO: Add code
}

void sub_4D5508(int val) {
    //TODO: Add code
}

char* sub_4DF5C7(void* data) {
    //TODO: Add code
    return NULL;
}

int sub_4DF689(void* data) {
    //TODO: Add code
    return 0;
}

int sub_4D503A(HWND hWnd) {
    //TODO: Add code
    return 0;
}

int sub_4DE606()
{
    int result; // eax

    result = *(DWORD*)(sub_4DF5C7(sub_4DDF8E) + 4);
    if (!result)
        return sub_4DF689(sub_4DE68E);
    return result;
}

HWND sub_4D8E88(int val) 
{
    //TODO: Add code
    return NULL;
}

int sub_4D7997(int val) 
{
    //TODO: Add code
    return 0;
}

void sub_4D731F(char val) 
{
    //TODO: Add code
}

void sub_4D7ADF(int v1, int v2, int v3, int v4, int v5, int v6) 
{
    //TODO: Add code
}

void sub_4D8EC2(int val) 
{
    //TODO: Add code
}

//Unknown Class
typedef struct _CLASS1 {
    DWORD val8; // dword [ a1 - 32 ]
    DWORD val7; // dword [ a1 - 28 ]
    DWORD val6; // dword [ a1 - 24 ]
    HWND val5;  // dword [ a1 - 20 ]
    int* val4;  // dword [ a1 - 16 ]
    DWORD val3; // dword [ a1 - 12 ]
    DWORD val2; // dword [ a1 - 8 ]
    DWORD val1; // dword [ a1 - 4 ]

} CLASS1, *PCLASS1;

BOOL sub_4D8C20(CLASS1* cls, DWORD dwValue, int val, HMODULE hModule) {
    return FALSE;
}

int sub_4D8F04(CLASS1* a1, unsigned int ecx)
{
    a1 -= 1;

    int v1 = ecx; // ecx
    int v2; // esi
    HGLOBAL Resource; // edi
    HMODULE v4; // ebx
    HRSRC ResourceA; // eax
    bool v7; // zf
    int v8; // eax
    char v9; // bl
    int v10; // [esp-24h] [ebp-24h] BYREF

    sub_4BB144();
    v2 = v1;
    a1->val4 = &v10;
    a1->val7 = v1;
    Resource = *(HGLOBAL*)(v1 + 68);
    a1->val6 = *(DWORD*)(v1 + 72);
    v4 = *(HMODULE*)(sub_4DE606() + 12);
    if (*(DWORD*)(v2 + 64))
    {
        v4 = *(HMODULE*)(sub_4DE606() + 12);
        ResourceA = FindResourceA(v4, *(LPCSTR*)(v2 + 64), RT_DIALOG);
        Resource = LoadResource(v4, ResourceA);
    }
    if (Resource)
        a1->val6 = (DWORD)LockResource(Resource);
    if (!a1->val6)
        return -1;
    a1->val5 = sub_4D8E88(v2);
    sub_4D5554();
    v7 = a1->val5 == 0;
    a1->val8 = 0;
    if (!v7 && IsWindowEnabled(a1->val5))
    {
        EnableWindow(a1->val5, FALSE);
        a1->val8 = 1;
    }
    a1->val1 = 0;
    sub_4D5508(v2);
    v8 = sub_4D503A(a1->val5);
    if (sub_4D8C20(a1, a1->val6, v8, v4))
    {
        if ((*(BYTE*)(v2 + 36) & 0x10) != 0)
        {
            v9 = 4;
            if ((sub_4D7997(v2) & 0x100) != 0)
                v9 = 5;
            sub_4D731F(v9);
        }
        if (*(DWORD*)(v2 + 28))
            sub_4D7ADF(0, 0, 0, 0, 0, 0x97u);
    }
    a1->val1 = -1;
    if (a1->val8)
        EnableWindow(a1->val5, TRUE);
    if (a1->val5)
    {
        if (GetActiveWindow() == *(HWND*)(v2 + 28))
            SetActiveWindow(a1->val5);
    }
    (*(void(__thiscall**)(int))(*(DWORD*)v2 + 88))(v2);
    sub_4D8EC2(v2);
    return *(DWORD*)(v2 + 44);
}

// sub_4D1C57 : wWinMain
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    return 0;
}
