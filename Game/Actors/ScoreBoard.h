#pragma once
#include "../../Engine/Objects/TextBoxActor.h"
#include "../../Engine/Components/RectangleComponent.h"
#include "../Managers/MyGameManager.h"

class ScoreBoard : public TextBoxActor
{

public:
    ScoreBoard();
    virtual ~ScoreBoard();

protected:

    int             m_scoreL;               // Left player score
    int             m_scoreR;               // Right player score
    MyGameManager*  m_gameManager = NULL;   // Reference to the game manager
    
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
This method is to update the text of the score board with the current score
*/
    void UpdateScoreBoardText();

/**
This method is to update the position
*/
    void UpdateScoreBoardPosition();
};