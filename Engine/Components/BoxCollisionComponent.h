#pragma once
#include "CollisionComponent.h"


class BoxCollisionComponent : public CollisionComponent
{

public:
	BoxCollisionComponent();

protected:
	Vector2D			m_BoxSize;						// The size of the box represented as a Vector2D

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
	virtual void PhysicsTick();

/**
* This method returns a reference of the box size
* @return A reference of the box size of the BoxCollisionComponent
*/
	Vector2D* GetBoxSize() { return &m_BoxSize; }

/**
* This method sets a new value for the box size
* @param The new size for the box as a Vector2D
*/
	inline void SetBoxSize(const Vector2D& size) { m_BoxSize = size; }

/**
* This method sets a new value for the box size
* @param The new box size as two floats, one for the X value and another for the Y value
*/
	inline void SetBoxSize(const float sizeX, const float sizeY) { SetBoxSize(Vector2D(sizeX, sizeY)); }

	
};