#pragma once
#include "ActorComponent.h"
#include <set>
#include "../Utils/Utils.h"

class MovementComponent : public ActorComponent
{

public:
	MovementComponent();

protected:

	float                   m_maxSpeed = 0;             // Max movement speed of the Movement Component
	float                   m_currentSpeed = 0;         // Current movement speed of the Movement Component
	Vector2D                m_movementDirection;    // Current Movement direction of the Movement Component


/**
This event is called at the begining of the destructor method
 */
	virtual void EndPlay();

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
	virtual void BeginPlay();

	virtual void Tick(float deltaTime);

	inline float GetMaxSpeed() const { return m_maxSpeed; }
	inline void SetMaxSpeed(float speed) { m_maxSpeed = speed; }

	inline float GetCurrentSpeed() const { return m_currentSpeed; }
	inline void SetCurrentSpeed(float speed) { m_currentSpeed = CLAMP(speed, -m_maxSpeed, m_maxSpeed); }

	Vector2D GetMovementDirection() const { return m_movementDirection; }
	void SetMovementDirection(Vector2D dir) { m_movementDirection = dir.GetNormal(); }
	void SetMovementDirection(float x, float y) { SetMovementDirection(Vector2D(x,y)); }
	void SetMovementDirectionX(float x) { SetMovementDirection(Vector2D(x, m_movementDirection.GetY())); }
	void SetMovementDirectionY(float y) { SetMovementDirection(Vector2D(m_movementDirection.GetX(), y)); }
};