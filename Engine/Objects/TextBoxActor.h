#pragma once
#include "Actor.h"
#include "../Components/TextBoxComponent.h"

class TextBoxActor : public Actor
{

public:
    TextBoxActor();
    virtual ~TextBoxActor();

protected:

    TextBoxComponent* m_textBoxComponent;    // The text box component
    
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