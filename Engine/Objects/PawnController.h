#pragma once
#include "Actor.h"

class Pawn;

class PawnController : public Actor
{

public:
    PawnController();
    virtual ~PawnController();

protected:
    Pawn* m_pawn;    // The pawn currently controlling
    
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
* This method is called to possess a Pawn. Won't do anything if it's NULL
* @param pawn: The new pawn to be possessed
*/
    void Possess(Pawn* pawn);

/**
This event is called just after a PawnController possess a Pawn
*/
    virtual void OnPossess() {}

/**
* This method is called to unpossess the current possessed Pawn. Won't do anything if it's NULL
*/
    void UnPossess();

/**
* Returns the current Pawn possessed
* @return The current Pawn possessed
*/
    Pawn* GetPawn() const;
};