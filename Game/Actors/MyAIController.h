#pragma once
#include "../../Engine/Objects/AIController.h"

class Paddle;
class Ball;
class MyGameManager;

class MyAIController : public AIController
{

protected:
    Paddle*         m_paddle;
    Ball*           m_ball;
    MyGameManager*  m_gameManger;

public:

    virtual void OnPossess();

    virtual void UpdateAIState(float deltaTime);

    void SetBall(Ball* ball);

};