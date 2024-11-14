#pragma once
#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

#include "BaseWindow.h"
#include "DrawableShapeComponent.h"

template <class T> void SafeDestroy(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

class MainWindow : public BaseWindow<MainWindow>
{
    ID2D1Factory* pFactory;
    ID2D1HwndRenderTarget* pRenderTarget;
    ID2D1SolidColorBrush* pBrush;
    D2D1_ELLIPSE            ellipse = D2D1_ELLIPSE();

    void    CalculateLayout();
    HRESULT CreateGraphicsResources();
    void    DiscardGraphicsResources();
    void    OnPaint();
    void    Resize();

public:

    MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL)
    {
    }

    PCWSTR  ClassName() const { return L"Circle Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};



