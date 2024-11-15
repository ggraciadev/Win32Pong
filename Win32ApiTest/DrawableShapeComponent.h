#pragma once
#include "ActorComponent.h"
#include <d2d1.h>

class DrawableShapeComponent : public ActorComponent
{
public:
	DrawableShapeComponent();
	virtual ~DrawableShapeComponent();


protected:
	D2D1_COLOR_F			pColor;
	ID2D1SolidColorBrush*	pBrush = NULL;

public:
	virtual void Init(Actor* actor);
	virtual void Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget);
	virtual void Init(Actor* actor, const Transform& transform, ID2D1HwndRenderTarget* renderTarget, D2D1_COLOR_F color);

	D2D1_COLOR_F GetColor() const { return pColor; }
	inline void SetColor(D2D1_COLOR_F color) { pColor = color; }

	virtual void BeginPlay();
	virtual void EndPlay();

public:

};