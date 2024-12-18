#pragma once
#include "Actor.h"
#include "../Components/RectangleComponent.h"

class RectangleActor : public Actor
{

public:
    RectangleActor();
    virtual ~RectangleActor();

protected:
    RectangleComponent* m_rectangleComponent;    // The rectangle component
    
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
};