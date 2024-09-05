#include <windows.h>

LRESULT CALLBACK Windowprocedure(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWindowprocedure(HWND, UINT, WPARAM, LPARAM);

void AddMenu(HWND);

void registerChildWindow(HINSTANCE);
void displayChildWindow(HWND hWnd);

void displayText(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevinst, LPSTR args, int nCmdShow)
{
    WNDCLASSW wc = {0};
    MSG msg = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = Windowprocedure;
    wc.hInstance = hInst;
    wc.lpszClassName = L"MY WINDOW CLASS";

    if (!RegisterClassW(&wc))
    {
        return -1;
    }

    registerChildWindow(hInst);
    
    HWND hWnd = CreateWindowW(L"MY WINDOW CLASS", L"Notepad", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 500, 500, NULL, NULL, NULL, NULL);

    ShowWindow(hWnd, 3);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK Windowprocedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        AddMenu(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
        break;
    }
}

void AddMenu(HWND hWnd)
{
    HMENU hMenu = CreateMenu();
    HMENU HelpSubMenu = CreateMenu();
    HMENU ViewSubMenu = CreateMenu();
    HMENU FormatSubMenu = CreateMenu();
    HMENU EditSubMenu = CreateMenu();
    HMENU FileSubMenu = CreateMenu();
    HMENU ZoomSubMenu = CreateMenu();

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)FileSubMenu, "File");
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("New\tCtrl+N"));
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("New Window\tCtrl+Shift+N"));
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Open\tCtrl+O"));
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Save\tCtrl+S"));
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Save As\tCtrl+Shift+S"));
    AppendMenu(FileSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Page Setup..."));
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Print...\tCtrl+P"));
    AppendMenu(FileSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(FileSubMenu, MF_STRING, 0, TEXT("Exit"));

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)EditSubMenu, "Edit");
    AppendMenu(EditSubMenu, MF_STRING, 1, TEXT("Undo\tCtrl+Z"));
    AppendMenu(EditSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Cut\tCtrl+X"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Copy\tCtrl+C"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Paste\tCtrl+V"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("delete\tdel"));
    AppendMenu(EditSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Search with bing...\tCtrl+E"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Find...\tCtrl+F"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Find next\tF3"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Find previous\tShift+F3"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Replace\tCtrl+H"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Go to...\tCtrl+G"));
    AppendMenu(EditSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Select All\tCtrl+A"));
    AppendMenu(EditSubMenu, MF_STRING, 0, TEXT("Time/Date\tF5"));

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)FormatSubMenu, TEXT("Format"));
    AppendMenu(FormatSubMenu, MF_STRING, 0, TEXT("Word Wrap"));
    AppendMenu(FormatSubMenu, MF_STRING, 0, TEXT("Font..."));

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)ViewSubMenu, TEXT("View"));
    
    AppendMenu(ViewSubMenu, MF_POPUP, (UINT_PTR)ZoomSubMenu, TEXT("Zoom"));
    AppendMenu(ZoomSubMenu, MF_STRING, 0, TEXT("Zoom In\tCtrl+Plus"));
    AppendMenu(ZoomSubMenu, MF_STRING, 0, TEXT("Zoom Out\tCtrl + Minus"));
    AppendMenu(ZoomSubMenu, MF_STRING, 0, TEXT("Restore Default Zoom\tCtrl + 0"));
    
    AppendMenu(ViewSubMenu, MF_STRING, 0, TEXT("Status Bar"));

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)HelpSubMenu, "Help");
    AppendMenu(HelpSubMenu, MF_STRING, 0, TEXT("View Help"));
    AppendMenu(HelpSubMenu, MF_STRING, 0, TEXT("Send Feedback"));
    AppendMenu(HelpSubMenu, MF_SEPARATOR, 0, 0);
    AppendMenu(HelpSubMenu, MF_STRING, 0, TEXT("About Notepad"));

    SetMenu(hWnd, hMenu);
}

LRESULT CALLBACK ChildWindowprocedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    default:
        return DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}

void registerChildWindow(HINSTANCE hInstance)
{
    WNDCLASSW wcc = {0};

    wcc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcc.lpfnWndProc = ChildWindowprocedure;
    wcc.hInstance = hInstance;
    wcc.lpszClassName = L"MYCHILDWINDOWCLASS";
    RegisterClassW(&wcc);
}

void displayChildWindow(HWND hWnd)
{

    CreateWindowW(L"MYCHILDWINDOWCLASS", L"CHILD WINDOW", WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU, 75, 100, 500, 500, hWnd, NULL, NULL, NULL);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void displayText(HWND hWnd)
{

    CreateWindowW(L"Static", L"About", WS_VISIBLE | WS_CHILD | SS_CENTER, 0, 0, 500, 500, hWnd, NULL, NULL, NULL);
}
