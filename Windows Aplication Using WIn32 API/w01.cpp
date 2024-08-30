#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpfnWndProc = WindowProcedure;
    wc.lpszClassName = L"MyWindowClass";

    if (!RegisterClassW(&wc))
    {
        return -1;
    }

    CreateWindowW(L"MyWindowClass", L"MY WINDOW", WS_POPUP | WS_VISIBLE, 100, 100, 800, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wl, LPARAM lp)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wl, lp);
    }
}
