#include "Framework.h"


HINSTANCE g_hInstance;
HDC hdc;
HWND hWnd;
Player* player;

void Init()
{
    //srand((unsigned int)time(nullptr));
    player = new Player();

    // 테스트용 아이템 강제 활성화
    for (int i = 0; i < 10; ++i)
        ItemManager::Get()->GetItem(player); // 강제로 한 번 불러보기 (충돌용)
}

void Update()
{
    if (player != nullptr)
        player->Update();
}

void Render(HDC hdc)
{
    Ellipse(hdc, 100, 100, 150, 150); // 반지름 25짜리 원
    ItemManager::Get()->Render(hdc);
    player->Render(hdc);
}

void Release()
{
    if (player != nullptr)
        delete player;
}

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        Render(hdc);
        EndPaint(hWnd, &ps);
    }
    break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

// WinMain
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    g_hInstance = hInstance;

    // 윈도우 클래스 등록
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyGameWindow";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    // 윈도우 생성
    hWnd = CreateWindowW(L"MyGameWindow", L"Item Test",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
        nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hWnd, nCmdShow);
    //UpdateWindow(hWnd);

    Init();

    MSG msg = {};
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Update();
            InvalidateRect(hWnd, nullptr, FALSE);
        }
    }

    Release();
    return (int)msg.wParam;
}