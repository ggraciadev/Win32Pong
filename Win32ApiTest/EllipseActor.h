#pragma once
#include "Actor.h"
#include "EllipseComponent.h"

class EllipseActor : public Actor
{

public:
    EllipseActor();
    virtual ~EllipseActor();

protected:
    EllipseComponent* pEllipseComponent;
    
    virtual void EndPlay();

public:
    virtual void BeginPlay();
    virtual void Tick(float deltaTime);
};