#pragma once
#include "../../Engine/Objects/EllipseActor.h"
#include "../../Engine/Components/BoxCollisionComponent.h"
#include "../../Engine/Components/MovementComponent.h"

class Ball : public EllipseActor
{

public:
    Ball();
    virtual ~Ball();

protected:
    BoxCollisionComponent*  m_boxCollisionComponent;
    MovementComponent*      m_movementComponent;
    
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

    virtual void OnActorBeginOverlap(Actor* other, CollisionComponent* otherComponent);
};