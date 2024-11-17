#pragma once
#include "../../Engine/Objects/Pawn.h"
#include "../../Engine/Components/RectangleComponent.h"
#include "../../Engine/Components/BoxCollisionComponent.h"
#include "../../Engine/Components/MovementComponent.h"

class Paddle : public Pawn
{

public:
    Paddle();
    virtual ~Paddle();

protected:
    RectangleComponent*     m_rectangleComponent;   // The rectangle component
    MovementComponent*      m_movementComponent;
    BoxCollisionComponent*  m_boxCollisionComponent;
    Vector2D                m_input;                // Current input movement that the PlayerController is sending

    
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
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
    virtual void Tick(float deltaTime);

/**
This methed updates the current speed value considering the input value
*/
    void UpdateSpeed(float deltaTime);

/**
* Sets a new value for the max movement speed
* @param speed: New movement speed
*/
    void SetMaxSpeed(float speed) { m_movementComponent->SetMaxSpeed(speed); }

/**
* Sets a new value for the curren movement speed
* @param speed: New current speed
*/
    void SetCurrentSpeed(float speed) { m_movementComponent->SetCurrentSpeed(speed); }

/**
* Sets a new value for the input
* @param speed: New input
*/
    void SetInput(Vector2D input);

    void SetInputX(float input) { SetInput(Vector2D(input, m_input.GetY())); }

    void SetInputY(float input) { SetInput(Vector2D(m_input.GetX(), input)); }
};