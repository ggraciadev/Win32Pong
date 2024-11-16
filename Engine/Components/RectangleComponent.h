#pragma once
#include "DrawableShapeComponent.h"


class RectangleComponent : public DrawableShapeComponent
{

public:
	RectangleComponent();

protected:
	Vector2D			pRectangleSize;						// The size of the rectangle represented as a Vector2D
	Vector2D			pCornerRadius;						// The radius of the corners of the rectangle represented as a Vector2D
	D2D1_ROUNDED_RECT	pRectangle = D2D1_ROUNDED_RECT();	// The D2D1 rectangle that should be rendered

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
* This method returns a reference of the rectangle size
* @return A reference of the rectangle size of the RectangleComponent
*/
	Vector2D* GetRectangleSize() { return &pRectangleSize; }

/**
* This method sets a new value for the rectangle size
* @param The new size for the rectangle as a Vector2D
*/
	inline void SetRectangleSize(const Vector2D& size) { pRectangleSize = size; }

/**
* This method sets a new value for the rectangle size
* @param The new rectangle size as two floats, one for the X value and another for the Y value
*/
	inline void SetRectangleSize(const float sizeX, const float sizeY) { SetRectangleSize(Vector2D(sizeX, sizeY)); }


/**
* This method returns a reference of the rectangle corner radius
* @return A reference of the rectangle corner radius of the RectangleComponent
*/
	Vector2D* GetCornerRadius() { return &pCornerRadius; }

/**
* This method sets a new value for the rectangle corner radius
* @param The new rectangle corner radius as a Vector2D
*/
	inline void SetCornersRadius(const Vector2D& radius) { pCornerRadius = radius; }

/**
* This method sets a new value for the rectangle corner radius
* @param The new rectangle corner radius as two floats, one for the X value and another for the Y value
*/
	inline void SetCornersRadius(const float radiusX, const float radiusY) { SetCornersRadius(Vector2D(radiusX, radiusY)); }

	
};