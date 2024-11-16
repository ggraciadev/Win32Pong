#pragma once
#include "Actor.h"

class PawnController;

class Pawn : public Actor
{

public:
    Pawn();
    virtual ~Pawn();

protected:
    PawnController* m_pawnController;    // The Pawn Controller possessing this Pawn
    
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

    void SetPawnController(PawnController* m_pawnController);

/**
* Returns the PawnController that possess this Pawn
* @return the PawnController that possess this Pawn
*/
    PawnController* GetPawnController() const;

};