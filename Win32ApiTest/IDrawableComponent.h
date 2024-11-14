#pragma once

class IDrawableComponent
{

protected:
    ID2D1HwndRenderTarget* pRenderTarget;

public:
    virtual void Draw() = 0;

    void Init(ID2D1HwndRenderTarget* renderTarget);
};