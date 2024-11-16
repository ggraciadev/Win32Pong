#pragma once
#include "DrawableShapeComponent.h"


class EllipseComponent : public DrawableShapeComponent
{

public:
	EllipseComponent();

protected:
	Vector2D		m_ellipseRadius;				// The radius for the Ellipse represented as a Vector2D
	D2D1_ELLIPSE	m_ellipse = D2D1_ELLIPSE();	// The D2D1 ellipse that should be rendered

/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay();

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();

/**
This event is for the rendering of the component if needed. This method should be overrided by every ActorComponent that uses it
*/
	virtual void Draw();

/**
This method is called just before Draw to update every shape positions.
*/
	virtual void UpdateShape();

/**
* This method returns a reference of the ellipse radius
* @return A reference of the ellipse raudius of the EllipseComoponent
*/
	inline Vector2D* GetEllipseRadius() { return &m_ellipseRadius; }

/**
* This method sets a new value for the ellipse radius
* @param The new ellipse radius as a Vector2D
*/
	inline void SetEllipseRadius(const Vector2D& ellipseRadius) { m_ellipseRadius = ellipseRadius; }

/**
* This method sets a new value for the ellipse radius
* @param The new ellipse radius as two floats, one for the X value and another for the Y value
*/
	inline void SetEllipseRadius(const float ellipseRadiusX, const float ellipseRadiusY) { SetEllipseRadius(Vector2D(ellipseRadiusX, ellipseRadiusY)); }
	
};