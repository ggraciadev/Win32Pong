#pragma once
#include "../Utils/Transform.h"
#include <vector>
#include <d2d1.h>

class ActorComponent;

class Actor
{

public:
    Actor();
    virtual ~Actor();

protected:
    Actor*                          m_parentActor = NULL;    // The Actor that is attached to
    Transform                       m_transform;             // The Transform of this Actor
    std::vector<ActorComponent*>    m_actorComponents;       // Components of this Actor
    ID2D1HwndRenderTarget*          m_renderTarget = NULL;   // The render target that will be used to render this Actor

/**
This event is called at the begining of the destructor method
 */
    virtual void EndPlay();

/**
 * To add an ActorComponent to the list of ActorComponents
 * @return a reference to the actorComponent added to the list
 */
    template< class T>
    T* AddActorComponent();

public:
/**
This event is called when the game starts or when the owner Actor is spawned
*/
    virtual void BeginPlay();
/**
This event is called when the game starts or when the owner Actor is spawned
*/
    virtual void Init();
    
/**
This event is for the logic of the component, the behaviour that has to be updated frame by frame if needed.
*/
    virtual void Tick(float deltaTime);

/**
This event is for the rendering of the Actor. This method automaticaly calls the SafeDraw of all its ActorComponents
*/
    void Draw();

/**
* This method returns a reference of the transform
* @return A reference of the transform of the Actor
*/
    Transform* GetTransform() { return &m_transform; }
    void SetTransform(const Transform& transform);

/**
* This method returns a reference of the render target
* @return A reference of the render target of the Actor
*/
    ID2D1HwndRenderTarget* GetRenderTarget() { return m_renderTarget; }
};


template< class T>
T* Actor::AddActorComponent() {
    T* tempComponent = new T();
    if ((ActorComponent*)(tempComponent) == NULL) {
        delete tempComponent;
        return NULL;
    }
    m_actorComponents.push_back(tempComponent);
    return tempComponent;
}