#include <windows.h>

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void Addmenus(HWND);
HMENU hMenu;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"MyWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
    {
        return -1;
    }
    CreateWindowW(L"MyWindowClass", L"MY WINDOW", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:

        switch (wp)
        {
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case FILE_MENU_NEW:
            MessageBeep(MB_ICONINFORMATION);
            break;
        }
        break;

    case WM_CREATE:
        Addmenus(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void Addmenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    HMENU hSubMenu = CreateMenu();

    AppendMenu(hSubMenu, MF_STRING, 0, "Create");
    AppendMenu(hSubMenu, MF_STRING, 0, "Create Now");
    AppendMenu(hSubMenu, MF_STRING, 0, "Create Later");

    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_NEW, "New");
    AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Open");
    AppendMenu(hFileMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
    AppendMenu(hMenu, MF_STRING, 0, "Help");

    SetMenu(hWnd, hMenu);
}
