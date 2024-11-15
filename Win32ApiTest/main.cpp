#ifndef UNICODE
#define UNICODE
#endif 

#include "MainWindow.h"
#include "GameManager.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    MainWindow win;

    if (!win.Create(L"Circle", WS_OVERLAPPEDWINDOW))
    {
        return 0;
    }

    ShowWindow(win.Window(), nCmdShow);

    // Run the message loop.

    MSG msg = { };

    GameManager* gameManager = GameManager::GetInstance();

    LARGE_INTEGER cpu_frequency;
    QueryPerformanceFrequency(&cpu_frequency);
    LARGE_INTEGER last_counter;
    QueryPerformanceCounter(&last_counter);

    while (gameManager->IsGameRunning())
    {
        LARGE_INTEGER current_counter;
        QueryPerformanceCounter(&current_counter);
        int64_t counter_elapsed = current_counter.QuadPart - last_counter.QuadPart;
        float delta = (float)counter_elapsed / (float)cpu_frequency.QuadPart;	// in seconds
        last_counter = current_counter;

        while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);		// Send message to the WindowProc (WindowCallback)
        }

        if (gameManager->IsGameRunning()) {
            gameManager->UpdateScene(delta);
            win.OnPaint();
        }
    }
    delete gameManager;

    return 0;
}