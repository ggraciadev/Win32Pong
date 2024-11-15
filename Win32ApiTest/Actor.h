#pragma once
#include "Transform.h"
#include <vector>
#include <d2d1.h>

class ActorComponent;

class Actor
{

public:
    Actor();
    virtual ~Actor();

protected:
    Transform                       pTransform;             // The Transform of this Actor
    std::vector<ActorComponent*>    pActorComponents;       // Components of this Actor
    ID2D1HwndRenderTarget*          pRenderTarget = NULL;   // The render target that will be used to render this Actor

/**
This event is called at the begining of the destructor method
 */
    virtual void EndPlay();

/**
 * To add an ActorComponent to the list of ActorComponents
 * @param actorComponent:  a reference to the actorComponent to add to the list
 */
    virtual void AddActorComponent(ActorComponent* actorComponent);

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
    virtual void BeginPlay();
/**
This event is called when the game starts or when the owner Actor is spawned
*/
    virtual void Init(ID2D1HwndRenderTarget* renderTarget, const Transform& transform = Transform(Vector2D(0, 0), 0, Vector2D(1, 1)));
    
/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
    virtual void Tick(float deltaTime);

/**
This event is for the rendering of the Actor. This method automaticaly calls the SafeDraw of all its ActorComponents
*/
    virtual void Draw();

/**
* This method returns a reference of the transform
* @return A reference of the transform of the Actor
*/
    Transform* GetTransform() { return &pTransform; }
    void SetTransform(const Transform& transform);

/**
* This method returns a reference of the render target
* @return A reference of the render target of the Actor
*/
    ID2D1HwndRenderTarget* GetRenderTarget() { return pRenderTarget; }
};