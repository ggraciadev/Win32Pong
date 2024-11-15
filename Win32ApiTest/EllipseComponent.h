#pragma once
#include "DrawableShapeComponent.h"


class EllipseComponent : public DrawableShapeComponent
{

public:
	EllipseComponent();

protected:
	Vector2D		pEllipseRadius;
	D2D1_ELLIPSE	pEllipse = D2D1_ELLIPSE();

	virtual void EndPlay();

public:
	virtual void BeginPlay();
	virtual void Draw(ID2D1HwndRenderTarget* renderTarget);
	virtual void UpdateShape();

	Vector2D GetEllipseRadius() const { return pEllipseRadius; }
	void SetEllipseRadius(const Vector2D& ellipseRadius) { pEllipseRadius = ellipseRadius; }
	void SetEllipseRadius(const float ellipseRadiusX, const float ellipseRadiusY) { SetEllipseRadius(Vector2D(ellipseRadiusX, ellipseRadiusY)); }
	
};