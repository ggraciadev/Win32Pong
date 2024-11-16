#pragma once
#include "PawnController.h"

class AIController : public PawnController
{

public:
    AIController();
    virtual ~AIController();

protected:
    
/**
This event is called at the begining of the destructor method
*/
    virtual void EndPlay();

public:
/**
 This event is called when the game starts or when the owner PawnController is spawned
 */
    virtual void BeginPlay();

/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
    virtual void Tick(float deltaTime);

/**
This method should be override to give behaviour to the AIController
*/
    virtual void UpdateAIState(float deltaTime) {}

};