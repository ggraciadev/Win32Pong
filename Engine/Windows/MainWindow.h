#pragma once
#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

#include "BaseWindow.h"

class GameManager;

class MainWindow : public BaseWindow<MainWindow>
{
    ID2D1Factory* pFactory;
    ID2D1HwndRenderTarget* pRenderTarget;
    PAINTSTRUCT pPaintStructure;
    //EllipseActor* pEllipseActor;
    GameManager* pGameManager = NULL;
    
    /*ID2D1SolidColorBrush* pBrush;
    D2D1_ELLIPSE            ellipse = D2D1_ELLIPSE();*/

    void    CalculateLayout();
    HRESULT CreateGraphicsResources();
    void    DiscardGraphicsResources();
    void    Resize();

public:

    MainWindow() : pFactory(NULL), pRenderTarget(NULL)
    {
    }
    void    OnPaint();
    void    StartRender();
    void    EndRender();

    PCWSTR  ClassName() const { return L"Circle Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};



