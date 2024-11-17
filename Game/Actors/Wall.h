#pragma once
#include "../../Engine/Objects/RectangleActor.h"
#include "../../Engine/Components/RectangleComponent.h"
#include "../../Engine/Components/BoxCollisionComponent.h"

class Wall : public RectangleActor
{

public:
    Wall();
    virtual ~Wall();

protected:

    BoxCollisionComponent* m_boxCollisionComponent;
    
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