#pragma once
#include "../../Engine/Objects/PlayerController.h"

class Paddle;

class MyPlayerController : public PlayerController
{

protected:
    Paddle* m_paddle;

    virtual void RegisterInputs();

public:


    virtual void UpdateInput();

    virtual void OnPossess();

};