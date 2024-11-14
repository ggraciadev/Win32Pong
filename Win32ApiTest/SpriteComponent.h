#pragma once

#include "IDrawableComponent.h"
#include "Bitmap.h"

class SpriteComponent : public IDrawableComponent
{

public:
    SpriteComponent() {}
    ~SpriteComponent() {}

protected:
    Bitmap* m_bitmap;

public:
    virtual void Draw() {}
};