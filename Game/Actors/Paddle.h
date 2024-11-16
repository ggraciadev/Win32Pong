#pragma once
#include "../../Engine/Objects/Pawn.h"
#include "../../Engine/Components/RectangleComponent.h"

class Paddle : public Pawn
{

public:
    Paddle();
    virtual ~Paddle();

protected:
    RectangleComponent*     m_rectangleComponent;   // The rectangle component
    float                   m_maxSpeed;             // Max movement speed of the paddle
    float                   m_currentSpeed;         // Current movement speed of the paddle
    float                   m_input;                // Current input movement that the PlayerController is sending
    
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
    void SetMaxSpeed(float speed);

/**
* Sets a new value for the curren movement speed
* @param speed: New current speed
*/
    void SetCurrentSpeed(float speed);

/**
* Sets a new value for the input
* @param speed: New input
*/
    void SetInput(float input);
};