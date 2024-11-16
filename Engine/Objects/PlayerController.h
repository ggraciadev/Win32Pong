#pragma once
#include "PawnController.h"

class InputManager;

class PlayerController : public PawnController
{

public:
    PlayerController();
    virtual ~PlayerController();

protected:

    InputManager* m_inputManager;
    
/**
This event is called at the begining of the destructor method
*/
    virtual void EndPlay();

/**
 This method should be overrided to register all the inputs that this PlayerController uses
 */
    virtual void RegisterInputs() {}
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
 This method should be overrided to write the logic of what should be done with the input
 */
    virtual void UpdateInput() {}

/**
 To register a new key to be listened
 */
    void RegisterKey(BYTE key);

/**
 * This method is used to know if a key, previously registered, is being pressed
 * @param key: The key index
 * @return If the key is being pressed
 */
    bool GetKeyPressed(BYTE key);

/**
* This method is used to know if a key, previously registered, is being just released
* @param key: The key index
* @return If the key is being just released
*/
    bool GetKeyUp(BYTE key);

/**
* This method is used to know if a key, previously registered, is being just pressed
* @param key: The key index
* @return If the key is being just pressed
*/
    bool GetKeyDown(BYTE key);

};